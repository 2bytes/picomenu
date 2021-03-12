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

#include "menu_list.hpp"

namespace twobytes {

    MenuList::MenuList() : rows_(0,0) {}

    void MenuList::SetTitleBackground(pimoroni::Pen pen) {
        this->title_background_pen_ = pen;
    }

    void MenuList::SetTitleForeground(pimoroni::Pen pen) {
        this->title_foreground_pen_ = pen;
    }

    void MenuList::AddRow(MenuBase* item) {
        rows_.push_back(item);
    }

    int MenuList::Size() {
        return rows_.size();
    }

    MenuBase* MenuList::GetHighlightedRow() {
        return rows_.at(highlighted_row_);
    }

    void MenuList::Previous() {
        if (highlighted_row_ == 0){
            return;
        }

        --highlighted_row_;
    }

    void MenuList::Next() {
        if (highlighted_row_ == rows_.size()-1){
            return;
        }

        ++highlighted_row_;
    }

    int MenuList::HighlightedRowIndex() {
        return highlighted_row_;
    }
    

    void MenuList::DrawTitle(pimoroni::PicoDisplay display) {

        if (this->GetTitle().length() == 0) {
            return;
        }

        pimoroni::Rect title_rect(0,0, pimoroni::PicoDisplay::PORTRAIT_WIDTH, 20);

        display.set_pen(title_background_pen_);
        display.rectangle(title_rect);
        display.set_pen(title_foreground_pen_);
        display.text(GetTitle(), pimoroni::Point(20, 3), pimoroni::PicoDisplay::PORTRAIT_WIDTH);
    }

    void MenuList::DrawRows(pimoroni::PicoDisplay display){

        int startY = rowHeight;
        int rs = rows_.size();
        
        if (this->GetTitle().length() == 0) {
            startY = 0;
        }

        for(int i = 0; i < rows_.size(); i++) {
            MenuBase* mi = rows_.at(i);
            if (i == highlighted_row_) {
                display.set_pen(255,165,0);
            } else {
                display.set_pen(this->GetBackground());
            }
            pimoroni::Rect bg_rect(0, startY, pimoroni::PicoDisplay::PORTRAIT_WIDTH, 20);
            display.rectangle(bg_rect);
            display.set_pen(title_background_pen_);
            display.line(pimoroni::Point(0, startY+rowHeight-1), pimoroni::Point(pimoroni::PicoDisplay::PORTRAIT_WIDTH, startY+rowHeight-1));
            display.set_pen(this->GetForeground());
            display.text(mi->GetTitle(), pimoroni::Point(2, startY+4), pimoroni::PicoDisplay::PORTRAIT_WIDTH);
            startY+=rowHeight;
        }
    }

    void MenuList::Draw(pimoroni::PicoDisplay display) {
        display.set_pen(this->GetBackground());
        display.clear();
        DrawTitle(display);
        DrawRows(display);
        display.update();
    }
}
