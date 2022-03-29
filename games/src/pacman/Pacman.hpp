/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "graphic_library.hpp"
#include "game_library.hpp"
#include <memory>
#include <iostream>
#include <array>

namespace arcade {

class Pacman : public GameLibrary {
    private:
        void setGameObjects() override;
        void updateGameObjects() override;
        void initWall(int posX, int posY, int index);
        void initPacman(int posX, int posY);
        void initPhantoms(int posX, int posY);
        void readMap();
        void handlePacmanMovement();
        void setDirection();
        bool checkMovement(object entity, Direction direction);
        std::string map;
        object pacman;
        std::vector<object> walls;
        std::array<object, 4> phantoms;
    public:
        Pacman();
        ~Pacman();

};

}

#endif /* !PACMAN_HPP_ */
