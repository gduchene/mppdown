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
#include "text_g.h"

latex::text_g::text_g() : text_g::base_type(text_) {
    using namespace ka;
    using ka::standard_wide::char_;

    text_ = stext_ | ptext_;
    
    stext_ = &uint_(EMPH) << L"\\emph{" << +text_ << '}'
           | &uint_(SEMPH) << L"\\textit{\\emph{" << +text_ << L"}}"
           | &uint_(VSEMPH) << L"\\texttt{\\textit{\\emph{" << +text_ << L"}}}"
           | &uint_(ALT) << L"\\textit{" << +text_ << '}'
           | &uint_(SALT) << L"\\textit{\\textbf{" << +text_ << L"}}"
           | &uint_(CODE) << L"\\texttt{" << +text_ << '}'
           | &uint_(MATH) << L"$" << +text_ << '$';

    ptext_ = +char_;
}
