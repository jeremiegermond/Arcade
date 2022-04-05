/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Score.cpp
*/

#include "Score.hpp"

namespace arcade {

bool compPair(std::pair<std::string, int> a, std::pair<std::string, int> b) {
    return a.second > b.second;
}

Score::Score() {
    {
        std::ofstream scoreBoard("scoreboard.txt");
    }
    std::fstream scoreBoard("scoreboard.txt", std::ios::in | std::ios::out);
    std::stringstream tmp_line;
    std::string tmp;
    std::string user;
    std::string score;

    if (!scoreBoard.is_open())
        throw Exception("Cannot open score file.");

    while (!scoreBoard.eof()) {
        std::getline(scoreBoard, tmp, '\n');
        tmp_line << tmp;
        tmp_line >> user;
        tmp_line >> score;
        if (user.empty() || score.empty())
            break;
        addToScoreboard(user, std::stoi(score));
        user.clear();
        score.clear();
        tmp_line.str("");
        tmp_line.clear();
    }
    scoreBoard.close();
}

Score::~Score() {
    writeScoreboard();
}

void Score::addToScoreboard(const std::string& user, int score) {
    scoreMap.emplace_back(user, score);
    std::sort(scoreMap.begin(), scoreMap.end(), compPair);
}

void Score::writeScoreboard() {
    std::ofstream scoreBoard("scoreboard.txt");

    if (scoreBoard.is_open()) {
        for (auto &i : scoreMap) {
            scoreBoard << i.first << " " << i.second << "\n";
        }
        scoreBoard.close();
    }
}

std::vector<std::pair<std::string, int>> Score::getScoreBoard() const {
    return scoreMap;
}

}