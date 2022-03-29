/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#include "sdl_game_library.hpp"
#include <iostream>

namespace arcade {

SDLGraphicLibrary::SDLGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters), window(nullptr), gameSizeUnit(40) {
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

    KeyEvent SDLGraphicLibrary::loop() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (auto &i: entityObjects) {
            i.sdlDstRect = {*i.posX * gameSizeUnit, *i.posY * gameSizeUnit, i.sizeW * gameSizeUnit, i.sizeH * gameSizeUnit};
            SDL_RenderCopyEx(renderer, i.sdlTexture, &i.sdlSrcRect, &i.sdlDstRect, *i.rotation, nullptr, (SDL_RendererFlip)*i.mirrored);
        }
        for (auto &i: textObjects) {
            SDL_RenderCopy(renderer, i.sdlTexture, nullptr, &i.sdlDstRect);
        }
        SDL_RenderPresent(renderer);
        if (SDL_GetTicks() > lastTime + 150) {
            animateEntityObject();
            lastTime = SDL_GetTicks();
        }
        return handleInputs();
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
        castedObject.sdlDstRect = {*castedObject.posX * gameSizeUnit, *castedObject.posY * gameSizeUnit, 200, 100};
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
        castedObject.sdlDstRect = {*castedObject.posX * gameSizeUnit, *castedObject.posY * gameSizeUnit, castedObject.sizeW * gameSizeUnit, castedObject.sizeH * gameSizeUnit};
        if (castedObject.isAnimated)
            castedObject.sdlSrcRect = {castedObject.animX + castedObject.animW * castedObject.currentFrame, castedObject.animY + castedObject.animH * castedObject.currentFrame, castedObject.spriteW, castedObject.spriteH};
        else
            castedObject.sdlSrcRect = {castedObject.animX + castedObject.animW, castedObject.animY + castedObject.animH, castedObject.spriteW, castedObject.spriteH};

        entityObjects.push_back(castedObject);
    }

    void SDLGraphicLibrary::animateEntityObject() {
        for (auto &i: entityObjects) {
            if (!i.isAnimated)
                continue;
            if (i.currentFrame >= i.maxFrame)
                i.currentFrame = 0;
            i.sdlSrcRect = {i.animX + i.animW * i.currentFrame, i.animY + i.animH * i.currentFrame, i.spriteW, i.spriteW};
            i.currentFrame += 1;
        }
    }

    KeyEvent SDLGraphicLibrary::handleInputs() {
        SDL_Event event;
        KeyEvent input = KeyEvent::NONE;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                closeWindow();
                std::exit(0);
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        input = KeyEvent::ESCAPE;
                        break;
                    case SDLK_RIGHT:
                        input = KeyEvent::RIGHT;
                        break;
                    case SDLK_LEFT:
                        input = KeyEvent::LEFT;
                        break;
                    case SDLK_DOWN:
                        input = KeyEvent::DOWN;
                        break;
                    case SDLK_UP:
                        input = KeyEvent::UP;
                        break;
                    case SDLK_z:
                        input = KeyEvent::z;
                        break;
                    case SDLK_q:
                        input = KeyEvent::q;
                        break;
                    case SDLK_s:
                        input = KeyEvent::s;
                        break;
                    case SDLK_d:
                        input = KeyEvent::d;
                        break;
                }
            }
        }
        return input;
    }

    extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
        return new SDLGraphicLibrary(parameters);
    }
}