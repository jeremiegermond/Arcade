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
#include "exception.hpp"
#include <vector>
#include <memory>

namespace arcade {

struct sdlTextObject : public object {
    SDL_Rect sdlMessageRect;
    SDL_Texture *sdlTexture;
    SDL_Surface *sdlSurface;

    sdlTextObject(const object &obj) : object(obj) {}
};


class SDLGraphicLibrary : public GraphicLibrary {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        std::vector<sdlTextObject> textObjects;
        TTF_Font *Sans;
        SDL_Color textColor;

    public:
        SDLGraphicLibrary(const Parameters &parameters);
        ~SDLGraphicLibrary() override;

        void createWindow() override;
        std::string getName() const override;
        void closeWindow() override;
        void loadObjects(std::vector<object> gameObjects) override;
        void loop() override;
        void initTextObjects(object &gameObject);

};

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters);

}