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

#pragma once

#include <string>
#include <stack>
#include "menu_list.hpp"
#include "pico_display.hpp"

namespace twobytes {

/**
 * @brief Menu provides the pico display menu system
 * 
 */
class PicoMenu {
    private:
        uint8_t width_;
        uint8_t height_;
        pimoroni::PicoDisplay display_;
        std::stack< MenuBase* > main_menu_;
        uint8_t up_button_ = pimoroni::PicoDisplay::A;
        uint8_t down_button_ = pimoroni::PicoDisplay::X;
        uint8_t back_button_ = pimoroni::PicoDisplay::B;
        uint8_t select_button_ = pimoroni::PicoDisplay::Y;
    public:
        /**
         * @brief Construct a new Menu object
         * 
         * @param display Pimoroni PicoDisplay object for displaying to and accessing buttons on.
         */
        PicoMenu(pimoroni::PicoDisplay display);
        /**
         * @brief Construct a new Menu object
         * 
         * @param width Width if not using the default, e.g. for Portrait
         * @param height Height if not using the default, e.g. for Portrait
         * @param display Pimoroni PicoDisplay object for displaying and accessing buttons on
         */
        PicoMenu(int width, int height, pimoroni::PicoDisplay display);
        /**
         * @brief Set the top level menu object
         * 
         * @param menu Top level menu item to be displayed
         */
        void SetMenu(MenuList* menu);
        /**
         * @brief Update takes care of reading buttons and updating the dsplay. 
         * It should be called in a loop.
         * 
         */
        void Update();
    private:
        void CheckInputs();
        void Draw();
        void Previous();
        void Next();
        void Select();
        void Back();
};

}
