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
        std::string name;

        virtual void drawEntityObject() {};
        virtual void drawTextObject() {};
    public:
        GraphicLibrary(const Parameters &parameters, std::string name) : parameters(parameters), name(name) {}
        ~GraphicLibrary() = default;
        std::string getName() const override { return name; };
};

}