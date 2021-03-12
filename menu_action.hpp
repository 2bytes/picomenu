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

#include <string>
#include "menu_base.hpp"
#include "pico_display.hpp"

namespace twobytes {

    /**
     * @brief Typedef for the action function to call when selected.
     * 
     */
    typedef void(*menu_action)(void);

    /**
     * @brief MenuList implements a menu action for Pico Menu.
     * It accepts a pointer to a function to execute when selected.
     * 
     */
    class MenuAction : public MenuBase {
        public:
            /**
             * @brief provide the function for the action to call
             *  when selected.
             */
            menu_action action_;
        private:
            std::string description_;
        public:
            /**
             * @brief Construct a new Menu Action
             * 
             */
            MenuAction();
            /**
             * @brief Set the Description text for the action page.
             *
             * @param description string to be displayed on the action page.
             */
            void SetDescription(std::string description);
            /**
             * @brief Draw function for the action page.
             *
             * @param display is the Pimoroni PicoDisplay instance
             */
            void Draw(pimoroni::PicoDisplay display);
            /**
             * @brief Set the Function to call when this action is selected
             *
             * @param action 
             */
            void SetFunction(menu_action action);
            /**
             * @brief Execute the provided function on action selection (button press)
             *
             */
            void Execute();
    };
}
