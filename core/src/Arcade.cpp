/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "exception.hpp"

namespace arcade {

Arcade::Arcade() : input(KeyEvent::NONE), running(false) {
    GraphicLibrary::Parameters parameters {
        .window = {
            .title = "Arcade",
            .width = 1920,
            .height = 1080
        },
        .tilemap = {
            .width = 76,
            .height = 22
        }
    };
    lib_sdl2 = std::make_unique<DynamicLibrary>(DynamicLibrary("./lib/arcade_sdl2.so", RTLD_LAZY | RTLD_LOCAL));
    sdl2.reset(lib_sdl2->create(parameters));

    lib_ncurses = std::make_unique<DynamicLibrary>(DynamicLibrary("./lib/arcade_ncurses.so", RTLD_LAZY | RTLD_LOCAL));
    ncurses.reset(lib_ncurses->create(parameters));

    game_lib = std::make_unique<DynamicLibrary>(DynamicLibrary("./lib/arcade_pacman.so", RTLD_LAZY | RTLD_LOCAL));
    pacman.reset(game_lib->create_game());
}

Arcade::~Arcade() {
    pacman.reset();
    ncurses.reset();
    sdl2.reset();
    currentGraphic.reset();
    currentGame.reset();
}

void Arcade::run(const std::string &libName) {
    setCurrentGraphicLib(libName);
    currentGame = pacman;
    currentGame->setGameObjects();
    currentGraphic->createWindow();
    currentGraphic->loadObjects(currentGame->getGameObjects());
    running = true;
    while (running) {
        input = currentGraphic->loop();
        handleKeyEvents();
        currentGame->setKeyEvent(input);
        pacman->updateGameObjects();
    }
}

void Arcade::setCurrentGraphicLib(const std::string &libName) {
    if (libName == "./lib/arcade_sdl2.so")
        currentGraphic = sdl2;
    else if (libName == "./lib/arcade_ncurses.so")
        currentGraphic = ncurses;
    else
        throw arcade::Exception("invalid lib path");
}

void Arcade::handleKeyEvents() {
    if (input == KeyEvent::ESCAPE)
        running = false;
}

}