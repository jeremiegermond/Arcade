/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** game_library
*/

#pragma once

#include <string>
#include "object.hpp"
#include <vector>
#include <memory>
#include "IGraphicLibrary.hpp"

namespace arcade {

class GraphicLibrary : public IGraphicLibrary {
    public:
    protected:
        Parameters parameters;

    public:
        GraphicLibrary(const Parameters &parameters);
        ~GraphicLibrary();
};

}