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
        virtual void createWindow() = 0;
        virtual std::string getName() const = 0;
        virtual void closeWindow() = 0;
        virtual void loadObjects(std::vector<std::shared_ptr<arcade::object>> GameObjects) = 0;
        virtual void loop() = 0;
    };

}

#endif //ARCADE_IGRAPHICLIBRARY_HPP
