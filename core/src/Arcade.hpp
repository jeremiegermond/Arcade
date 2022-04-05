/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Arcade.hpp
*/

#ifndef ARCADE_ARCADE_HPP
#define ARCADE_ARCADE_HPP

#include <string>
#include <memory>
#include "IGraphicLibrary.hpp"
#include "IGameLibrary.hpp"
#include "dynamic_library.hpp"
#include "graphic_library.hpp"

namespace arcade {

class Arcade {
    public:
        Arcade();
        ~Arcade();
        void run(const std::string &libName);
        void switchLib();
    private:
        std::shared_ptr<IGraphicLibrary> sdl2;
        std::shared_ptr<IGraphicLibrary> ncurses;
        std::shared_ptr<IGraphicLibrary> currentGraphic;
        std::shared_ptr<IGameLibrary> pacman;
        std::shared_ptr<IGameLibrary> currentGame;
        std::unique_ptr<DynamicLibrary> lib_sdl2;
        std::unique_ptr<DynamicLibrary> lib_ncurses;
        std::unique_ptr<DynamicLibrary> game_lib;
        KeyEvent input;
        bool running;

        void setCurrentGraphicLib(const std::string &libName);
        void handleKeyEvents();
};

}

#endif //ARCADE_ARCADE_HPP
