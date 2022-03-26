/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "game_library.hpp"

#include <iostream>

namespace arcade {

Pacman::Pacman() : GameLibrary()
{
    std::cout << "PACMAN" << std::endl;
}

Pacman::~Pacman()
= default;

void Pacman::setGameObjects()
{
    gameText.text = "Pacman";
    gameText.posX = 34;
    gameText.type = Type::TEXT;
    pacman.texturePath = "./assets/pacman.png";
    pacman.maxFrame = 3;
    pacman.type = Type::ENTITY;
    pacman.animW = 20;
    pacman.animH = 0;
    pacman.isAnimated = true;
    pacman.spriteW = 20;
    pacman.spriteH = 20;
//    pacman->rotation = 180;
//    phantoms1->rotation = 180;

    gameObjects.push_back(gameText);
    gameObjects.push_back(pacman);
}

void Pacman::updateGameObjects() {
    
}

extern "C" IGameLibrary* create_game() {
    return new Pacman();
}

}