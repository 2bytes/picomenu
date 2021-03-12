cmake_minimum_required(VERSION 3.16)

include(pico_sdk_import.cmake)

project(Menu C CXX ASM)

pico_sdk_init()

add_executable(Menu menu_example.cpp)
add_subdirectory(../ build)

pico_add_extra_outputs(Menu)
target_link_libraries(Menu pico_stdlib twobytes_menu)
