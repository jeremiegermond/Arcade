project(arcade)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_CXX_FLAGS "-std=c++17 -g3 -Wall -O0")

include_directories(include)

add_executable(arcade core/src/Arcade.cpp core/src/Arcade.hpp)
add_subdirectory(core)

add_library(arcade_sdl2 SHARED)

set_target_properties(
        arcade_sdl2
        PROPERTIES
        PREFIX ""
)

add_library(arcade_ncurses SHARED)

set_target_properties(
        arcade_ncurses
        PROPERTIES
        PREFIX ""
)

add_library(arcade_sfml SHARED)

set_target_properties(
        arcade_sfml
        PROPERTIES
        PREFIX ""
)

add_subdirectory(game_libraries)
add_library(arcade_pacman SHARED)
add_library(arcade_nibbler SHARED)
add_library(arcade_menu SHARED)

set_target_properties(
        arcade_pacman
        PROPERTIES
        PREFIX ""
)

set_target_properties(
        arcade_nibbler
        PROPERTIES
        PREFIX ""
)

set_target_properties(
        arcade_menu
        PROPERTIES
        PREFIX ""
)

add_subdirectory(games)
add_custom_command(
        TARGET arcade
        POST_BUILD COMMAND ${CMAKE_COMMAND}
        -E create_symlink ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
)
add_custom_command(
        TARGET arcade
        POST_BUILD COMMAND ${CMAKE_COMMAND}
        -E create_symlink ${CMAKE_BINARY_DIR}/lib ${CMAKE_SOURCE_DIR}/lib
)
add_custom_command(
        TARGET arcade
        POST_BUILD COMMAND ${CMAKE_COMMAND}
        -E create_symlink ${CMAKE_BINARY_DIR}/arcade ${CMAKE_SOURCE_DIR}/arcade
)