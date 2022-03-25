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
    NONE
};

struct object {
    Type type;
    std::string texturePath;
    std::string text;
    char chr;
    int posX;
    int posY;
    bool isAnimated;
    int currentFrame;
};

}

#endif /* !OBJECT_HPP_ */
