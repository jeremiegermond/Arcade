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

KeyEvent NCursesGraphicLibrary::loop() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    refresh();
    return KeyEvent::NONE;
}

void NCursesGraphicLibrary::initTextObjects(object &gameObject) {
    textObjects.push_back(gameObject);
}

void NCursesGraphicLibrary::initEntityObjects(object &gameObject) {
    entityObjects.push_back(gameObject);
}

KeyEvent NCursesGraphicLibrary::handleInputs() {
    KeyEvent input = KeyEvent::NONE;
    int key = getch();
    
    switch (key)
    {
    case KEY_UP:
        input = KeyEvent::UP;
        break;
    case KEY_DOWN:
        input = KeyEvent::DOWN;
        break;
    case KEY_LEFT:
        input = KeyEvent::LEFT;
        break;
    case KEY_RIGHT:
        input = KeyEvent::RIGHT;
        break;
    case KEY_EXIT:
        input = KeyEvent::ESCAPE;
        break;
    case ord('z'):
        input = KeyEvent::z;
        break;
    case ord('q'):
        input = KeyEvent::q;
        break;
    case ord('s'):
        input = KeyEvent::s;
        break;
    case ord('d'):
        input = KeyEvent::d;
        break;
    default:
        break;
    }
    return input;
}

    void NCursesGraphicLibrary::drawTextObject() {
        if()
    }

    void NCursesGraphicLibrary::drawEntityObject() {
        if()
    }

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new NCursesGraphicLibrary(parameters);
}

}