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

enum objectType {
    TEXT,
    ENTITY
};

enum objectState {
    NONE,
    ALIVE,
    DEAD
};

struct object
{
    objectType type;
    objectState state;
    std::string texturePath;
    std::string text;
    char chr;
    int posX;
    int posY;
    int animW;
    int animH;
    int Weight;
    int Height;
    double rotation;
    bool isAnimated;
    int currentFrame;
    int maxFrame;
};

}

#endif /* !OBJECT_HPP_ */
