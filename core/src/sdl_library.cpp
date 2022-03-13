/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_library
*/

#include "arcade.hpp"

namespace arcade {

SDLLibrary::SDLLibrary() noexcept(false) : handle(dlopen("./libsdl2.so", RTLD_LAZY)) {
    if (!handle) {
        throw Exception("Cannot open libsdl2.so");
    }
}

std::string SDLLibrary::getName() const {
    return "SDL2";
}

}