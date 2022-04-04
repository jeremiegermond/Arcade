/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "game_library.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

namespace arcade {

Pacman::Pacman() : GameLibrary(), pacmanSpeed(1), fantomsSpeed(1.1), initialFantomsSpeed(1.1), invicible(false), phantomSpawnX(0), phantomSpawnY(0), started(false), pacgumsNumber(0), totalPacgums(0), timeUpdate(20), timeInvicibility(10000)
{
    std::ifstream mapfile("./assets/pacman.map");
    std::stringstream ss;
    ss << mapfile.rdbuf();

    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);

    map = vstrings;
    mapfile.close();
}

Pacman::~Pacman()
= default;

void Pacman::setGameObjects()
{
    score = 0;
    *gameText.text = "Pacman";
    *gameText.posX = 0;
    *gameText.posY = 0;
    gameText.sizeW = 7;
    gameText.sizeH = 1;
    gameText.type = Type::TEXT;
    *scoreText.text = "Score : 0";
    *scoreText.posX = 0;
    *scoreText.posY = 4;
    scoreText.sizeW = 3;
    scoreText.sizeH = 1;
    scoreText.type = Type::TEXT;
    gameObjects.push_back(gameText);
    gameObjects.push_back(scoreText);
    readMap();
    chrono = NOW;
}

    void Pacman::updateGameObjects() {
        updateScore();
        setDirection();
        if (handleBeginOrEnd())
            return;
        if (updateByTime()) {
            handlePacmanMovement();
            handlePacgumColision();
            handlePhantomsMovement();
            handlePhantomColision();
            handleTeleportation();
            handleInvicibility();
            handleWin();
       }
    }

    void Pacman::readMap() {
        int posX = 0;
        int posY = 0;
        int index = 0;

        for (auto &lines : map) {
            for (auto &i: lines) {
                posX++;
                if (i == 'X') {
                    initWall(posX, posY, index);
                } else if (i == 'P' || i == 'M' || i == 'U' || i == 'L') {
                    if (i == 'U') {
                        phantomSpawnX = posX;
                        phantomSpawnY = posY;
                    }
                    initPhantoms(posX, posY, i);
                } else if (i == '.') {
                    pacgumsNumber++;
                    initPacgums(posX, posY);
                } else if (i == 'C') {
                    pacgumsNumber++;
                    initBigPacgums(posX, posY);
                } else if (i == 'O') {
                    initPacman(posX, posY);
                } else if (i == 't') {
                    initTeleporters(posX, posY);
                }
                index++;
            }
            posX = 0;
            posY++;
        }
        totalPacgums = pacgumsNumber;
    }

    void Pacman::initWall(int posX, int posY, int index) {
        object newWall;

        newWall.texturePath = "./assets/pacman_wall.png";
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

    void Pacman::initPacman(int posX, int posY) {
        pacman.texturePath = "./assets/pacman.png";
        pacman.chr = 'O';
        pacman.maxFrame = 3;
        pacman.type = Type::ENTITY;
        *pacman.animX = 0;
        *pacman.animY = 0;
        *pacman.animW = 20;
        *pacman.animH = 0;
        pacman.isAnimated = true;
        *pacman.spriteW = 20;
        *pacman.spriteH = 20;
        pacman.sizeH = 1;
        pacman.sizeW = 1;
        *pacman.rotation = 180;
        *pacman.posX = posX;
        *pacman.posY = posY;
        *pacman.mirrored = 0;

        gameObjects.push_back(pacman);
    }

    void Pacman::initPhantoms(int posX, int posY, char chr) {
        static int phantom_nbr = 0;

        phantoms[phantom_nbr].texturePath = "./assets/pacman.png";
        phantoms[phantom_nbr].chr = chr;
        phantoms[phantom_nbr].maxFrame = 2;
        phantoms[phantom_nbr].type = Type::ENTITY;
        *phantoms[phantom_nbr].animX = 120;
        *phantoms[phantom_nbr].animY = 80 + (phantom_nbr * 20);
        *phantoms[phantom_nbr].animW = 20;
        *phantoms[phantom_nbr].animH = 0;
        phantoms[phantom_nbr].isAnimated = true;
        *phantoms[phantom_nbr].spriteW = 20;
        *phantoms[phantom_nbr].spriteH = 20;
        phantoms[phantom_nbr].sizeH = 1;
        phantoms[phantom_nbr].sizeW = 1;
        *phantoms[phantom_nbr].rotation = 0;
        *phantoms[phantom_nbr].posX = posX;
        *phantoms[phantom_nbr].posY = posY;
        *phantoms[phantom_nbr].mirrored = 0;

        gameObjects.push_back(phantoms[phantom_nbr]);
        phantom_nbr++;
        if (phantom_nbr == 4)
            phantom_nbr = 0;
    }

    void Pacman::initPacgums(int posX, int posY) {
        object newPacgums;

        newPacgums.texturePath = "./assets/pacman.png";
        newPacgums.chr = '.';
        newPacgums.maxFrame = 0;
        newPacgums.type = Type::ENTITY;
        *newPacgums.animX = 60;
        *newPacgums.animY = 0;
        *newPacgums.animW = 0;
        *newPacgums.animH = 0;
        newPacgums.isAnimated = false;
        *newPacgums.spriteW = 20;
        *newPacgums.spriteH = 20;
        newPacgums.sizeH = 1;
        newPacgums.sizeW = 1;
        *newPacgums.rotation = 0;
        *newPacgums.posX = posX;
        *newPacgums.posY = posY;
        *newPacgums.mirrored = 0;
        *newPacgums.state = State::ALIVE;

        pacgums.push_back(newPacgums);
        gameObjects.push_back(pacgums.back());
    }

    void Pacman::initBigPacgums(int posX, int posY) {
        object newBigPacgums;

        newBigPacgums.texturePath = "./assets/pacman.png";
        newBigPacgums.chr = 'C';
        newBigPacgums.maxFrame = 0;
        newBigPacgums.type = Type::ENTITY;
        *newBigPacgums.animX = 60;
        *newBigPacgums.animY = 20;
        *newBigPacgums.animW = 0;
        *newBigPacgums.animH = 0;
        newBigPacgums.isAnimated = false;
        *newBigPacgums.spriteW = 20;
        *newBigPacgums.spriteH = 20;
        newBigPacgums.sizeH = 1;
        newBigPacgums.sizeW = 1;
        *newBigPacgums.rotation = 0;
        *newBigPacgums.posX = float (posX);
        *newBigPacgums.posY = float (posY);
        *newBigPacgums.mirrored = 0;
        *newBigPacgums.state = State::ALIVE;

        bigPacgums.push_back(newBigPacgums);
        gameObjects.push_back(bigPacgums.back());
    }

    void Pacman::initTeleporters(int posX, int posY) {
        static int nbr = 0;

        *teleporters[nbr].posX = posX;
        *teleporters[nbr].posY = posY;
        nbr++;
    }

    void Pacman::handlePacmanMovement() {
        checkMovement(pacman, pacmanSpeed);
    }

    void Pacman::setDirection() {
        switch (event) {
            case KeyEvent::UP:
                *pacman.bufferedDirection = Direction::UP;
                break;
            case KeyEvent::LEFT:
                *pacman.bufferedDirection = Direction::LEFT;
                break;
            case KeyEvent::DOWN:
                *pacman.bufferedDirection = Direction::DOWN;
                break;
            case KeyEvent::RIGHT:
                *pacman.bufferedDirection = Direction::RIGHT;
                break;
            default:
                break;
        }
        if (isInt(*pacman.posX) && isInt(*pacman.posY)) {
            *pacman.direction = *pacman.bufferedDirection;
            setPacmanRotation();
        }
    }

    bool Pacman::checkMovement(object &entity, float speed) {
        auto newPosX = *entity.posX;
        auto newPosY = *entity.posY;


        switch (*entity.direction) {
            case Direction::RIGHT:
                newPosX += .1 * speed;
                break;
            case Direction::DOWN:
                newPosY += .1 * speed;
                break;
            case Direction::UP:
                newPosY -= .1 * speed;
                break;
            case Direction::LEFT:
                newPosX -= .1 * speed;
                break;
        }
        if (checkColision(entity, speed)) {
            *entity.posX = newPosX;
            *entity.posY = newPosY;
            return true;
        }
        return false;
    }

    bool Pacman::updateByTime() {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(NOW - chrono).count() > timeUpdate) {
            chrono = NOW;
            return true;
        }
        return false;
    }

    bool Pacman::checkColision(object &entity, float speed) {
        float hitboxLocationX = *entity.posX;
        float hitboxLocationY = *entity.posY;

        switch (*entity.direction) {
            case Direction::RIGHT:
                hitboxLocationX += 1;
                break;
            case Direction::DOWN:
                hitboxLocationY += 1;
                break;
            case Direction::UP:
                hitboxLocationY -= .1;
                break;
            case Direction::LEFT:
                hitboxLocationX -= .1;
                break;
        }
        for (auto &i : walls) {
            if (int (*i.posX) == int (hitboxLocationX) && int (*i.posY) == int (hitboxLocationY)) {
                return false;
            }
        }
        return true;
    }

    bool Pacman::isInt(float val) {
        if (int (val * 10) == int (val) * 10) {
            return true;
        }
        return false;
    }

    void Pacman::setPacmanRotation() {
        switch (*pacman.direction) {
            case Direction::RIGHT:
                *pacman.rotation = 180;
                break;
            case Direction::DOWN:
                *pacman.rotation = 270;
                break;
            case Direction::UP:
                *pacman.rotation = 90;
                break;
            case Direction::LEFT:
                *pacman.rotation = 0;
                break;
        }
    }

    void Pacman::handlePacgumColision() {
        float hitboxLocationX = *pacman.posX;
        float hitboxLocationY = *pacman.posY;

        switch (*pacman.direction) {
            case Direction::RIGHT:
                hitboxLocationX += 1;
                break;
            case Direction::DOWN:
                hitboxLocationY += 1;
                break;
            case Direction::UP:
                hitboxLocationY -= .1;
                break;
            case Direction::LEFT:
                hitboxLocationX -= .1;
                break;
        }

        for (auto &i : pacgums) {
            if (int (*i.posX) == int (hitboxLocationX) && int (*i.posY) == int (hitboxLocationY) && *i.state == State::ALIVE) {
                pacgumsNumber--;
                score += 100;
                *i.state = State::NONE;
            }
        }
        for (auto &i : bigPacgums) {
            if (int (*i.posX) == int (hitboxLocationX) && int (*i.posY) == int (hitboxLocationY) && *i.state == State::ALIVE) {
                pacgumsNumber--;
                score += 1000;
                *i.state = State::NONE;
                chrono_invicibility = NOW;
                invicible = true;
                fantomsSpeed = 0.7;
            }
        }
    }

    void Pacman::handlePhantomsMovement() {
        for (auto &a : phantoms) {
            if (*a.state == State::DEAD) {
                handleDeadPhantom(a);
                continue;
            }
            if (!checkMovement(a, fantomsSpeed)) {
                setRandomDirection(a);
            }
        }
    }

    void Pacman::setRandomDirection(object &entity) {
        int random_value = std::rand() % 4;

        switch (random_value) {
            case 0:
                *entity.direction = Direction::UP;
                break;
            case 1:
                *entity.direction = Direction::LEFT;
                break;
            case 2:
                *entity.direction = Direction::RIGHT;
                break;
            case 3:
                *entity.direction = Direction::DOWN;
                break;
        }
    }

    void Pacman::handlePhantomColision() {
        for (auto &a : phantoms) {
            if (*a.state == State::DEAD)
                continue;
            if (int (*pacman.posX) == int (*a.posX) && int (*pacman.posY) == int (*a.posY)) {
                if (invicible) {
                    handlePacmanEatPhantom(a);
                } else {
                    score = 0;
                    gameEnd();
                }
            }
        }
    }

    void Pacman::gameEnd() {
        resetGame();
        started = false;
    }

    void Pacman::resetGame() {
        int posX = 0;
        int posY = 0;

        for (auto &lines : map) {
            for (auto &i: lines) {
                posX++;
                if (i == 'P' || i == 'M' || i == 'U' || i == 'L') {
                    resetPhantom(posX, posY);
                } else if (i == 'O') {
                    resetPacman(posX, posY);
                }
            }
            posX = 0;
            posY++;
        }
        resetPacgums();
    }

    void Pacman::resetPhantom(int posX, int posY) {
        static int nbr = 0;

        *phantoms[nbr].posX = posX;
        *phantoms[nbr].posY = posY;
        *phantoms[nbr].state = State::ALIVE;
        *phantoms[nbr].alpha = 255;

        nbr++;
        if (nbr == 4)
            nbr = 0;
    }

    void Pacman::resetPacman(int posX, int posY) {
        *pacman.posX = posX;
        *pacman.posY = posY;
        *pacman.state = State::ALIVE;
    }

    void Pacman::resetPacgums() {
        for (auto &i : pacgums) {
            *i.state = State::ALIVE;
        }
        for (auto &i : bigPacgums) {
            *i.state = State::ALIVE;
        }
    }

    void Pacman::handleTeleportation() {
        if (int (*pacman.posX) == int (*teleporters[0].posX) && int (*pacman.posY) == int (*teleporters[0].posY)) {
            *pacman.posX = *teleporters[1].posX - 1;
            *pacman.posY = *teleporters[1].posY;
        } else if (int (*pacman.posX) == int (*teleporters[1].posX) && int (*pacman.posY) == int (*teleporters[1].posY)) {
            *pacman.posX = *teleporters[0].posX + 1;
            *pacman.posY = *teleporters[0].posY;
        }
    }

    void Pacman::handleInvicibility() {
        if (invicible) {
            if (std::chrono::duration_cast<std::chrono::milliseconds>(NOW - chrono_invicibility).count() > timeInvicibility) {
                invicible = false;
                fantomsSpeed = initialFantomsSpeed;
            }
        }
    }

    void Pacman::handlePacmanEatPhantom(object &i) {
        *i.alpha = 50;
        *i.state = State::DEAD;
    }

    void Pacman::handleDeadPhantom(object &i) {
        if (int (*i.posX) == int (phantomSpawnX) && int (*i.posY) == int (phantomSpawnY)) {
            *i.alpha = 255;
            *i.state = State::ALIVE;
            return;
        }
        if (*i.posX > phantomSpawnX && int (*i.posX) != int (phantomSpawnX)) {
            *i.posX -= .1;
        } else if (int (*i.posX) != int (phantomSpawnX)) {
            *i.posX += .1;
        }
        if (*i.posY > phantomSpawnY && int (*i.posY) != int (phantomSpawnY)) {
            *i.posY -= .1;
        } else if (int (*i.posY) != int (phantomSpawnY)) {
            *i.posY += .1;
        }
    }

    void Pacman::updateScore() {
        *scoreText.text = "Score : " + std::to_string(score);
    }

    bool Pacman::handleBeginOrEnd() {
        if (!started) {
            *gameText.text = "Press any key to start";
            if (event != KeyEvent::NONE) {
                started = true;
                *gameText.text = "Pacman";
            }
            return true;
        } else {
            return false;
        }
    }

    void Pacman::handleWin() {
        if (pacgumsNumber == 0) {
            resetGame();
            started = false;
            pacgumsNumber = totalPacgums;
            initialFantomsSpeed += .2;
            fantomsSpeed += .2;
        }
    }

    extern "C" IGameLibrary* create_game() {
        return new Pacman();
    }

}