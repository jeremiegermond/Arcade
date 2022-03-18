/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** dynamic_library
*/

#include "dynamic_library.hpp"
#include "exception.hpp"

namespace arcade {

DynamicLibrary::DynamicLibrary(const std::string &library, int flags) :
    handle(dlopen(library.c_str(), flags), [] (void *handle) { dlclose(handle); }) {

    if (!handle) {
        throw Exception("Cannot open file " + std::string(dlerror()));
    }
}

GameLibrary * DynamicLibrary::create() {
    void *fptr = dlsym(this->handle.get(), "create");

    if (!fptr) {
        throw Exception("Cannot find create function " + std::string(dlerror()));
    }

    arcade::GameLibrary * (* create) () = (arcade::GameLibrary * (*) ()) fptr;
    
    return create();
}

}