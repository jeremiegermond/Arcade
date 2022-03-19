/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#pragma once

#include "game_library.hpp"
#include <SDL2/SDL.h>
#include "exception.hpp"

namespace arcade {

class SDLGameLibrary : public GameLibrary {
    private:
        SDL_Window *window;
    public:
        SDLGameLibrary(const Parameters &parameters);
        ~SDLGameLibrary();

        void createWindow() override;
        std::string getName() const override;
};

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters);

}