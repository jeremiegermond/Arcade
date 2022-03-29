/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** game_library
*/

#ifndef GAME_LIBRARY_HPP_
#define GAME_LIBRARY_HPP_

#include <memory>
#include <vector>
#include "object.hpp"
#include "IGameLibrary.hpp"

namespace arcade {

class GameLibrary : public IGameLibrary {
    protected:
        std::vector<object> gameObjects;
        object gameText;
        KeyEvent event;
        virtual void updateGameObjects() {}
    public:
        GameLibrary() = default;
        ~GameLibrary() override = default;
        std::vector<object> getGameObjects() override { return this->gameObjects; }
        void setGameObjects() override {}
        void setKeyEvent(KeyEvent e) override { event = e; }

};

}

#endif /* !GAME_LIBRARY_HPP_ */
