/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

namespace arcade {
    Menu::Menu() {
    }

    Menu::~Menu() {
    }

    void Menu::setGameObjects() {
        std::string scorestring;


        gameSelected = "pacman";
        *gameText.text = "Menu";
        *gameText.posX = 30;
        *gameText.posY = 0;
        gameText.sizeW = 7;
        gameText.sizeH = 1;
        gameText.type = Type::TEXT;
        gameObjects.push_back(gameText);
        *gameSelectedText.text = "< " + gameSelected + " >";
        *gameSelectedText.posX = 17;
        *gameSelectedText.posY = 10;
        gameSelectedText.sizeW = 7;
        gameSelectedText.sizeH = 2;
        gameSelectedText.type = Type::TEXT;
        gameObjects.push_back(gameSelectedText);
        *tooltipText.text = "Press right or left to change game.";
        *tooltipText.posX = 13.5;
        *tooltipText.posY = 5;
        tooltipText.sizeW = 15;
        tooltipText.sizeH = 2;
        tooltipText.type = Type::TEXT;
        gameObjects.push_back(tooltipText);
    }

    void Menu::updateGameObjects() {
        handleChangeGame();
        *gameSelectedText.text = "< " + gameSelected + " >";
    }

    void Menu::handleChangeGame() {
        if (event == KeyEvent::RIGHT) {
            if (gameSelected == "pacman") {
                gameSelected = "nibbler";
            } else if (gameSelected == "nibbler") {
                gameSelected = "pacman";
            }
        }
        if (event == KeyEvent::LEFT) {
            if (gameSelected == "pacman") {
                gameSelected = "nibbler";
            } else if (gameSelected == "nibbler") {
                gameSelected = "pacman";
            }
        }
    }

    std::string Menu::getSelectedGame() {
        return gameSelected;
    }


    void Menu::setScoreVector(std::vector<std::pair<std::string, int>> score) {
        scoreBoard = score;
    }

    extern "C" IGameLibrary* create_game() {
        return new Menu();
    }
}