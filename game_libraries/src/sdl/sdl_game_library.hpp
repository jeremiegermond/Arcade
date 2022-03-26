/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** sdl_game_library
*/

#pragma once

#include "graphic_library.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "exception.hpp"
#include <vector>
#include <memory>

namespace arcade {

struct sdlObject : public arcade::object {
    SDL_Rect sdlDstRect{};
    SDL_Rect sdlSrcRect{};
    SDL_Texture *sdlTexture{};
    SDL_Surface *sdlSurface{};

    sdlObject(const object &obj) : object(obj) {}
};


class SDLGraphicLibrary : public GraphicLibrary {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        std::vector<sdlObject> textObjects;
        std::vector<sdlObject> entityObjects;
        TTF_Font *Sans;
        SDL_Color textColor;
        bool started;
        unsigned int lastTime;

        void initTextObjects(object &gameObject);
        void initEntityObjects(object &gameObject);
        void animateEntityObject();
    public:
        SDLGraphicLibrary(const Parameters &parameters);
        ~SDLGraphicLibrary() override;

        void createWindow() override;
        std::string getName() const override;
        void closeWindow() override;
        void loadObjects(std::vector<object> gameObjects) override;
        void loop() override;

};

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters);

}