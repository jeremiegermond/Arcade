/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Score.cpp
*/

#include "Score.hpp"

namespace arcade {
    Score::Score() {
        std::ifstream scoreBoard("scoreboard.txt");
        std::stringstream tmp_line;
        std::string tmp;
        std::string user;
        std::string score;

        while (!scoreBoard.eof()) {
            std::getline(scoreBoard, tmp, '\n');
            tmp_line << tmp;
            tmp_line >> user;
            tmp_line >> score;
            addToScoreboard(user, std::stoi(score));
            tmp_line.str("");
            tmp_line.clear();
        }
    }

    Score::~Score() {
    }

    void Score::addToScoreboard(std::string user, int score) {
        scoreMap.insert({user, score});
    }
}