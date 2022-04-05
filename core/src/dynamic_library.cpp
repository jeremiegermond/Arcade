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

IGraphicLibrary * DynamicLibrary::create(const IGraphicLibrary::Parameters &parameters) {
    void *fptr = dlsym(this->handle.get(), "create");

    if (!fptr) {
        throw Exception("Cannot find create function " + std::string(dlerror()));
    }

    IGraphicLibrary * (* create) (const IGraphicLibrary::Parameters &) = (IGraphicLibrary * (*) (const IGraphicLibrary::Parameters &)) fptr;
    
    return create(parameters);
}

IGameLibrary * DynamicLibrary::create_game() {
    void *fptr = dlsym(this->handle.get(), "create_game");

    if (!fptr) {
        throw Exception("Cannot find create_game function " + std::string(dlerror()));
    }

    IGameLibrary * (* create_game) () = (IGameLibrary * (*) ()) fptr;
    
    return create_game();
}

}