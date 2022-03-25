/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/
#include <iostream>
#include "ncurses_game_library.hpp"
#include <memory>
#include <iostream>
#include <thread>

namespace arcade {

NCursesGraphicLibrary::NCursesGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters) {}

void NCursesGraphicLibrary::closeWindow() {
    if (this->window) {
        clear();
        endwin();
    }
}

void NCursesGraphicLibrary::createWindow() {
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
        throw Exception("Cannot create _window.");
    }
    box(this->window, 0, 0);
    wrefresh(this->window);
}

std::string NCursesGraphicLibrary::getName() const {
    return "nCurses";
}

void NCursesGraphicLibrary::loadObjects(std::vector<object> GameObjects) {
    for (auto &object : GameObjects) {
        switch (object.type) {
            case Type::TEXT:
                initTextObjects(object);
                break;
            default:
                break;
        }
    }
}

void NCursesGraphicLibrary::loop() {
    renderTextObjects();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void NCursesGraphicLibrary::initTextObjects(object &gameObject) {
    textObjects.push_back(gameObject);
}

void NCursesGraphicLibrary::renderTextObjects() {
    for (auto &object: textObjects) {
        mvwaddstr(window, object.posY, object.posX, &object.text[0]);
        wrefresh(window);
    }
}

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new NCursesGraphicLibrary(parameters);
}

}