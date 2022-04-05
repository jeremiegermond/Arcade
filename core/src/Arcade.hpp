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
#include <cassert>
#include <array>
#include <algorithm>
#include "Score.hpp"

namespace arcade {

class Arcade {
    public:
        Arcade();

        void run(const std::string &libName);
        void switchLib();
    private:
        std::unique_ptr<IGraphicLibrary> currentGraphic;
        DynamicLibrary currentGraphicLib;
        size_t graphicIndex = 0;

        std::shared_ptr<IGameLibrary> currentGame;
        DynamicLibrary pacmanLib;
        std::shared_ptr<IGameLibrary> pacman;

        KeyEvent input;
        bool running;
        Score scoreBoard;
        std::string username;

        void getNextLibrary();
        void handleKeyEvents();
};

}

#endif //ARCADE_ARCADE_HPP
