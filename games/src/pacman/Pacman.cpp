/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "../game_library.hpp"

#include <iostream>

namespace arcade {

Pacman::Pacman() : GameLibrary(), pacman(new object), phantoms1(new object), phantoms2(new object), phantoms3(new object), phantoms4(new object)
{
    std::cout << "PACMAN" << std::endl;
}

Pacman::~Pacman()
= default;

void Pacman::setGameObjects()
{
    game_text.text = "Pacman";
    game_text.posX = 34;
    game_text.type = TEXT;
    pacman->texturePath = "../assets/pacman.png";
    pacman->maxFrame = 3;
    pacman->type = ENTITY;
    pacman->animW = 20;
    pacman->animH = 0;
    pacman->isAnimated = true;
    pacman->Weight = 20;
    pacman->Height = 20;
//    pacman->rotation = 180;
    phantoms1->texturePath = "../assets/pacman.png";
    phantoms1->maxFrame = 1;
    phantoms1->type = ENTITY;
    phantoms1->animW = 20;
    phantoms1->animH = 0;
    phantoms1->isAnimated = true;
    phantoms1->Weight = 20;
    phantoms1->Height = 20;
//    phantoms1->rotation = 180;

    _game_objects.push_back(std::make_shared<arcade::object>(game_text));
    _game_objects.push_back(pacman);
}

void Pacman::updateGameObjects()
{
    
}

extern "C" IGameLibrary* create_game()
{
    return new Pacman();
}

}