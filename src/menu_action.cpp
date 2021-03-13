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

#include "menu_action.hpp"

namespace twobytes {
    MenuAction::MenuAction() : action_(NULL) {}

    void MenuAction::Draw(pimoroni::PicoDisplay display) {
        display.set_pen(255,255,255);
        display.clear();
        display.set_pen(255,0,0);
        display.text(
            this->description_,
            pimoroni::Point(pimoroni::PicoDisplay::PORTRAIT_WIDTH/5, 
            pimoroni::PicoDisplay::PORTRAIT_HEIGHT/5), 
            4*(pimoroni::PicoDisplay::PORTRAIT_WIDTH/5)
        );
        display.update();
    }

    void MenuAction::SetFunction(menu_action action) {
        this->action_ = action;
    }

    void MenuAction::Execute() {
        if(this->action_ != NULL) {
            this->action_();
        }
    }

    void MenuAction::SetDescription(std::string description) {
        this->description_ = description;
    }
}
