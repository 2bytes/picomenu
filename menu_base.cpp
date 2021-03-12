// MIT License

// Copyright (c) 2021 Hamid Elaosta

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "menu_base.hpp"

#include <string>

namespace twobytes {

    MenuBase::MenuBase() {}

    void MenuBase::SetTitle(std::string title) {
        this->title_ = title;
    }

    std::string MenuBase::GetTitle() {
        return this->title_;
    }

    void MenuBase::SetBackground(pimoroni::Pen pen) {
        this->bg_pen = pen;
    }

    pimoroni::Pen MenuBase::GetBackground() {
        return this->bg_pen;
    }

    void MenuBase::SetForeground(pimoroni::Pen pen) {
        this->fg_pen = pen;
    }

    pimoroni::Pen MenuBase::GetForeground() {
        return this->fg_pen;
    }

    void draw() {}

}
