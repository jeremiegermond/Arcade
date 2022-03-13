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
#include <exception>

namespace arcade {

class Exception : public std::exception {
    private:
        std::string message;
    public:
        Exception(const std::string &message) : message(message) {}
        const char *what() const noexcept { return this->message.c_str(); }
};

class GameLibrary {
    public:
        virtual ~GameLibrary() = default;
        virtual std::string getName() const = 0;
};

struct DLDeleter {
    void operator()(void *handle) {
        if (handle) {
            dlclose(handle);
        }
    }
};

class SDLLibrary : public GameLibrary {
    private:
        std::unique_ptr<void, DLDeleter> handle;
    public:
        SDLLibrary() noexcept(false);
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