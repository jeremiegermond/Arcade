/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#include "sdl_game_library.hpp"
#include <iostream>

namespace arcade {

SDLGameLibrary::SDLGameLibrary(const Parameters &parameters) : GameLibrary(parameters), window(nullptr) {}

SDLGameLibrary::~SDLGameLibrary() {
    if (this->window) {
        SDL_DestroyWindow(this->window);
    }
    SDL_Quit();
}

void SDLGameLibrary::createWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception("Cannot initialize SDL: " + std::string(SDL_GetError()));
    }

    this->window = SDL_CreateWindow(
        this->parameters.window.title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->parameters.window.width,
        this->parameters.window.height,
        SDL_WINDOW_OPENGL
    );

    if (!this->window) {
        throw Exception("Cannot create window: " + std::string(SDL_GetError()));
    }
}

std::string SDLGameLibrary::getName() const {
    return "SDL2";
}

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters) {
    return new SDLGameLibrary(parameters);
}


}