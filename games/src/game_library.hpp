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

class GameLibrary : public arcade::IGameLibrary {
    public:
        GameLibrary();
        ~GameLibrary() override;
        std::vector<std::shared_ptr<arcade::object>> getGameObjects() override;
        void setGameObjects() override;

    protected:
        std::vector<std::shared_ptr<arcade::object>> _game_objects;
        arcade::object game_text;

        virtual void updateGameObjects();
    private:
};

}

#endif /* !GAME_LIBRARY_HPP_ */
