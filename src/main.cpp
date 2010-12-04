/*
Copyright (c) 2010, Grégoire Duchêne <gduchene@fastmail.net>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/qi.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "elements.h"
#include "generators/latex_g.h"
#include "parser/document_p.h"

namespace ka = boost::spirit::karma;
namespace qi = boost::spirit::qi;

int main(int argc, char **argv) {
    using namespace std;

    if (argc != 2)
        return 1;

    wifstream ifile(argv[1]);
    
    if (ifile.fail()) {
        cerr << "Error while reading the file." << endl;
        return 1;
    }

    wchar_t buffer;
    wstring input;

    while (ifile.get(buffer))
        input.push_back(buffer);

    ifile.close();

    document_p parser;
    iiterator begin = input.begin();
    iiterator end = input.end();
    document_t ast;

    if (!qi::parse(begin, end, parser, ast) || begin != end) {
        cerr << "Error while parsing the file." << endl;
        return 1;
    }

    latex_g generator;
    wstring output;
    oiterator sink(output);

    if (!ka::generate(sink, generator, ast)) {
        cerr << "Error while generating the output." << endl;
        return 1;
    }

    wcout << output << flush;
    return 0;
}
