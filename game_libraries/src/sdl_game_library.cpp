/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#include "sdl_game_library.hpp"

namespace arcade {

std::string SDLGameLibrary::getName() const {
    return "SDL2";
}

extern "C" GameLibrary *create() {
    return new SDLGameLibrary();
}

}