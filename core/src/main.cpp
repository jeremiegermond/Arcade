/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** main
*/

#include "game_library.hpp"
#include "dlfcn.h"
#include <iostream>

int main() {
    void *handle = dlopen("./libnCurses.so", RTLD_LAZY | RTLD_LOCAL);

    if (!handle) {
        std::cout << "pas bon " << dlerror() << std::endl;
        return 1;
    }

    void *fptr = dlsym(handle, "create");
    arcade::GameLibrary *(* create)() = (arcade::GameLibrary * (*) ()) fptr;

    arcade::GameLibrary *lib = create();

    std::cout << lib->getName() << std::endl;

    delete lib;
    dlclose(handle);
}