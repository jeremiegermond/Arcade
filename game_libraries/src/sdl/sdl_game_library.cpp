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
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception("Cannot initialize SDL: " + std::string(SDL_GetError()));
    }
    TTF_Init();
    Sans = TTF_OpenFont("assets/Sans.ttf", 24);
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
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw Exception("Cannot initialize SDL: " + std::string(SDL_GetError()));
    }
    IMG_Init(IMG_INIT_PNG);
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
    started = true;
}

std::string SDLGraphicLibrary::getName() const {
    return "SDL2";
}

void SDLGraphicLibrary::loadObjects(std::vector<object> gameObjects) {
    for (auto &object : gameObjects) {
        switch (object.type) {
            case Type::TEXT:
                initTextObjects(object);
                break;
            case Type::ENTITY:
                initEntityObjects(object);
                break;
        }
    }
}

    void SDLGraphicLibrary::loop() {
        while (started) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            for (auto &i: textObjects) {
                SDL_RenderCopy(renderer, i.sdlTexture, nullptr, &i.sdlDstRect);
            }
            for (auto &i: entityObjects) {
                SDL_RenderCopyEx(renderer, i.sdlTexture, &i.sdlSrcRect, &i.sdlDstRect, i.rotation, NULL, SDL_FLIP_NONE);
            }
            SDL_RenderPresent(renderer);
            if (SDL_GetTicks() > lastTime + 150) {
                animateEntityObject();
                lastTime = SDL_GetTicks();
            }
            //            SDL_Delay(15);
        }
    }

    void SDLGraphicLibrary::initTextObjects(object &gameObject) {
        sdlObject castedObject(gameObject);

        castedObject.sdlSurface = TTF_RenderText_Solid(Sans, castedObject.text.c_str(), textColor);
        if (castedObject.sdlSurface == nullptr) {
            std::cout << SDL_GetError() << std::endl;
            throw arcade::Exception("texture is null");
        }
        castedObject.sdlTexture =  SDL_CreateTextureFromSurface(renderer, castedObject.sdlSurface);
        if (castedObject.sdlTexture == nullptr) {
            std::cout << SDL_GetError() << std::endl;
            throw arcade::Exception("surface is null");
        }
        castedObject.sdlDstRect.h = 100;
        castedObject.sdlDstRect.w = 200;
        castedObject.sdlDstRect.x = castedObject.posX * 25;
        castedObject.sdlDstRect.y = castedObject.posY * 25;
        SDL_RenderCopy(renderer, castedObject.sdlTexture, nullptr, &castedObject.sdlDstRect);

        textObjects.push_back(castedObject);
    }

    void SDLGraphicLibrary::initEntityObjects(object &gameObject) {
        sdlObject castedObject(gameObject);

        castedObject.sdlSurface = IMG_Load(castedObject.texturePath.c_str());
        if (castedObject.sdlSurface == nullptr) {
            std::cout << SDL_GetError() << std::endl;
            throw arcade::Exception("texture is null");
        }
        castedObject.sdlTexture = SDL_CreateTextureFromSurface(renderer, castedObject.sdlSurface);
        if (castedObject.sdlTexture == nullptr) {
            std::cout << SDL_GetError() << std::endl;
            throw arcade::Exception("surface is null");
        }
        castedObject.sdlDstRect.h = 500;
        castedObject.sdlDstRect.w = 500;
        castedObject.sdlDstRect.x = castedObject.posX;
        castedObject.sdlDstRect.y = castedObject.posY;
        castedObject.sdlSrcRect = {0, 0, 20, 20};

        entityObjects.push_back(castedObject);
    }

    void SDLGraphicLibrary::animateEntityObject() {
        for (auto &i: entityObjects) {
            if (!i.isAnimated)
                continue;
            if (i.currentFrame >= i.maxFrame)
                i.currentFrame = 0;
            i.sdlSrcRect = {i.animW * i.currentFrame, i.animH * i.currentFrame, i.Weight, i.Weight};
            i.currentFrame += 1;
        }
    }

    extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
        return new SDLGraphicLibrary(parameters);
    }
}