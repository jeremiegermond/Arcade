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

Arcade::Arcade() : input(KeyEvent::NONE), running(false), scoreBoard() {
    this->pacmanLib.open("./lib/arcade_pacman.so", RTLD_LAZY | RTLD_LOCAL);
    this->pacman.reset(this->pacmanLib.create_game());
    this->nibblerLib.open("./lib/arcade_nibbler.so", RTLD_LAZY | RTLD_LOCAL);
    this->nibbler.reset(this->nibblerLib.create_game());
    this->menuLib.open("./lib/arcade_menu.so", RTLD_LAZY | RTLD_LOCAL);
    this->menu.reset(this->menuLib.create_game());
}

void Arcade::run(const std::string &libName) {
    auto itr = std::find(GRAPHIC_LIB_PATHS.begin(), GRAPHIC_LIB_PATHS.end(), std::string_view(libName.c_str()));

    if (itr == GRAPHIC_LIB_PATHS.end()) {
        throw Exception(libName + " is not a graphic lib.");
    }
    this->graphicIndex = itr - GRAPHIC_LIB_PATHS.begin();

    username = "user";

    getCurrentLibrary();
    currentGame = menu;
    currentGame->setGameObjects();
    currentGraphic->createWindow();
    currentGraphic->loadObjects(currentGame->getGameObjects());
    running = true;
    while (running) {
        input = currentGraphic->loop();
        if (currentGame == menu) {
            if (input == KeyEvent::UP) {
                if (currentGame->getSelectedGame() == "pacman") {
                    currentGame = pacman;
                } else if (currentGame->getSelectedGame() == "nibbler") {
                    currentGame = nibbler;
                }
                currentGame->setGameObjects();
                currentGraphic->loadObjects(currentGame->getGameObjects());
                input = KeyEvent::NONE;
                continue;
            }
        }
        handleKeyEvents();
        currentGame->setKeyEvent(input);
        currentGame->updateGameObjects();
        switchLib();
        if (currentGame->hasGameEnded() || !running) {
            scoreBoard.addToScoreboard(username, currentGame->getLastScore());
        }
    }
    currentGame.reset();
}

void Arcade::getNextLibrary() {
    this->graphicIndex = (this->graphicIndex + 1) % GRAPHIC_LIB_PATHS.size();
    getCurrentLibrary();
}

void Arcade::getPrevLibrary() {
   this->graphicIndex = this->graphicIndex == 0 ? GRAPHIC_LIB_PATHS.size() - 1 : this->graphicIndex - 1;
   getCurrentLibrary();
}

void Arcade::getCurrentLibrary() {
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
}

void Arcade::handleKeyEvents() {
    if (input == KeyEvent::q) {
        currentGraphic->closeWindow();
        currentGraphic.reset(nullptr);
        running = false;
    }
}

void Arcade::switchLib() {
    if (input == KeyEvent::d || input == KeyEvent::s) {
        currentGraphic->closeWindow();
        if (input == KeyEvent::s) {
            getPrevLibrary();
        } else {
            getNextLibrary();
        }
        currentGraphic->createWindow();
        currentGraphic->loadObjects(currentGame->getGameObjects());
        input = KeyEvent::NONE;
    }
}

}