/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "game_library.hpp"

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

void Nibbler::setGameObjects()
{
    score = 0;
    *gameText.text = "Nibbler";
    *gameText.posX = 30;
    *gameText.posY = 0;
    gameText.sizeW = 7;
    gameText.sizeH = 1;
    gameText.type = Type::TEXT;
//    *scoreText.text = "Score : 0";
//    *scoreText.posX = 30;
//    *scoreText.posY = 4;
//    scoreText.sizeW = 3;
//    scoreText.sizeH = 1;
//    scoreText.type = Type::TEXT;
    gameObjects.push_back(gameText);
//    gameObjects.push_back(scoreText);
//    readMap();
//    chrono = NOW;
}

void Nibbler::updateGameObjects() {
//    updateScore();
//    setDirection();
//    if (handleBeginOrEnd())
//        return;
//    if (updateByTime()) {
//        handleNibblerMovement();
//        handleAppleColision();
//        handleWin();
//   }
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
            }
//            else if (i == 'A') {
//                applesNumber++;
//                initApples(posX, posY);
//            } else if (i == 'N') {
//                initNibbler(posX, posY);
//                index++;
//            } else if (i == 'C') {
//                initNibbler(posX, posY);
//                index++;
//            }
            posX = 0;
            posY++;
        }
        totalApples = applesNumber;
    }
}

void Nibbler::initWall(int posX, int posY, int index)
{
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

void Nibbler::initNibbler(int posX, int posY)
{
    nibbler.texturePath = "./assets/nibbler.png";
    nibbler.chr = 'O';
    nibbler.maxFrame = 3;
    nibbler.type = Type::ENTITY;
    *nibbler.animX = 0;
    *nibbler.animY = 0;
    *nibbler.animW = 20;
    *nibbler.animH = 0;
    nibbler.isAnimated = true;
    *nibbler.spriteW = 20;
    *nibbler.spriteH = 20;
    nibbler.sizeH = 1;
    nibbler.sizeW = 1;
    *nibbler.rotation = 180;
    *nibbler.posX = posX;
    *nibbler.posY = posY;
    *nibbler.mirrored = 0;

    gameObjects.push_back(nibbler);
}

void Nibbler::initApples(int posX, int posY)
{
    object newApples;
    newApples.texturePath = "./assets/nibbler.png";
    newApples.chr = 'A';

    apples.push_back(newApples);
    gameObjects.push_back(apples.back());
}

void Nibbler::handleNibblerMovement()
{
    checkMovement(nibbler, nibblerSpeed);
}

void Nibbler::setDirection()
{
    switch (event) {
        case KeyEvent::UP:
            *nibbler.bufferedDirection = Direction::UP;
            break;
        case KeyEvent::LEFT:
            *nibbler.bufferedDirection = Direction::LEFT;
            break;
        case KeyEvent::DOWN:
            *nibbler.bufferedDirection = Direction::DOWN;
            break;
        case KeyEvent::RIGHT:
            *nibbler.bufferedDirection = Direction::RIGHT;
            break;
        default:
            break;
    }
    if (isInt(*nibbler.posX) && isInt(*nibbler.posY)) {
        *nibbler.direction = *nibbler.bufferedDirection;
        setNibblerRotation();
    }
}

bool Nibbler::checkMovement(object &entity, float speed)
{
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

bool Nibbler::updateByTime()
{
    if (std::chrono::duration_cast<std::chrono::milliseconds>(NOW - chrono).count() > timeUpdate) {
        chrono = NOW;
        return true;
    }
    return false;
}

bool Nibbler::checkColision(object &entity, float speed)
{
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

bool Nibbler::isInt(float val)
{
    if (int (val * 10) == int (val) * 10) {
        return true;
    }
    return false;
}

void Nibbler::setNibblerRotation()
{
    switch (*nibbler.direction) {
        case Direction::RIGHT:
            *nibbler.rotation = 180;
            break;
        case Direction::DOWN:
            *nibbler.rotation = 270;
            break;
        case Direction::UP:
            *nibbler.rotation = 90;
            break;
        case Direction::LEFT:
            *nibbler.rotation = 0;
            break;
    }
}

void Nibbler::handleAppleColision() {
    float hitboxLocationX = *nibbler.posX;
    float hitboxLocationY = *nibbler.posY;

    switch (*nibbler.direction) {
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

    for (auto &i : apples) {
        if (int (*i.posX) == int (hitboxLocationX) && int (*i.posY) == int (hitboxLocationY) && *i.state == State::ALIVE) {
            applesNumber--;
            score += 100;
            lastScore = score;
            *i.state = State::NONE;
        }
    }
}

void Nibbler::gameEnd()
{
    resetGame();
    started = false;
}

void Nibbler::resetGame()
{
    int posX = 0;
    int posY = 0;

    for (auto &lines : map) {
        for (auto &i: lines) {
            posX++;
            if (i == 'N') {
                resetNibbler(posX, posY);
            }
        }
        posX = 0;
        posY++;
    }
    resetApples();
}

void Nibbler::resetNibbler(int posX, int posY)
{
    *nibbler.posX = posX;
    *nibbler.posY = posY;
    *nibbler.state = State::ALIVE;
}

void Nibbler::resetApples()
{
    for (auto &i : apples) {
        *i.state = State::ALIVE;
    }
}

void Nibbler::updateScore()
{
    *scoreText.text = "Score : " + std::to_string(score);
}

bool Nibbler::handleBeginOrEnd()
{
    bool started = true;
    
    if (!started) {
        *gameText.text = "Press any key to start";
        if (event != KeyEvent::NONE) {
            started = true;
            *gameText.text = "Nibbler";
        }
        return true;
    } else {
        return false;
    }
}

void Nibbler::handleWin() {
    if (applesNumber == 0) {
        resetGame();
        started = false;
        applesNumber = totalApples;
    }
}

    
extern "C" IGameLibrary* create_game() {
    return new Nibbler();
}

}