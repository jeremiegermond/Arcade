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
    pacman->texturePath = "./assets/pacman.png";
    

    _game_objects.push_back(std::make_shared<arcade::object>(game_text));
}

void Pacman::updateGameObjects()
{
    
}

extern "C" IGameLibrary* create_game()
{
    return new Pacman();
}

}