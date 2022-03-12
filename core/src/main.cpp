/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** main
*/

#include "arcade.hpp"

int main() {
    arcade::GameLibraryFactory factory;
    auto lib = factory("nCurses");
    auto lib2 = factory("SDL2");
    auto lib3 = factory("libcaca");

    std::cout << (lib ? lib->getName() : "null") << std::endl;
    std::cout << (lib2 ? lib2->getName() : "null") << std::endl;
    std::cout << (lib3 ? lib3->getName() : "null") << std::endl;
}