/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** game_library
*/

#pragma once

#include <string>

namespace arcade {

class GameLibrary {
    public:
        virtual std::string getName() const = 0;
};

}