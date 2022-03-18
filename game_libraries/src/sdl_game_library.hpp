/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#pragma once

#include "game_library.hpp"

namespace arcade {

class SDLGameLibrary : public GameLibrary {
    private:
    public:
        std::string getName() const override;
};

extern "C" GameLibrary *create();

}