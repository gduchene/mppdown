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
#ifndef _MPPDOWN_LINE_P
#define _MPPDOWN_LINE_P
#include <boost/spirit/include/qi.hpp>
#include "../elements.h"
#include "text_p.h"

namespace qi = boost::spirit::qi;
namespace ph = boost::phoenix;

struct line_p : qi::grammar<iiterator, line_t()> {
    qi::rule<iiterator, line_t()> line_;
    text_p text_;

    line_p();
};
#endif
