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
#include "menu_action.hpp"
#include "pico_display.hpp"

using namespace pimoroni;

uint16_t buffer[PicoDisplay::PORTRAIT_WIDTH*PicoDisplay::PORTRAIT_HEIGHT];
PicoDisplay display(buffer, PicoDisplay::PORTRAIT_WIDTH, PicoDisplay::PORTRAIT_HEIGHT);
twobytes::PicoMenu menu(PicoDisplay::PORTRAIT_WIDTH, PicoDisplay::PORTRAIT_HEIGHT, display);

twobytes::MenuAction action1{};

int aNumber = 0;

int r = 0;
int g = 0;
int b = 0;

void ledRed() {r=100,g=0,b=0;}
void ledGreen() {r=0,g=100,b=0;}
void ledBlue() {r=0,g=0,b=100;}
void ledOff() {r=0,g=0,b=0;}

void action1Func() {
    aNumber++;
    action1.SetDescription("Action1 pressed " + std::to_string(aNumber) + " times");
}

int brightness = 50;

twobytes::MenuAction actionUp{};
twobytes::MenuAction actionDown{};

void brightnessUp() {
    if (brightness <= 100) {
        actionUp.SetDescription("Brightness increased by 10%");
        brightness += 10;
        display.set_backlight((255/100)*brightness);
    } else {
        actionUp.SetDescription("Maximum Brightness");
    }
}

void brightnessDown() {
    if (brightness >= 30) {
        actionDown.SetDescription("Brightness decreased by 10%");
        brightness -= 10;
        display.set_backlight((255/100)*brightness);
    } else {
        actionDown.SetDescription("Minimum Brightness");
    }
}


int main() {

    display.init();
    display.set_backlight((255/100)*50); // Set backlight to 50%

    // Create the main menu
    twobytes::MenuList topMenu{};
    topMenu.SetTitle("Pico Menu");
    topMenu.SetTitleBackground(twobytes::MenuBase::create_pen(140,0,200)); // #600080
    topMenu.SetTitleForeground(twobytes::MenuBase::create_pen(255,255,255)); // #FFFFFF

    topMenu.SetBackground(twobytes::MenuBase::create_pen(200,0,80)); // #600080
    topMenu.SetForeground(twobytes::MenuBase::create_pen(255,255,255)); // #FFFFFF

    // Add a submenu
    twobytes::MenuList ledMenu{};
    ledMenu.SetTitle("LED Colour");

    twobytes::MenuAction ledRedAction{};
    ledRedAction.SetTitle("Red");
    ledRedAction.SetDescription("LED set to Red");
    ledRedAction.SetFunction(ledRed);

    twobytes::MenuAction ledGreenAction{};
    ledGreenAction.SetTitle("Green");
    ledGreenAction.SetDescription("LED set to Green");
    ledGreenAction.SetFunction(ledGreen);

    twobytes::MenuAction ledBlueAction{};
    ledBlueAction.SetTitle("Blue");
    ledBlueAction.SetDescription("LED set to Blue");
    ledBlueAction.SetFunction(ledBlue);

    twobytes::MenuAction ledOffAction{};
    ledOffAction.SetTitle("Off");
    ledOffAction.SetDescription("LED set to Off");
    ledOffAction.SetFunction(ledOff);

    twobytes::MenuList brightnessMenu{};
    brightnessMenu.SetTitle("Brightness");
    brightnessMenu.SetBackground(twobytes::MenuList::create_pen(0,0,0));
    brightnessMenu.SetForeground(twobytes::MenuList::create_pen(255,255,255));

    actionUp.SetTitle("+ 10%");
    actionUp.SetFunction(brightnessUp);
    actionUp.SetDescription("Brightness increased by 10%");

    actionDown.SetTitle("- 10%");
    actionDown.SetFunction(brightnessDown);
    actionDown.SetDescription("Brightness decreased by 10%");
    brightnessMenu.AddRow(&actionUp);
    brightnessMenu.AddRow(&actionDown);
    topMenu.AddRow(&brightnessMenu);

    ledMenu.AddRow(&ledRedAction);
    ledMenu.AddRow(&ledGreenAction);
    ledMenu.AddRow(&ledBlueAction);
    ledMenu.AddRow(&ledOffAction);
    topMenu.AddRow(&ledMenu);

    // Set values of a globally defined action and add it to the menu
    action1.SetTitle("action1");
    action1.SetFunction(action1Func);
    topMenu.AddRow(&action1);

    menu.SetMenu(&topMenu);

    // Once we've created all of our menus and actions and added them, we only need to call menu.update() in a loop.
    while (true) {
        menu.Update();
        // The pimoroni implementation for the LED requires that it be set on every loop, it's not a toggle,
        // so we'll update it here too.
        display.set_led(r,g,b);
    }

}