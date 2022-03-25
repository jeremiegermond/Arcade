/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#include "sdl_game_library.hpp"
#include <iostream>

namespace arcade {

SDLGraphicLibrary::SDLGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters), window(nullptr) {
    TTF_Init();
    Sans = TTF_OpenFont("../assets/Sans.ttf", 24);
    if (Sans == nullptr) {
        throw arcade::Exception("Can't open font file");
    }
    textColor = {255, 255, 255};
}

SDLGraphicLibrary::~SDLGraphicLibrary() {
    closeWindow();
}

void SDLGraphicLibrary::closeWindow()
{
    if (this->window) {
        SDL_DestroyWindow(this->window);
    }
    SDL_Quit();
}

void SDLGraphicLibrary::createWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception("Cannot initialize SDL: " + std::string(SDL_GetError()));
    }

    this->window = SDL_CreateWindow(
        this->parameters.window.title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->parameters.window.width,
        this->parameters.window.height,
        SDL_WINDOW_SHOWN
    );

    if (!this->window) {
        throw Exception("Cannot create _window: " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
}

std::string SDLGraphicLibrary::getName() const {
    return "SDL2";
}

    void SDLGraphicLibrary::loadObjects(std::vector<std::shared_ptr<arcade::object>> GameObjects) {
        for (auto &object : GameObjects) {
            switch (object->type) {
                case TEXT:
                    initTextObjects(object);
            }
        }
    }

    void SDLGraphicLibrary::loop() {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (auto &i : textObjects) {
            SDL_RenderCopy(renderer, i->sdlTexture, NULL, &i->sdlMessageRect);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
    }

    void SDLGraphicLibrary::initTextObjects(std::shared_ptr<object>& object) {
        sdlTextObject castedObject = *std::static_pointer_cast<sdlTextObject>(object);

        castedObject.sdlSurface = TTF_RenderText_Solid(Sans, castedObject.text.c_str(), textColor);
        castedObject.sdlTexture =  SDL_CreateTextureFromSurface(renderer, castedObject.sdlSurface);
        if (castedObject.sdlTexture == nullptr) {
            std::cout << SDL_GetError() << std::endl;
            throw arcade::Exception("surface is null");
        }
        castedObject.sdlMessageRect.h = 100;
        castedObject.sdlMessageRect.w = 200;
        castedObject.sdlMessageRect.x = castedObject.posX * 25;
        castedObject.sdlMessageRect.y = castedObject.posY * 25;
        SDL_RenderCopy(renderer, castedObject.sdlTexture, nullptr, &castedObject.sdlMessageRect);

        textObjects.push_back(std::make_shared<sdlTextObject>(castedObject));
    }

    extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
        return new SDLGraphicLibrary(parameters);
    }


}