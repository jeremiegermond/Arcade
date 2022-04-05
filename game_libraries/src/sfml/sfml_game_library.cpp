/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** sfml_game_library
*/

#include "sfml_game_library.hpp"
#include <iostream>

namespace arcade {

SFMLGraphicLibrary::SFMLGraphicLibrary(const Parameters &parameters) : GraphicLibrary(parameters, "sfml") {}

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
    this->window.draw(sf::CircleShape(50));
    this->window.display();

    return handleInputs();
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
        }
    }
    return input;
}

extern "C" GraphicLibrary *create(const GraphicLibrary::Parameters &parameters) {
    return new SFMLGraphicLibrary(parameters);
}

}