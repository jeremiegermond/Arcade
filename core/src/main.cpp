/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** main
*/

#include "Arcade.hpp"

#include "graphic_library.hpp"
#include "dynamic_library.hpp"
#include "dlfcn.h"
#include <iostream>
#include <thread>
#include <memory>

int main(int argc, char **argv) {
    arcade::Arcade game;

    std::srand(std::time(nullptr));
    if (argc == 2) {
        game.run(argv[1]);
    }
}