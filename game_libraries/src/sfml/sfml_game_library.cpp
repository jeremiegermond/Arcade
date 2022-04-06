/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** sfml_game_library
*/

#include "sfml_game_library.hpp"
#include <iostream>

namespace arcade {

SFMLGraphicLibrary::SFMLGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters, "sfml"), sizeUnit(40) {}

SFMLGraphicLibrary::~SFMLGraphicLibrary() {
    closeWindow();
}

void SFMLGraphicLibrary::closeWindow() {
    this->window.close();
}

void SFMLGraphicLibrary::createWindow() {
    this->window.create(
        sf::VideoMode(this->parameters.window.width, this->parameters.window.height), 
        this->parameters.window.title, 
        sf::Style::Resize | sf::Style::Close
    );
    window.setFramerateLimit(60);
}

KeyEvent SFMLGraphicLibrary::loop() {
    this->window.clear();
    drawTextObject();
    drawEntityObject();
    this->window.display();

    return handleInputs();
}

void SFMLGraphicLibrary::loadObjects(std::vector<object> gameObjects) {
    entityObjects.clear();
    textObjects.clear();
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

void SFMLGraphicLibrary::initTextObjects(object &gameObject) {
    sfmlObject castedObject(gameObject);

    textObjects.push_back(castedObject);
}

void SFMLGraphicLibrary::initEntityObjects(object &gameObject) {
    sfmlObject castedObject(gameObject);

    castedObject.rectangle = sf::RectangleShape(sf::Vector2f(sizeUnit, sizeUnit));
    entityObjects.push_back(castedObject);
}

void SFMLGraphicLibrary::drawTextObject() {
    this->font.loadFromFile("assets/Sans.ttf");

    for (auto &i : textObjects) {
        sf::Text text(i.text->c_str(), font);
        text.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
        text.setCharacterSize(24);
	    this->window.draw(text);
    }
}

void SFMLGraphicLibrary::drawEntityObject() {
    for (auto &i: entityObjects) {
            if (*i.state == State::NONE)
                continue;
            switch (i.chr) {
                case 'X':
                    i.rectangle.setFillColor(sf::Color(0, 0, 255, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'C':
                    i.rectangle.setFillColor(sf::Color(0, 255, 0, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'N':
                    i.rectangle.setFillColor(sf::Color(0, 255, 0, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'O':
                    i.rectangle.setFillColor(sf::Color(255, 255, 0, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'P':
                    i.rectangle.setFillColor(sf::Color(255, 0, 0, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'M':
                    i.rectangle.setFillColor(sf::Color(255, 0, 255, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'U':
                    i.rectangle.setFillColor(sf::Color(0, 255, 255, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case 'L':
                    i.rectangle.setFillColor(sf::Color(255, 255, 255, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit, *i.posY * sizeUnit);
                    this->window.draw(i.rectangle);
                    break;
                case '.':
                    i.rectangle.setSize(sf::Vector2f(10, 10));
                    i.rectangle.setFillColor(sf::Color(255, 255, 255, *i.alpha));
                    i.rectangle.setPosition(*i.posX * sizeUnit + 15, *i.posY * sizeUnit + 15);
                    this->window.draw(i.rectangle);
                    break;
                default:
                    break;
            }
        }
}

KeyEvent SFMLGraphicLibrary::handleInputs() {
    sf::Event event;
    KeyEvent input = KeyEvent::NONE;

    while (this->window.pollEvent(event)){
        if (event.type == sf::Event::Closed) {
            closeWindow();
            std::exit(0);
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                input = KeyEvent::ESCAPE;
                break;
            }
            if (event.key.code == sf::Keyboard::Up) {
                input = KeyEvent::UP;
                break; 
            }
            if (event.key.code == sf::Keyboard::Down) {
                input = KeyEvent::DOWN;
                break; 
            }
            if (event.key.code == sf::Keyboard::Left) {
                input = KeyEvent::LEFT;
                break; 
            }
            if (event.key.code == sf::Keyboard::Right) {
                input = KeyEvent::RIGHT;
                break; 
            }
            if (event.key.code == sf::Keyboard::D) {
                input = KeyEvent::d;
                break; 
            }
            if (event.key.code == sf::Keyboard::S) {
                input = KeyEvent::s;
                break; 
            }
            if (event.key.code == sf::Keyboard::Q) {
                input = KeyEvent::q;
                break; 
            }
        }
    }
    return input;
}

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new SFMLGraphicLibrary(parameters);
}

}