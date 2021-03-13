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
#include <vector>
#include "pico_display.hpp"

namespace twobytes {

    /**
     * @brief Base class for menu items.
     * Subclass this base to implement drawing, navigation etc.
     *  See MenuList and MenuAction for example subclasses.
     */
    class MenuBase {

        public:
            /**
             * @brief Create a pen (uint16_t).
             *  This is a static implementation compatible with the PicoDisplay createPen.
             * 
             * @param r red colour integer 0 to 255.
             * @param g green colour integer 0 to 255.
             * @param b  blue colour integer 0 to 255.
             * @return constexpr uint16_t is compatible with pimoroni::Pen
             */
            static constexpr uint16_t create_pen(uint8_t r, uint8_t g, uint8_t b) {
                uint16_t p = ((r & 0b11111000) << 8) |
                             ((g & 0b11111100) << 3) |
                             ((b & 0b11111000) >> 3);

                return __builtin_bswap16(p);
            };
        private:
            uint16_t bg_pen = create_pen(255,255,255);
            uint16_t fg_pen = create_pen(0,0,0);
            std::string title_;
        public:
            /**
             * @brief Construct a new Menu Base.
             * Subclass this in order to create custom menu or action or other types.
             * 
             */
            MenuBase();
            /**
             * @brief Destroy the Menu Base object
             *
             */
            virtual ~MenuBase() {};
            /**
             * @brief draw function to implement in subclasses.
             * Will be called by parent menu to draw this type.
             *
             * @param display is the Pimoroni PicoDisplay to be displayed to and buttons accessed on.
             */
            virtual void Draw(const pimoroni::PicoDisplay display) = 0;
            /**
             * @brief Previous moves the cursor to the previous item in the list, highlighting it
             *
             */
            virtual void Previous() {};
            /**
             * @brief Next moves the cursor to the next item in the list, highlighting it
             *
             */
            virtual void Next() {};
            /**
             * @brief Get the Highlighted Row to interact with it
             *
             * @return MenuBase* subclass is returned.
             */
            virtual MenuBase* GetHighlightedRow() { return NULL; };
            /**
             * @brief Execute the function supplied to this action, if there is one.
             *
             */
            virtual void Execute() {};
            /**
             * @brief Set the Title of this type, used for displaying in the title
             * of a page, or as the row text in a menu.
             *
             * @param title String title to display as row text or page title.
             */
            void SetTitle(std::string title);
            /**
             * @brief Get the Title string for drawing.
             *
             * @return std::string 
             */
            std::string GetTitle();
            /**
             * @brief Set the Background colour for non-title parts of the screen.
             *
             * @param pen is the pimoroni::Pen colour to set as the background.
             */
            void SetBackground(pimoroni::Pen pen);
            /**
             * @brief Set the Foreground (text) colour for non-title parts of the screen
             *
             * @param pen is the pimoroni::Pen colour for non-title text.
             */
            void SetForeground(pimoroni::Pen pen);
            /**
             * @brief Get the Background colour
             *
             * @return pimoroni::Pen background colour for the page.
             */
            pimoroni::Pen GetBackground();
            /**
             * @brief Get the Foreground (text) colour
             *
             * @return pimoroni::Pen text colour for the page.
             */
            pimoroni::Pen GetForeground();
    };
}
