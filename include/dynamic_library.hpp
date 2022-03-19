/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** dynamic_library
*/

#pragma once

#include "game_library.hpp"
#include <string>
#include <memory>
#include "dlfcn.h"

namespace arcade {

class DynamicLibrary {
    private:
        std::unique_ptr<void, void (*) (void *)> handle;
    public:
        DynamicLibrary(const std::string &library, int flags);
        GameLibrary *create(const GameLibrary::Parameters &parameters);
};

}