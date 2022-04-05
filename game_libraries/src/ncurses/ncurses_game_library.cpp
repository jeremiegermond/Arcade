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

NCursesGraphicLibrary::NCursesGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters, "ncurses"), timeUpdate(50)
{
}

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
    wrefresh(this->window);
    curs_set(0);
    noecho();
    start_color();
    keypad(window, true);
    nodelay(window, true);
    chrono = NOW;
}

void NCursesGraphicLibrary::loadObjects(std::vector<object> GameObjects) {
    for (auto &object : GameObjects) {
        switch (object.type) {
            case Type::TEXT:
                initTextObjects(object);
                break;
            case Type::ENTITY:
                initEntityObjects(object);
                break;
            default:
                break;
        }
    }
}

KeyEvent NCursesGraphicLibrary::loop() {
    if (timeRefresh()) {
        wclear(window);
        drawEntityObject();
        drawTextObject();
        wrefresh(this->window);
    }

    return handleInputs();//handleInputs();
}

void NCursesGraphicLibrary::initTextObjects(object &gameObject) {
    textObjects.push_back(gameObject);
}

void NCursesGraphicLibrary::initEntityObjects(object &gameObject) {
    entityObjects.push_back(gameObject);
}

KeyEvent NCursesGraphicLibrary::handleInputs() {
    KeyEvent input = KeyEvent::NONE;
    int key = wgetch(window);
    
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
        case 'z':
            input = KeyEvent::z;
            break;
        case 'q':
            input = KeyEvent::q;
            break;
        case 's':
            input = KeyEvent::s;
            break;
        case 'd':
            input = KeyEvent::d;
            break;
        default:
            break;
    }
    return input;
}

    void NCursesGraphicLibrary::drawTextObject() {
        for (auto &i: textObjects) {
            wmove(window, *i.posY, *i.posX);
            waddstr(window, i.text->c_str());
        }
    }

    void NCursesGraphicLibrary::drawEntityObject() {
        init_pair(1, COLOR_BLUE, COLOR_BLUE);
        init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(3, COLOR_RED, COLOR_RED);
        init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(5, COLOR_CYAN, COLOR_CYAN);
        init_pair(6, COLOR_WHITE, COLOR_WHITE);
        init_pair(7, COLOR_GREEN, COLOR_GREEN);

        for (auto &i: entityObjects) {
            wmove(window, *i.posY, *i.posX);
            switch (i.chr) {
                case 'X':
                    wattron(window, COLOR_PAIR(1));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(1));
                    break;
                case 'O':
                    wattron(window, COLOR_PAIR(2));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(2));
                    break;
                case 'P':
                    wattron(window, COLOR_PAIR(3));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(3));
                    break;
                case 'M':
                    wattron(window, COLOR_PAIR(4));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(4));
                    break;
                case 'U':
                    wattron(window, COLOR_PAIR(5));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(5));
                    break;
                case 'L':
                    wattron(window, COLOR_PAIR(6));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(6));
                    break;
                case '.':
                    if (*i.state != State::ALIVE)
                        break;
                    wattron(window, COLOR_PAIR(0));
                    waddch(window, i.chr);
                    wattroff(window, COLOR_PAIR(0));
                    break;
                case 'C':
                    if (*i.state != State::ALIVE)
                        break;
                    wattron(window, COLOR_PAIR(7));
                    waddch(window, 'C');
                    wattroff(window, COLOR_PAIR(7));
                    break;
                default:
                    break;
            }
        }
    }

    bool NCursesGraphicLibrary::timeRefresh() {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(NOW - chrono).count() > timeUpdate) {
            chrono = NOW;
            return true;
        }
        return false;
    }

    extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new NCursesGraphicLibrary(parameters);
}

}