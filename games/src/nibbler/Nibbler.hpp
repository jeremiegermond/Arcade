/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "game_library.hpp"
#include <istream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <chrono>

#define NOW std::chrono::high_resolution_clock::now()

namespace arcade {

class Nibbler : public GameLibrary {
    private:
        void initNibbler(int posX, int posY);
        void readMap();
        void initWall(int posX, int posY, int index);
        void initApples(int posX, int posY);
        void updateScore();
        bool handleBeginOrEnd();
        void setGameObjects();
        void updateGameObjects();
        void handleNibblerMovement();
        void setDirection();
        bool checkMovement(object &entity, float speed);
        bool updateByTime();
        bool checkColision(object &entity, float speed);
        bool isInt(float val);
        void setNibblerRotation();
        void handleAppleColision();
        void gameEnd();
        void handleWin();
        void resetNibbler(int posX, int posY);
        void resetGame();
        void resetApples();

        std::vector<std::string> map;
        object nibbler;
        float nibblerSpeed;
        bool started;
        int applesNumber;
        int totalApples;
        std::vector<object> apples;
        std::vector<object> walls;
        std::chrono::high_resolution_clock::time_point chrono;
        std::chrono::duration<long, std::ratio<1, 1000>>::rep timeUpdate;
    
    public:
        Nibbler();
};

}


#endif /* !NIBBLER_HPP_ */
