/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** game_library
*/
#include "game_library.hpp"
#include <iostream>

namespace arcade {

GameLibrary::GameLibrary()
= default;

GameLibrary::~GameLibrary()
= default;

    void GameLibrary::setGameObjects() {
        game_text.text = "Pacman";
        game_text.posX = 34;

        _game_objects.push_back(std::make_shared<arcade::object>(game_text));
    }

    void GameLibrary::updateGameObjects() {

    }

    std::vector<std::shared_ptr<arcade::object>> GameLibrary::getGameObjects() {
        return _game_objects;
    }


}