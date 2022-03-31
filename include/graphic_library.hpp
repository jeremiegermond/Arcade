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
    protected:
        Parameters parameters;

        virtual void drawEntityObject() {};
        virtual void drawTextObject() {};
    public:
        GraphicLibrary(const Parameters &parameters) : parameters(parameters) {}
        ~GraphicLibrary() = default;
};

}