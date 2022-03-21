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
        struct Parameters {
            struct Window {
                std::string title;
                int width;
                int height;
            };

            struct TileMap {
                int width;
                int height;
            };
            Window window;
            TileMap tilemap;
        };
    protected:
        Parameters parameters;
        GameLibrary(const Parameters &parameters) : parameters(parameters) {}
    
    public:
        virtual ~GameLibrary() = default;
        virtual void createWindow() = 0;
        virtual std::string getName() const = 0;
};

}