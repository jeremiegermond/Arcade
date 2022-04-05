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
#include <map>

namespace arcade {
    class Score {
        public:
            Score();
            ~Score();

        protected:
        private:
            std::map<std::string, int> scoreMap;

        void addToScoreboard(std::string user, int score);
    };
}

#endif //ARCADE_SCORE_HPP
