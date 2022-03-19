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
#include <thread>
#include <memory>

int main() {
    arcade::GameLibrary::Parameters parameters {
        .window = {
            .title = "Arcade",
            .width = 1920 / 2,
            .height = 1080 / 2
        },
        .tilemap = {
            .width = 15,
            .height = 15
        }
    };

    {arcade::DynamicLibrary dynamic("./libSDL2.so", RTLD_LAZY | RTLD_LOCAL);
    std::unique_ptr<arcade::GameLibrary> lib(dynamic.create(parameters));
    std::cout << lib->getName() << std::endl;
    lib->createWindow();
    std::this_thread::sleep_for(std::chrono::seconds(5));}


    {arcade::DynamicLibrary dynamic2("./libnCurses.so", RTLD_LAZY | RTLD_LOCAL);
    std::unique_ptr<arcade::GameLibrary> lib(dynamic2.create(parameters));
    std::cout << lib->getName() << std::endl;
    lib->createWindow();
    std::this_thread::sleep_for(std::chrono::seconds(5));}
}