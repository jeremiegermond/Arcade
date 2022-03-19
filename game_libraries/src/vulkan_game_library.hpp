/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** vulkan_game_library
*/

#pragma once

#include "game_library.hpp"

namespace arcade {

class VulkanGameLibrary : public GameLibrary {
    public:
        VulkanGameLibrary(const Parameters &parameters);
        void createWindow() {}
        std::string getName() const override;
};

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters);

}