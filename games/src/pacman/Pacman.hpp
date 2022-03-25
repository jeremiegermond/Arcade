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

namespace arcade {

class Pacman : public GameLibrary {
    public:
        Pacman();
        ~Pacman() = default;
    private:
        void setGameObjects() override;
        void updateGameObjects() override;
        std::unique_ptr<object> pacman;
        std::unique_ptr<object> phantoms1;
        std::unique_ptr<object> phantoms2;
        std::unique_ptr<object> phantoms3;
        std::unique_ptr<object> phantoms4;

};

}

#endif /* !PACMAN_HPP_ */
