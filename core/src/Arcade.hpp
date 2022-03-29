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
            void run(const std::string& libName);

        protected:

        private:
            std::shared_ptr<arcade::IGraphicLibrary> sdl2;
            std::shared_ptr<arcade::IGraphicLibrary> ncurses;
            std::shared_ptr<arcade::IGraphicLibrary> currentGraphic;
            std::shared_ptr<arcade::IGameLibrary> pacman;
            std::shared_ptr<arcade::IGameLibrary> currentGame;
            std::unique_ptr<arcade::DynamicLibrary> lib_sdl2;
            std::unique_ptr<arcade::DynamicLibrary> lib_ncurses;
            std::unique_ptr<arcade::DynamicLibrary> game_lib;
            KeyEvent input;
            bool running;

            void setCurrentGraphicLib(const std::string& libName);
            void handleKeyEvents();
    };

}

#endif //ARCADE_ARCADE_HPP
