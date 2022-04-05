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
        void initTeleporters(int posX, int posY);
        void readMap();
        void handlePacmanMovement();
        void handleTeleportation();
        void setDirection();
        bool checkMovement(object &entity, float speed);
        bool updateByTime();
        bool checkColision(object &entity, float speed);
        static bool isInt(float val);
        void setPacmanRotation();
        void handlePacgumColision();
        void handlePhantomsMovement();
        void setRandomDirection(object &entity);
        void handlePhantomColision();
        void gameEnd();
        void resetGame();
        void resetPhantom(int posX, int posY);
        void resetPacman(int posX, int posY);
        void resetPacgums();
        void handleInvicibility();
        void handlePacmanEatPhantom(object &i);
        void handleDeadPhantom(object &i);
        void updateScore();
        bool handleBeginOrEnd();
        void handleWin();

        std::vector<std::string> map;
        object pacman;
        float pacmanSpeed;
        float fantomsSpeed;
        float initialFantomsSpeed;
        bool invicible;
        int phantomSpawnX;
        int phantomSpawnY;
        bool started;
        int pacgumsNumber;
        int totalPacgums;
        std::vector<object> pacgums;
        std::vector<object> bigPacgums;
        std::vector<object> walls;
        std::array<object, 2> teleporters;
        std::array<object, 4> phantoms;
        std::chrono::high_resolution_clock::time_point chrono;
        std::chrono::high_resolution_clock::time_point chrono_invicibility;
        std::chrono::duration<long, std::ratio<1, 1000>>::rep timeUpdate;
        std::chrono::duration<long, std::ratio<1, 1000>>::rep timeInvicibility;

    public:
        Pacman();
        ~Pacman() = default;
};

}

#endif /* !PACMAN_HPP_ */
