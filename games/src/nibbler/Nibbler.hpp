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

namespace arcade
{
   class Nibbler : public GameLibrary {
    private:
        void initNibbler(int posX, int posY);
        void readMap();
        void initWall(int posX, int posY, int index);
        void initApples(int posX, int posY);
        void updateScore();
        bool handleBeginOrEnd();

        std::vector<std::string> map;
        object nibbler;
        int applesNumber;
        int totalApples;
        std::vector<object> apples;
        std::vector<object> walls;
    
    public:
        Nibbler();
        ~Nibbler();
};

}


#endif /* !NIBBLER_HPP_ */
