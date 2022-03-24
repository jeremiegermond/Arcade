/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/

#pragma once

#pragma once

#include "../graphic_library.hpp"
#include <ncurses.h>
#include "exception.hpp"
#include <vector>
#include <memory>

namespace arcade {

class NCursesGraphicLibrary : public GraphicLibrary {
    private:
        WINDOW *_window;
        std::vector<std::shared_ptr<arcade::object>> _text_objects;

        void initTextObjects(std::shared_ptr<object>& GameObject);
        void renderTextObjects();
    public:
        NCursesGraphicLibrary(const Parameters &parameters);
        ~NCursesGraphicLibrary();
        
        void createWindow() override;
        std::string getName() const override;
        void closeWindow() override;
        void loadObjects(std::vector<std::shared_ptr<arcade::object>> GameObjects) override;
        void loop() override;
};

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters);

}