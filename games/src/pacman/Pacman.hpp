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
#include <chrono>


#define NOW std::chrono::high_resolution_clock::now()

namespace arcade {

    class Pacman : public GameLibrary {
    private:
        void setGameObjects() override;
        void updateGameObjects() override;
        void initWall(int posX, int posY, int index);
        void initPacman(int posX, int posY);
        void initPhantoms(int posX, int posY, char chr);
        void initPacgums(int posX, int posY);
        void initBigPacgums(int posX, int posY);
        void readMap();
        void handlePacmanMovement();
        void setDirection();
        void checkMovement(object &entity);
        bool updateByTime();
        bool checkColision(object &entity);
        static bool isInt(float val);
        void setPacmanRotation();

        std::vector<std::string> map;
        object pacman;
        std::vector<object> pacgums;
        std::vector<object> bigPacgums;
        std::vector<object> walls;
        std::array<object, 4> phantoms;
        std::chrono::high_resolution_clock::time_point chrono;
        const std::chrono::duration<long, std::ratio<1, 1000>>::rep timeUpdate;

    public:
        Pacman();
        ~Pacman();

};

}

#endif /* !PACMAN_HPP_ */
