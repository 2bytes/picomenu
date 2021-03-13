cmake_minimum_required(VERSION 3.16)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

include(pico_sdk_import.cmake)

project(pico_menu)

pico_sdk_init()

add_library(pico_menu INTERFACE)

add_subdirectory($ENV{PIM_SDK_PATH}/drivers/st7789 st7789)
add_subdirectory($ENV{PIM_SDK_PATH}/libraries/pico_graphics pico_graphics)
add_subdirectory($ENV{PIM_SDK_PATH}/libraries/pico_display pico_display)

target_sources(pico_menu INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/pico_menu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/menu_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/menu_list.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/menu_action.cpp
)

target_include_directories(pico_menu INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(pico_menu INTERFACE pico_stdlib hardware_spi st7789 pico_display pico_graphics)

# Create doxygen make target to make API documentation.
# Run "make doxygen" in the build directory after running cmake to make the documentation.
# Choose which type of documentation you want below:
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN NO)

doxygen_add_docs(
    doxygen
    ${PROJECT_SOURCE_DIR}
    COMMENT "Generate API documentation"
)
