/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Menu.hpp
*/

#ifndef ARCADE_MENU_HPP
#define ARCADE_MENU_HPP

#include "game_library.hpp"

namespace arcade {

class Menu : public GameLibrary {
public:
    Menu();
    ~Menu();
    void setGameObjects() override;
    void updateGameObjects() override;
    std::string getSelectedGame();

protected:

private:
    std::string gameSelected;
    object gameSelectedText;
    object tooltipText;
    object highScoresText;

    void handleChangeGame();
};
}

#endif //ARCADE_MENU_HPP
