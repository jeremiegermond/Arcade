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
    std::shared_ptr<State> state { new State(State::ALIVE) };
    std::string texturePath;
    std::shared_ptr<std::string> text { new std::string("") };
    char chr;
    std::shared_ptr<float> posX { new float(0) };
    std::shared_ptr<float> posY { new float(0) };
    std::shared_ptr<int> animX { new int(0) };
    std::shared_ptr<int> animY { new int(0) };
    std::shared_ptr<int> animW { new int(0) };
    std::shared_ptr<int> animH { new int(0) };
    std::shared_ptr<int> spriteW { new int(0) };
    std::shared_ptr<int> spriteH { new int(0) };
    int sizeW;
    int sizeH;
    std::shared_ptr<double> rotation { new double(0) };
    std::shared_ptr<int> mirrored { new int(0) };
    bool isAnimated;
    int currentFrame;
    int maxFrame;
    std::shared_ptr<Direction> direction { new Direction(Direction::RIGHT) };
    std::shared_ptr<Direction> bufferedDirection { new Direction(Direction::RIGHT) };
    std::shared_ptr<int> alpha { new int(255) };
};

}

#endif /* !OBJECT_HPP_ */
