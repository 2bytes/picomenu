cmake_minimum_required(VERSION 3.16)

include(../twobytes_menu.cmake)

project(Menu C CXX ASM)

add_executable(Menu menu_example.cpp)

pico_add_extra_outputs(Menu)
target_link_libraries(Menu pico_stdlib twobytes_menu)
