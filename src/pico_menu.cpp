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

#include "pico_menu.hpp"
#include "pico_display.hpp"
#include "menu_action.hpp"

namespace twobytes {

    int aPressedRecently = 0;
    int xPressedRecently = 0;
    int bPressedRecently = 0;
    int yPressedRecently = 0;
    int debounce = 10;

    PicoMenu::PicoMenu(pimoroni::PicoDisplay display) : PicoMenu(pimoroni::PicoDisplay::PORTRAIT_WIDTH,pimoroni::PicoDisplay::PORTRAIT_HEIGHT, display) {}

    PicoMenu::PicoMenu(int width, int height, pimoroni::PicoDisplay display) : width_(width), height_(height), display_(display) {
        display_.set_pen(0,0,0);
        display_.clear();
    }

    void PicoMenu::SetMenu(MenuList* item) {
        this->main_menu_.push(item);
    }

    void PicoMenu::Update() {
        this->CheckInputs();
        this->Draw();
    }

    void PicoMenu::Previous() {

        if(aPressedRecently == 0) {
            aPressedRecently = debounce;
            main_menu_.top()->Previous();
        }

        if(aPressedRecently > 0) {
            aPressedRecently--;
        }

    }

    void PicoMenu::Next() {

        if(xPressedRecently == 0) {
            xPressedRecently = debounce;
            main_menu_.top()->Next();
        }

        if(xPressedRecently > 0) {
            xPressedRecently--;
        }
    }

    void PicoMenu::Select() {

        if(yPressedRecently == 0) {
            yPressedRecently = debounce;

            MenuBase* cr = main_menu_.top()->GetHighlightedRow();
            if ( cr != NULL ) {
                this->main_menu_.push(cr);
                cr->Execute();
            }
        
        }

        if(yPressedRecently > 0) {
            yPressedRecently--;
        }

    }

    void PicoMenu::Back() {

        if(bPressedRecently == 0) {
            bPressedRecently = debounce;

            if (this->main_menu_.size() > 1) {
                this->main_menu_.pop();
            }
        }

        if(bPressedRecently > 0) {
            bPressedRecently--;
        }
    }

    void PicoMenu::Draw() {
        this->main_menu_.top()->Draw(this->display_);
    }

    void PicoMenu::CheckInputs() {
        if(display_.is_pressed(up_button_)) {
            this->Previous();
        }
        
        if(display_.is_pressed(down_button_)) {
            this->Next();
        }

        if(display_.is_pressed(back_button_)) {
            this->Back();
        }

        if(display_.is_pressed(select_button_)) {
            this->Select();
        }
    }
}
