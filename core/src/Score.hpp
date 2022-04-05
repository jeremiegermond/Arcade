/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Score.hpp
*/

#ifndef ARCADE_SCORE_HPP
#define ARCADE_SCORE_HPP

#include <ostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "exception.hpp"

namespace arcade {
class Score {
    public:
        Score();
        ~Score();

        void addToScoreboard(const std::string& user, int score);
        [[nodiscard]] std::vector<std::pair<std::string, int>> getScoreBoard() const;
    protected:
    private:
        std::vector<std::pair<std::string, int>> scoreMap;

        void writeScoreboard();
};
}

#endif //ARCADE_SCORE_HPP
