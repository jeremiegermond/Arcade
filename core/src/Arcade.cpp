/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "exception.hpp"

namespace arcade {

constexpr std::array<std::string_view, 3> GRAPHIC_LIB_PATHS = {
    "./lib/arcade_sdl2.so",
    "./lib/arcade_sfml.so",
    "./lib/arcade_ncurses.so"
};

Arcade::Arcade() : input(KeyEvent::NONE), running(false) {
    this->pacmanLib.open("./lib/arcade_pacman.so", RTLD_LAZY | RTLD_LOCAL);
    this->pacman.reset(this->pacmanLib.create_game());
}

void Arcade::run(const std::string &libName) {
    auto itr = std::find(GRAPHIC_LIB_PATHS.begin(), GRAPHIC_LIB_PATHS.end(), std::string_view(libName.c_str()));

    if (itr == GRAPHIC_LIB_PATHS.end()) {
        throw Exception(libName + " is not a graphic lib.");
    }
    this->graphicIndex = itr - GRAPHIC_LIB_PATHS.begin();

    getNextLibrary();
    currentGame = pacman;
    currentGame->setGameObjects();
    this->currentGraphic->createWindow();
    this->currentGraphic->loadObjects(currentGame->getGameObjects());
    running = true;
    while (running) {
        input = currentGraphic->loop();
        handleKeyEvents();
        currentGame->setKeyEvent(input);
        pacman->updateGameObjects();
        switchLib();
    }
    currentGraphic->closeWindow();
}

void Arcade::getNextLibrary() {
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
    std::string path = GRAPHIC_LIB_PATHS[this->graphicIndex].data();
    this->currentGraphic.reset(nullptr);
    this->currentGraphicLib.open(path, RTLD_LAZY | RTLD_LOCAL);
    this->currentGraphic.reset(this->currentGraphicLib.create(parameters));
    this->graphicIndex = (this->graphicIndex + 1) % GRAPHIC_LIB_PATHS.size();
}

void Arcade::handleKeyEvents() {
    if (input == KeyEvent::q)
        running = false;
}

void Arcade::switchLib() {
    if (input == KeyEvent::d || input == KeyEvent::s) {
        currentGraphic->closeWindow();
        getNextLibrary();
        currentGraphic->createWindow();
        currentGraphic->loadObjects(currentGame->getGameObjects());
        input = KeyEvent::NONE;
    }
}

}