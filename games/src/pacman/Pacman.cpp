/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "game_library.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace arcade {

Pacman::Pacman() : GameLibrary()
{
    std::cout << "PACMAN" << std::endl;
    std::ifstream mapfile("./assets/pacman.map");
    std::stringstream buffer;

    buffer << mapfile.rdbuf();
    map = buffer.str();
}

Pacman::~Pacman()
= default;

void Pacman::setGameObjects()
{
    gameText.text = "Pacman";
    *gameText.posX = 20;
    *gameText.posY = 0;
    gameText.type = Type::TEXT;
    gameObjects.push_back(gameText);
    readMap();
}

    void Pacman::updateGameObjects() {
        setDirection();
    }


    void Pacman::readMap() {
        int posX = 0;
        int posY = 0;
        int index = 0;

        for (auto &i : map) {
            posX++;
            if (i == '\n') {
                posX = 0;
                posY++;
                continue;
            }
            if (i == 'X') {
                initWall(posX, posY, index);
            } else if (i == 'O') {
                initPacman(posX, posY);
            } else if (i == 'P') {
                initPhantoms(posX, posY);
            }
            index++;
        }
    }

    void Pacman::initWall(int posX, int posY, int index) {
        object newWall;

        newWall.texturePath = "./assets/pacman_wall.png";
        newWall.chr = 'X';
        newWall.maxFrame = 2;
        newWall.type = Type::ENTITY;
        newWall.animX = 0;
        newWall.animY = 0;
        newWall.animW = 0;
        newWall.animH = 0;
        newWall.isAnimated = false;
        newWall.spriteW = 20;
        newWall.spriteH = 20;
        newWall.sizeH = 1;
        newWall.sizeW = 1;
        *newWall.rotation = 0;
        *newWall.posX = posX;
        *newWall.posY = posY;
        *newWall.mirrored = 0;

        walls.push_back(newWall);
        gameObjects.push_back(walls.back());
    }

    void Pacman::initPacman(int posX, int posY) {
        pacman.texturePath = "./assets/pacman.png";
        pacman.chr = 'O';
        pacman.maxFrame = 3;
        pacman.type = Type::ENTITY;
        pacman.animX = 0;
        pacman.animY = 0;
        pacman.animW = 20;
        pacman.animH = 0;
        pacman.isAnimated = true;
        pacman.spriteW = 20;
        pacman.spriteH = 20;
        pacman.sizeH = 1;
        pacman.sizeW = 1;
        *pacman.rotation = 180;
        *pacman.posX = posX;
        *pacman.posY = posY;
        *pacman.mirrored = 0;

        gameObjects.push_back(pacman);
    }

    void Pacman::initPhantoms(int posX, int posY) {
        static int phantom_nbr = 1;

        phantoms[phantom_nbr - 1].texturePath = "./assets/pacman.png";
        phantoms[phantom_nbr - 1].chr = 'P';
        phantoms[phantom_nbr - 1].maxFrame = 2;
        phantoms[phantom_nbr - 1].type = Type::ENTITY;
        phantoms[phantom_nbr - 1].animX = 120;
        phantoms[phantom_nbr - 1].animY = 80;
        phantoms[phantom_nbr - 1].animW = 20;
        phantoms[phantom_nbr - 1].animH = 0;
        phantoms[phantom_nbr - 1].isAnimated = true;
        phantoms[phantom_nbr - 1].spriteW = 20;
        phantoms[phantom_nbr - 1].spriteH = 20;
        phantoms[phantom_nbr - 1].sizeH = 1;
        phantoms[phantom_nbr - 1].sizeW = 1;
        *phantoms[phantom_nbr - 1].rotation = 0;
        *phantoms[phantom_nbr - 1].posX = posX;
        *phantoms[phantom_nbr - 1].posY = posY;
        *phantoms[phantom_nbr - 1].mirrored = 0;

        gameObjects.push_back(phantoms[phantom_nbr - 1]);
        phantom_nbr++;
    }

    void Pacman::handlePacmanMovement() {
//        if (*pacman.direction == Direction::UP && )
    }

    void Pacman::setDirection() {
        switch (event) {
            case KeyEvent::z:
                *pacman.direction = Direction::UP;
                break;
            case KeyEvent::q:
                *pacman.direction = Direction::LEFT;
                break;
            case KeyEvent::s:
                *pacman.direction = Direction::DOWN;
                break;
            case KeyEvent::d:
                *pacman.direction = Direction::RIGHT;
                break;
        }
    }

    bool Pacman::checkMovement(object entity, Direction direction) {
        if (direction == Direction::UP) {

        }
        return false;
    }

    extern "C" IGameLibrary* create_game() {
        return new Pacman();
    }

}