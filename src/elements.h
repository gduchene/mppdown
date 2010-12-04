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
#ifndef _MPPDOWN_ELEMENTS
#define _MPPDOWN_ELEMENTS
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>

typedef std::wstring::iterator iiterator;
typedef std::back_insert_iterator<std::wstring> oiterator;

struct stext_t;
typedef boost::variant<boost::recursive_wrapper<stext_t>, std::wstring> text_t;

enum stattribute_t {
    EMPH,
    SEMPH,
    VSEMPH,
    ALT,
    SALT
};

struct stext_t {
    stattribute_t attribute;
    std::vector<text_t> value;
};

typedef std::vector<text_t> document_t;

BOOST_FUSION_ADAPT_STRUCT (stext_t,
                           (stattribute_t, attribute)
                           (std::vector<text_t>, value)
                          )
#endif
