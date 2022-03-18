/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/

#include "ncurses_game_library.hpp"

namespace arcade {

std::string NCursesGameLibrary::getName() const {
    return "nCurses";
}

extern "C" GameLibrary *create() {
    return new NCursesGameLibrary();
}

}