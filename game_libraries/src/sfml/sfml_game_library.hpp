/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** sfml_game_library
*/

#ifndef SFML_GAME_LIBRARY_HPP_
#define SFML_GAME_LIBRARY_HPP_

#include "graphic_library.hpp"
#include "exception.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>

namespace arcade {

class SFMLGraphicLibrary : public GraphicLibrary {
    private:
        sf::RenderWindow window;

        KeyEvent handleInputs();
    public:
        SFMLGraphicLibrary(const Parameters &parameters);
        ~SFMLGraphicLibrary() override;

        void createWindow() override;
        void closeWindow() override;
        void loadObjects(std::vector<object> gameObjects) override;
        KeyEvent loop() override;
};

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters);

}

#endif /* !SFML_GAME_LIBRARY_HPP_ */
