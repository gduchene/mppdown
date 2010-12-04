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
#include "text_p.h"

text_p::text_p() : text_p::base_type(text_) {
    using namespace qi;
    using namespace ph;
    using qi::standard_wide::char_;

    text_ = stext_(_r1) | ptext_(_r1);

    stext_ = lit("***") >> attr(VSEMPH) >> +text_(val(L"*'`")) >> "***"
           | lit("**") >> attr(SEMPH) >> +text_(val(L"*'`")) >> "**"
           | lit('*') >> attr(EMPH) >> +text_(val(L"*'`")) >> '*'
           | lit("''") >> attr(SALT) >> +text_(val(L"*'`"))>> "''"
           | lit('\'') >> attr(ALT) >> +text_(val(L"*'`")) >> '\''
           | lit('`') >> attr(CODE) >> +ptext_(val(L"`")) >> '`';

    ptext_ = +(echar_ | rchar_(_r1));
    echar_ = lit('\\') >> char_;
    rchar_ = char_ - char_(_r1);
}
