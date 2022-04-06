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

struct sfmlObject : public object {
    sf::RectangleShape rectangle{};

    sfmlObject(const object &obj) : object(obj) {}
};


class SFMLGraphicLibrary : public GraphicLibrary {
    private:
        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Font font;
        sf::Text text;
        int sizeUnit;

        std::vector<sfmlObject> textObjects;
        std::vector<sfmlObject> entityObjects;

        void initTextObjects(object &gameObject);
        void initEntityObjects(object &gameObject);
        void drawTextObject() override;
        void drawEntityObject() override;
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
