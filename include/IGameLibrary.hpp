/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** game_library
*/

#ifndef ARCADE_IGAMELIBRARY_HPP
#define ARCADE_IGAMELIBRARY_HPP

namespace arcade {
    
class IGameLibrary {
    public:
        virtual ~IGameLibrary() = default;
        virtual void setGameObjects() {}
        virtual std::vector<object> getGameObjects() { return std::vector<object>(); }
};

extern "C" IGameLibrary *create_game();

}

#endif //ARCADE_IGAMELIBRARY_HPP
