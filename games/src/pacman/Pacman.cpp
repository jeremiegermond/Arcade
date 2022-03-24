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

Pacman::Pacman() : GameLibrary()
{
    std::cout << "PACMAN" << std::endl;
}

Pacman::~Pacman()
= default;

void Pacman::setGameObjects()
{
    GameLibrary::setGameObjects();
}

void Pacman::updateGameObjects()
{
    
}

extern "C" IGameLibrary* create_game()
{
    return new Pacman();
}

}