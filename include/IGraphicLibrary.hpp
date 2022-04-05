/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** IGraphicLibrary
*/

#ifndef ARCADE_IGRAPHICLIBRARY_HPP
#define ARCADE_IGRAPHICLIBRARY_HPP

#include <string>
#include "object.hpp"
#include <vector>
#include <memory>

namespace arcade {

enum class KeyEvent {
    NONE,
    LEFT,
    UP,
    DOWN,
    RIGHT,
    ESCAPE,
    ENTER,
    z,
    q,
    s,
    d
};


class IGraphicLibrary {
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

        virtual ~IGraphicLibrary() = default;
        virtual void createWindow() = 0;
        virtual std::string getName() const = 0;
        virtual void closeWindow() = 0;
        virtual void loadObjects(std::vector<object> gameObjects) = 0;
        virtual KeyEvent loop() = 0;
};

}

#endif //ARCADE_IGRAPHICLIBRARY_HPP
