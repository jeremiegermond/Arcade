/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** game_library_factory
*/

#include "arcade.hpp"

namespace arcade {

GameLibraryFactory::GameLibraryFactory() {
    this->functionByName = {
        { "nCurses", [] () { return GameLibraryFactory::GameLibraryPtr(new NCursesLibrary()); } },
        { "SDL2", [] () { return GameLibraryFactory::GameLibraryPtr(new SDLLibrary()); } }
    };
}

GameLibraryFactory::GameLibraryPtr GameLibraryFactory::operator()(const std::string &name) {
    auto itr = this->functionByName.find(name);

    if (itr != this->functionByName.end()) {
        return itr->second();
    }

    return nullptr;
}

}