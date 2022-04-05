/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "game_library.hpp"
#include <fstream>
#include <iterator>
#include <sstream>

namespace arcade {
Nibbler::Nibbler() : GameLibrary()
{
    std::ifstream mapfile("./assets/nibbler.map");
    std::stringstream ss;
    ss << mapfile.rdbuf();

    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);

    map = vstrings;
    mapfile.close();
}

    void Nibbler::readMap() {
        int posX = 0;
        int posY = 0;
        int index = 0;

        for (auto &lines: map) {
            for (auto &i: lines) {
                posX++;
                if (i == 'X') {
                    initWall(posX, posY, index);
                } else if (i == 'A') {
                    applesNumber++;
                    initApples(posX, posY);
                } else if (i == 'N') { // Tête du Snake doit être différente du corps
                    initNibbler(posX, posY);
                    index++;
                } else if (i == 'C') { // Coprs du Snake + le snake doit être de 4 au début (3 corps + 1 tête dcp)
                    initNibbler(posX, posY);
                    index++;
                }
                posX = 0;
                posY++;
            }
            totalApples = applesNumber;
        }
    }
    void Nibbler::initWall(int posX, int posY, int index) {
        object newWall;
        newWall.texturePath = "./assets/nibbler.png";
        newWall.chr = 'X';
        newWall.maxFrame = 2;
        newWall.type = Type::ENTITY;
        *newWall.animX = 0;
        *newWall.animY = 0;
        *newWall.animW = 0;
        *newWall.animH = 0;
        newWall.isAnimated = false;
        *newWall.spriteW = 20;
        *newWall.spriteH = 20;
        newWall.sizeH = 1;
        newWall.sizeW = 1;
        *newWall.rotation = 0;
        *newWall.posX = posX;
        *newWall.posY = posY;
        *newWall.mirrored = 0;

        walls.push_back(newWall);
        gameObjects.push_back(walls.back());
    }

    void Nibbler::initNibbler(int posX, int posY) {
        nibbler.texturePath = "./assets/nibbler.png";

        gameObjects.push_back(nibbler);
    }

    void Nibbler::initApples(int posX, int posY) {
        object newApples;
        newApples.texturePath = "./assets/nibbler.png";
        newApples.chr = 'A';

        apples.push_back(newApples);
        gameObjects.push_back(apples.back());
    }
}