/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/
#include <iostream>
#include "ncurses_game_library.hpp"

namespace arcade {

NCursesGameLibrary::NCursesGameLibrary(const Parameters &parameters) : GameLibrary(parameters) {}

NCursesGameLibrary::~NCursesGameLibrary() {
    if (this->window) {
        clear();
        endwin();
    }
}

void NCursesGameLibrary::createWindow() {
    if (!initscr()) {
        throw Exception("Cannot init nCurses.");
    }
    this->window = newwin(
        this->parameters.tilemap.height, 
        this->parameters.tilemap.width,
        0,
        0
    );

    if (!this->window) {
        throw Exception("Cannot create window.");
    }
    box(this->window, 0, 0);
    wrefresh(this->window);
}

std::string NCursesGameLibrary::getName() const {
    return "nCurses";
}

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters) {
    return new NCursesGameLibrary(parameters);
}

}