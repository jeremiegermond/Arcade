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

NCursesGraphicLibrary::~NCursesGraphicLibrary() {
}

void NCursesGraphicLibrary::closeWindow()
{
    if (this->_window) {
        clear();
        endwin();
    }
}

void NCursesGraphicLibrary::createWindow() {
    if (!initscr()) {
        throw Exception("Cannot init nCurses.");
    }
    this->_window = newwin(
        this->parameters.tilemap.height, 
        this->parameters.tilemap.width,
        0,
        0
    );

    if (!this->_window) {
        throw Exception("Cannot create _window.");
    }
    box(this->_window, 0, 0);
    wrefresh(this->_window);
}

std::string NCursesGraphicLibrary::getName() const {
    return "nCurses";
}

    void NCursesGraphicLibrary::loadObjects(std::vector<std::shared_ptr<arcade::object>> GameObjects) {
        for (auto &object : GameObjects) {
            switch (object->type) {
                case TEXT:
                    initTextObjects(object);
            }
        }
    }

    void NCursesGraphicLibrary::loop() {
        renderTextObjects();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    void NCursesGraphicLibrary::initTextObjects(std::shared_ptr<object> &GameObject) {
        _text_objects.push_back(GameObject);
    }

    void NCursesGraphicLibrary::renderTextObjects() {
        for (auto &object: _text_objects) {
            mvwaddstr(_window, object->posY, object->posX, &object->text[0]);
            wrefresh(_window);
        }
    }

    extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new NCursesGraphicLibrary(parameters);
}

}