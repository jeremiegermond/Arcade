/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "game_library.hpp"

namespace arcade {

Nibbler::Nibbler() : GameLibrary(), nibblerSpeed(1), started(false), timeUpdate(300)
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
    gameObjects.clear();
    nibbler_tail.clear();
    started = false;
    score = 0;
    *gameText.text = "Nibbler";
    *gameText.posX = 30;
    *gameText.posY = 0;
    gameText.sizeW = 7;
    gameText.sizeH = 1;
    gameText.type = Type::TEXT;
    *scoreText.text = "Score : 0";
    *scoreText.posX = 30;
    *scoreText.posY = 4;
    scoreText.sizeW = 3;
    scoreText.sizeH = 1;
    scoreText.type = Type::TEXT;
    gameObjects.push_back(gameText);
    gameObjects.push_back(scoreText);
    readMap();
    chrono = NOW;
}

void Nibbler::updateGameObjects() {
    updateScore();
    setDirection();
    if (handleBeginOrEnd())
        return;
    if (updateByTime()) {
        handleNibblerMovement();
        handleAppleColision();
        handleWin();
   }
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
            else if (i == 'A') {
                applesNumber++;
                initApples(posX, posY);
            }
            else if (i == 'N') {
                initNibbler(posX, posY);
                index++;
            }
        }
        posX = 0;
        posY++;
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
    *newWall.spriteW = 15;
    *newWall.spriteH = 15;
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
    nibbler.texturePath = "./assets/nibbler_snake.png";
    nibbler.chr = 'C';
    nibbler.maxFrame = 3;
    nibbler.type = Type::ENTITY;
    *nibbler.animX = 0;
    *nibbler.animY = 0;
    *nibbler.animW = 0;
    *nibbler.animH = 0;
    nibbler.isAnimated = false;
    *nibbler.spriteW = 20;
    *nibbler.spriteH = 20;
    nibbler.sizeH = 1;
    nibbler.sizeW = 1;
    *nibbler.rotation = 180;
    *nibbler.posX = posX;
    *nibbler.posY = posY;
    *nibbler.mirrored = 0;

    for (int i = 0; i < 200; i++) {
        object niblerTail;

        niblerTail.texturePath = "./assets/nibbler_snake.png";
        niblerTail.chr = 'C';
        niblerTail.maxFrame = 3;
        niblerTail.type = Type::ENTITY;
        if (i > 4)
            *niblerTail.state = State::NONE;
        *niblerTail.animX = 0;
        *niblerTail.animY = 0;
        *niblerTail.animW = 0;
        *niblerTail.animH = 0;
        niblerTail.isAnimated = false;
        *niblerTail.spriteW = 20;
        *niblerTail.spriteH = 20;
        niblerTail.sizeH = 1;
        niblerTail.sizeW = 1;
        *niblerTail.rotation = 0;
        *niblerTail.posX = posX - i;
        *niblerTail.posY = posY;
        *niblerTail.mirrored = 0;
        nibbler_tail.push_back(niblerTail);
        gameObjects.push_back(niblerTail);
    }
    gameObjects.push_back(nibbler);
}

void Nibbler::initApples(int posX, int posY)
{
    object newApples;
    newApples.texturePath = "./assets/apple.png";
    newApples.chr = 'P';
    newApples.maxFrame = 3;
    newApples.type = Type::ENTITY;
    *newApples.animX = 0;
    *newApples.animY = 0;
    *newApples.animW = 0;
    *newApples.animH = 0;
    newApples.isAnimated = true;
    *newApples.spriteW = 1184;
    *newApples.spriteH = 1184;
    newApples.sizeH = 1;
    newApples.sizeW = 1;
    *newApples.rotation = 0;
    *newApples.posX = posX;
    *newApples.posY = posY;
    *newApples.mirrored = 0;

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
            if (*nibbler.direction != Direction::DOWN)
                *nibbler.bufferedDirection = Direction::UP;
            break;
        case KeyEvent::LEFT:
            if (*nibbler.direction != Direction::RIGHT)
                *nibbler.bufferedDirection = Direction::LEFT;
            break;
        case KeyEvent::DOWN:
            if (*nibbler.direction != Direction::UP)
                *nibbler.bufferedDirection = Direction::DOWN;
            break;
        case KeyEvent::RIGHT:
            if (*nibbler.direction != Direction::LEFT)
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
            newPosX += 1 * speed;
            break;
        case Direction::DOWN:
            newPosY += 1 * speed;
            break;
        case Direction::UP:
            newPosY -= 1 * speed;
            break;
        case Direction::LEFT:
            newPosX -= 1 * speed;
            break;
    }
    if (checkColision(entity, speed)) {
        *nibbler_tail[0].posX = *entity.posX;
        *nibbler_tail[0].posY = *entity.posY;
        for (int i = 199; i >= 1; i--) {
            *nibbler_tail[i].posX = *nibbler_tail[i - 1].posX;
            *nibbler_tail[i].posY = *nibbler_tail[i - 1].posY;
        }
        *entity.posX = newPosX;
        *entity.posY = newPosY;


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
            gameEnded = true;
            lastScore = score;
            score = 0;
            gameEnd();
            return false;
        }
    }
    for (auto &i : nibbler_tail) {
        if (int (*i.posX) == int (hitboxLocationX) && int (*i.posY) == int (hitboxLocationY) && *i.state == State::ALIVE) {
            gameEnded = true;
            lastScore = score;
            score = 0;
            gameEnd();
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
    for (auto &i : apples) {
        if (int (*i.posX) == int (*nibbler.posX) && int (*i.posY) == int (*nibbler.posY) && *i.state == State::ALIVE) {
            for (auto &i : nibbler_tail) {
                if (*i.state == State::NONE) {
                    *i.state = State::ALIVE;
                    break;
                }
            }
            applesNumber--;
            score += 100;
            lastScore = score;
            *i.posX = (std::rand() % 16) + 10;
            *i.posY = std::rand() % 17;
            for (auto &a : walls) {
                while (*i.posX == *a.posX && *i.posY == *a.posY) {
                    *i.posX = (std::rand() % 16) + 10;
                    *i.posY = std::rand() % 17;
                }
            }
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
            if (i == 'A') {
                resetApples(posX, posY);
            }
        }
        posX = 0;
        posY++;
    }
    for (int i = 0; i < 200; i++) {
        if (i > 4)
            *nibbler_tail[i].state = State::NONE;
        else
            *nibbler_tail[i].state = State::ALIVE;
        *nibbler_tail[i].posX = *nibbler.posX - i;
        *nibbler_tail[i].posY = *nibbler.posY;
    }
}

void Nibbler::resetNibbler(int posX, int posY)
{
    *nibbler.posX = posX;
    *nibbler.posY = posY;
    *nibbler.state = State::ALIVE;
}

void Nibbler::updateScore()
{
    gameEnded = false;
    *scoreText.text = "Score : " + std::to_string(score);
}

bool Nibbler::handleBeginOrEnd()
{
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

    void Nibbler::resetApples(int posX, int posY) {
        static int i = 0;

        *apples[i].posX = posX;
        *apples[i].posY = posY;
        i++;
        if (i == 3)
            i = 0;
    }


    extern "C" IGameLibrary* create_game() {
    return new Nibbler();
}

}