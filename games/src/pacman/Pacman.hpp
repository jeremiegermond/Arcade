/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-marine.poteau
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../../game_libraries/src/graphic_library.hpp"
#include "../game_library.hpp"
#include <memory>

namespace arcade {

class Pacman : public GameLibrary {
    public:
        Pacman();
        ~Pacman() override;

    protected:
    private:
        void setGameObjects() override;
        void updateGameObjects() override;
        std::shared_ptr<arcade::object> pacman;
        std::shared_ptr<arcade::object> phantoms1;
        std::shared_ptr<arcade::object> phantoms2;
        std::shared_ptr<arcade::object> phantoms3;
        std::shared_ptr<arcade::object> phantoms4;

};

}

#endif /* !PACMAN_HPP_ */
