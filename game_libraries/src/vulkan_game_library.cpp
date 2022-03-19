/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** vulkan_game_library
*/

#include "vulkan_game_library.hpp"

namespace arcade {

VulkanGameLibrary::VulkanGameLibrary(const Parameters &parameters) : GameLibrary(parameters) {}

std::string VulkanGameLibrary::getName() const {
    return "Vulkan";
}

extern "C" GameLibrary *create(const GameLibrary::Parameters &parameters) {
    return new VulkanGameLibrary(parameters);
}

}