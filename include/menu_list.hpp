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
#include "menu_base.hpp"
#include "pico_display.hpp"

namespace twobytes {

    /**
     * @brief MenuList implements a menu system for Pico Menu. It can hold up to 11 rows,
     * and supports each row being a subclass which implements MenuBase.
     * 
     */
    class MenuList : public MenuBase {
        private:
            static const uint8_t kMaxRows = 11;
            uint8_t highlighted_row_ = 0;
            std::vector < MenuBase* > rows_;
            uint16_t title_background_pen_ = create_pen(255,0,0);
            uint16_t title_foreground_pen_ = create_pen(255,255,255);
            uint8_t rowHeight = 20;
        public:
            /**
             * @brief Construct a new MenuList object
             * 
             */
            MenuList();
            /**
             * @brief Add a new row of type MenuBase (MenuMenu, MenuAction)
             * 
             * @param item the menu item of type MenuBase
             */
            void AddRow(MenuBase* item);
            /**
             * @brief Get the Current Row object
             * 
             * @return MenuBase* for the highlighted row
             */
            MenuBase* GetHighlightedRow();
            /**
             * @brief Move to previous row on the screen
             * 
             */
            void Previous();
            /**
             * @brief Move to next row on the screen
             * 
             */
            void Next();
            /**
             * @brief The number of rows in the current menu
             * 
             * @return int number of rows
             */
            int Size();
            /**
             * @brief Currently highlighted row index
             * 
             * @return int index of the highlighted row
             */
            int HighlightedRowIndex();
            /**
             * @brief Draw function to draw this menu.
             * This is called automatically by the parent menu draw call.
             * 
             * @param display Pimoroni PicoDisplay for displaying to and accessing buttons on.
             */
            void Draw(pimoroni::PicoDisplay display);
            /**
             * @brief Set the Title Background colour
             * 
             * @param pen is the pimoroni::Pen to set
             * as the background colour for the title.
             */
            void SetTitleBackground(pimoroni::Pen pen);
            /**
             * @brief Set the Title Foreground colour
             * 
             * @param pen is the pimoroni::Pen to set
             * as the foreground (text) colour for the title.
             */
            void SetTitleForeground(pimoroni::Pen pen);
        private:
            void DrawTitle(const pimoroni::PicoDisplay display);
            void DrawRows(const pimoroni::PicoDisplay display);
    };
}
