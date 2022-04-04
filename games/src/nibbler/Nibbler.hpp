/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "game_library.hpp"

namespace arcade
{
   class Nibbler : public GameLibrary {
    private:
        void initNibbler(int posX, int posY);
        void readMap();
        void initWall(int posX, int posY, int index);
        void initNibbler(int posX, int posY);
        void initApples(int posX, int posY);

        std::vector<std::string> map;
        object nibbler;
        int applesNumber;
        int totalApples;
        std::vector<object> apples;
        std::vector<object> walls;
    
    public:
        Nibbler();
        ~Nibbler() = default;
};

}


#endif /* !NIBBLER_HPP_ */
