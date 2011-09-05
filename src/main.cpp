/*
Copyright (c) 2010, 2011, Grégoire Duchêne <gduchene@fastmail.net>

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
#include <boost/program_options.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/qi.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "elements.h"
#include "generators/latex/document_g.h"
#include "parser/document_p.h"

namespace ka = boost::spirit::karma;
namespace po = boost::program_options;
namespace qi = boost::spirit::qi;

int main(int argc, char** argv) {
    using namespace std;

    po::options_description general("Allowed options");
    po::positional_options_description pgeneral;
    po::variables_map variables;

    general.add_options()
        ("help,h", "produce this message")
        ("input,i", po::value<string>(), "set the input file")
        ("output,o", po::value<string>(), "set the output file");

    pgeneral.add("input", -1);

    po::store(po::command_line_parser(argc,argv).
              options(general).positional(pgeneral).run(), variables);

    po::notify(variables);

    if (variables.count("help")) {
        cout << general << endl;
        return 0;
    }

    if (!variables.count("input")) {
        cerr << "mppdown: you must specify an input file" << endl;
        return 1;
    }

    wifstream ifile(variables["input"].as<string>().c_str());
 
    if (ifile.fail()) {
        cerr << "mppdown: error while reading the file" << endl;
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

    try {
        if (!qi::parse(begin, end, parser, ast) || begin != end) {
            cerr << "mppdown: error while parsing the file" << endl;
            return 1;
        }
    } catch (...) { // VERY UGLY
        cerr << "mppdown: error while parsing the file" << endl;
        return 1;
    }

    latex::document_g generator;
    wstring output;
    oiterator sink(output);

    if (!ka::generate(sink, generator, ast)) {
        cerr << "mppdown: error while generating the output" << endl;
        return 1;
    }

    if (!variables.count("output"))
        wcout << output << flush;
    else {
        wofstream ofile(variables["output"].as<string>().c_str());

        if (ofile.fail()) {
            cerr << "mppdown: error while opening the output file" << endl;
            return 1;
        }

        ofile << output;
        ofile.close();
    }

    return 0;
}
