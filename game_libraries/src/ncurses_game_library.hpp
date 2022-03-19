/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** ncurses_game_library
*/

#pragma once

#pragma once

#include "game_library.hpp"
#include <ncurses.h>
#include "exception.hpp"

namespace arcade {

class NCursesGameLibrary : public GameLibrary {
    private:
        WINDOW *window;
    public:
        NCursesGameLibrary(const Parameters &parameters);
        ~NCursesGameLibrary();
        
        void createWindow() override;
        std::string getName() const override;
};

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters);

}