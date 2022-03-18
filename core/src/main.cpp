/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** main
*/

#include "game_library.hpp"
#include "dynamic_library.hpp"
#include "dlfcn.h"
#include <iostream>

int main() {
    arcade::DynamicLibrary dynamic("./libVulkan.so", RTLD_LAZY | RTLD_LOCAL);

    arcade::GameLibrary *lib = dynamic.create();
    std::cout << lib->getName() << std::endl;
}