/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "graphic_library.hpp"
#include "game_library.hpp"
#include <memory>
#include <iostream>
#include <array>

namespace arcade {

class Pacman : public GameLibrary {
    private:
        void setGameObjects() override;
        void updateGameObjects() override;
        object pacman;
        std::array<object, 4> phantoms;
    public:
        Pacman();
        ~Pacman() = default;
};

}

#endif /* !PACMAN_HPP_ */
