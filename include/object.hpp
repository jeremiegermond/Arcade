/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <string>
#include <memory>

namespace arcade {

enum class Type {
    TEXT,
    ENTITY
};

enum class State {
    NONE,
    ALIVE,
    DEAD
};

enum class Direction {
    RIGHT,
    DOWN,
    UP,
    LEFT
};

struct object
{
    Type type;
    std::string texturePath;
    std::string text;
    char chr;
    std::shared_ptr<int> posX { new int() };
    std::shared_ptr<int> posY { new int() };
    int animX;
    int animY;
    int animW;
    int animH;
    int spriteW;
    int spriteH;
    int sizeW;
    int sizeH;
    std::shared_ptr<double> rotation { new double() };
    std::shared_ptr<int> mirrored { new int() };
    bool isAnimated;
    int currentFrame;
    int maxFrame;
    std::shared_ptr<Direction> direction { new Direction() };
};

}

#endif /* !OBJECT_HPP_ */
