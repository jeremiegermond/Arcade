/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** game_library
*/

#ifndef ARCADE_IGAMELIBRARY_HPP
#define ARCADE_IGAMELIBRARY_HPP

#include "IGraphicLibrary.hpp"

namespace arcade {

class IGameLibrary {
    public:
        virtual ~IGameLibrary() = default;
        virtual void setGameObjects() = 0;
        virtual std::vector<object> getGameObjects() = 0;
        virtual void updateGameObjects() = 0;
        virtual void setKeyEvent(KeyEvent event) = 0;
        virtual int getLastScore() = 0;
        virtual bool hasGameEnded() = 0;
        virtual std::string getSelectedGame() = 0;
        virtual void setScoreVector(std::vector<std::pair<std::string, int>>) = 0;
};

extern "C" IGameLibrary *create_game();

}

#endif //ARCADE_IGAMELIBRARY_HPP
