//
// Created by leo on 2022-03-24.
//

#ifndef ARCADE_IGRAPHICLIBRARY_HPP
#define ARCADE_IGRAPHICLIBRARY_HPP

#include <string>
#include "object.hpp"
#include <vector>
#include <memory>

namespace arcade {

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
        virtual void createWindow() {}
        virtual std::string getName() const { return ""; }
        virtual void closeWindow() {}
        virtual void loadObjects(std::vector<object> gameObjects) {}
        virtual void loop() {}
};

}

#endif //ARCADE_IGRAPHICLIBRARY_HPP
