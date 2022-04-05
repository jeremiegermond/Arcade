/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/

#pragma once

#include "graphic_library.hpp"
#include <ncurses.h>
#include "exception.hpp"
#include <vector>
#include <memory>
#include <chrono>

#define NOW std::chrono::high_resolution_clock::now()

namespace arcade {

class NCursesGraphicLibrary : public GraphicLibrary {
    private:
        WINDOW *window;
        std::vector<object> textObjects;
        std::vector<object> entityObjects;
        std::chrono::high_resolution_clock::time_point chrono;
        std::chrono::duration<long, std::ratio<1, 1000>>::rep timeUpdate;

    void initTextObjects(object &gameObject);
        void initEntityObjects(object &gameObject);
        void drawEntityObject() override;
        void drawTextObject() override;
        KeyEvent handleInputs();
    public:
        NCursesGraphicLibrary(const Parameters &parameters);
        ~NCursesGraphicLibrary() = default;
        
        void createWindow() override;
        void closeWindow() override;
        void loadObjects(std::vector<object> gameObjects) override;
        KeyEvent loop() override;
        bool timeRefresh();
};

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters);

}