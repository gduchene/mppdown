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
#ifndef _MPPDOWN_ELEMENTS
#define _MPPDOWN_ELEMENTS
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>

typedef std::wstring::iterator iiterator;
typedef std::back_insert_iterator<std::wstring> oiterator;

enum stattribute_t {
    EMPH,
    SEMPH,
    VSEMPH,
    ALT,
    SALT,
    CODE,
    MATH,
    SUPER,
    QUOTE,
    SUB,
    LINK,
    NBSP,
    NEWLINE
};

struct stext_t;
struct pstext_t;
typedef boost::variant<boost::recursive_wrapper<stext_t>,
                       boost::recursive_wrapper<pstext_t>,
                       stattribute_t,
                       std::wstring> text_t;

struct stext_t {
    stattribute_t attribute;
    std::vector<text_t> value;
};

struct pstext_t {
    stattribute_t attribute;
    std::vector<text_t> value;
    std::wstring parameter;
};

typedef std::vector<text_t> line_t;

enum hattribute_t {
    HEADING_1,
    HEADING_2,
    HEADING_3,
    HEADING_4,
    HEADING_5
};

struct heading_t {
    hattribute_t level;
    line_t contents;
};

typedef boost::variant<heading_t,
                       std::vector<line_t> > paragraph_t;

typedef std::vector<paragraph_t> document_t;

BOOST_FUSION_ADAPT_STRUCT (stext_t,
                           (stattribute_t, attribute)
                           (std::vector<text_t>, value)
                          )

BOOST_FUSION_ADAPT_STRUCT (pstext_t,
                           (stattribute_t, attribute)
                           (std::vector<text_t>, value)
                           (std::wstring, parameter)
                          )

BOOST_FUSION_ADAPT_STRUCT (heading_t,
                           (hattribute_t, level)
                           (line_t, contents)
                          )
#endif
