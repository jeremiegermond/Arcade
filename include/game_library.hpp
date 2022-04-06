/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** game_library
*/

#ifndef GAME_LIBRARY_HPP_
#define GAME_LIBRARY_HPP_

#include <memory>
#include <vector>
#include "object.hpp"
#include "IGameLibrary.hpp"

namespace arcade {

class GameLibrary : public IGameLibrary {
    protected:
        std::vector<object> gameObjects;
        object gameText;
        object scoreText;
        int score{};
        int lastScore;
        KeyEvent event;
        bool gameEnded{};
        void updateGameObjects() override {}
    public:
        GameLibrary() = default;
        ~GameLibrary() override = default;
        std::vector<object> getGameObjects() override { return this->gameObjects; }
        void setGameObjects() override {}
        void setKeyEvent(KeyEvent e) override { event = e; }
        int getLastScore() override { return lastScore; };
        bool hasGameEnded() override { return gameEnded; };
        std::string getSelectedGame() override { return "";};
        void setScoreVector(std::vector<std::pair<std::string, int>>) { };

};

}

#endif /* !GAME_LIBRARY_HPP_ */
