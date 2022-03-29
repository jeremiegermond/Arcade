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

add_subdirectory(game_libraries)
add_library(arcade_pacman SHARED)

set_target_properties(
        arcade_pacman
        PROPERTIES
        PREFIX ""
)

add_subdirectory(games)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})