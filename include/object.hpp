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

struct object
{
    Type type;
    std::string texturePath;
    std::string text;
    char chr;
    int posX;
    int posY;
    int animW;
    int animH;
    int spriteW;
    int spriteH;
    double rotation;
    bool isAnimated;
    int currentFrame;
    int maxFrame;
};

}

#endif /* !OBJECT_HPP_ */
