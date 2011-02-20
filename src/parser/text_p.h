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
#ifndef _MPPDOWN_TEXT_P
#define _MPPDOWN_TEXT_P
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_standard_wide.hpp>
#include <string>
#include "../elements.h"

namespace qi = boost::spirit::qi;
namespace ph = boost::phoenix;

struct text_p : qi::grammar<iiterator, text_t(std::wstring)> {
    qi::rule<iiterator, text_t(std::wstring)> text_;
    qi::rule<iiterator, stext_t(std::wstring)> stext_;
    qi::rule<iiterator, pstext_t(std::wstring)> pstext_;
    qi::rule<iiterator, stattribute_t()> atom_;
    qi::rule<iiterator, std::wstring(std::wstring)> ptext_;
    qi::rule<iiterator, wchar_t()> echar_;
    qi::rule<iiterator, wchar_t(std::wstring)> rchar_;

    text_p();
};
#endif
