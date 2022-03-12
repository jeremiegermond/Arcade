/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** library
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <functional>

namespace arcade {

class GameLibrary {
    private:
    public:
        virtual ~GameLibrary() = default;
        virtual std::string getName() const = 0;
};

class SDLLibrary : public GameLibrary {
    public:
        std::string getName() const override;
};

class NCursesLibrary : public GameLibrary {
    public:
        std::string getName() const override;
};

class GameLibraryFactory {
    public:
        using GameLibraryPtr = std::unique_ptr<GameLibrary>;
        using GameLibraryFunction = std::function<GameLibraryPtr()>;
    private:
        std::unordered_map<std::string, GameLibraryFunction> functionByName;
    public:
        GameLibraryFactory();
        GameLibraryPtr operator()(const std::string &name);
};

}