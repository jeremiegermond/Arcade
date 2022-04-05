/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** dynamic_library
*/

#pragma once

#include "IGraphicLibrary.hpp"
#include "IGameLibrary.hpp"
#include <string>
#include <memory>
#include "dlfcn.h"

namespace arcade {

class DynamicLibrary {
    public:
        DynamicLibrary();
        void open(const std::string &library, int flags);
        IGraphicLibrary *create(const IGraphicLibrary::Parameters &parameters);
        IGameLibrary *create_game();
    private:
        std::unique_ptr<void, void (*) (void *)> handle;
};

}