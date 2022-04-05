/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Arcade.hpp
*/

#ifndef ARCADE_ARCADE_HPP
#define ARCADE_ARCADE_HPP

#include <string>
#include "dynamic_library.hpp"
#include "IGraphicLibrary.hpp"
#include "IGameLibrary.hpp"
#include "graphic_library.hpp"
#include "Score.hpp"

namespace arcade {

class Arcade {
    public:
        Arcade();
        ~Arcade();
        void run(const std::string &libName);
        void switchLib();
    private:
        IGraphicLibrary *sdl2;
        IGraphicLibrary *ncurses;
        IGraphicLibrary *currentGraphic{};
        IGameLibrary *pacman;
        IGameLibrary *currentGame{};
        DynamicLibrary *lib_sdl2;
        DynamicLibrary *lib_ncurses;
        DynamicLibrary *lib_pacman;
        KeyEvent input;
        bool running;
        Score scoreBoard;

        void setCurrentGraphicLib(const std::string &libName);
        void handleKeyEvents();
};

}

#endif //ARCADE_ARCADE_HPP
