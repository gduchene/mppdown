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
#ifndef _MPPDOWN_LATEX_PARAGRAPH_G
#define _MPPDOWN_LATEX_PARAGRAPH_G
#include <boost/spirit/include/karma.hpp>
#include "../../elements.h"
#include "heading_g.h"
#include "line_g.h"

namespace ka = boost::spirit::karma;

namespace latex {
struct paragraph_g : ka::grammar<oiterator, paragraph_t()> {
    ka::rule<oiterator, paragraph_t()> paragraph_;
    heading_g heading_;
    line_g line_;

    paragraph_g();
};
}
#endif
