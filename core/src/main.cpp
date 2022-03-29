/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** main
*/

#include "Arcade.hpp"

#include "graphic_library.hpp"
#include "dynamic_library.hpp"
#include "dlfcn.h"
#include <iostream>
#include <thread>
#include <memory>

int main(int argc, char **argv) {
    arcade::Arcade game;
    if (argc == 2) {
        game.run(argv[1]);
    }

//    arcade::GraphicLibrary::Parameters parameters {
//        .window = {
//            .title = "Arcade",
//            .width = 1920,
//            .height = 1080
//        },
//        .tilemap = {
//            .width = 76,
//            .height = 22
//        }
//    };
//
//    {
//        arcade::KeyEvent input;
//
//        arcade::DynamicLibrary dynamic("./lib/arcade_sdl2.so", RTLD_LAZY | RTLD_LOCAL);
//        std::unique_ptr<arcade::IGraphicLibrary> lib(dynamic.create(parameters));
//        std::cout << lib->getName() << std::endl;
//
//        arcade::DynamicLibrary lib_ncurses("./lib/arcade_ncurses.so", RTLD_LAZY | RTLD_LOCAL);
//        std::unique_ptr<arcade::IGraphicLibrary> lib2(lib_ncurses.create(parameters));
//        std::cout << lib2->getName() << std::endl;
//
//        arcade::DynamicLibrary game_lib("./lib/arcade_pacman.so", RTLD_LAZY | RTLD_LOCAL);
//        std::unique_ptr<arcade::IGameLibrary> game(game_lib.create_game());
//
//        game->setGameObjects();
//        lib->createWindow();
//        lib->loadObjects(game->getGameObjects());
//        while (input != arcade::KeyEvent::ESCAPE) {
//            input = lib->loop();
//        }
//    }
}