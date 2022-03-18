/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** vulkan_game_library
*/

#include "vulkan_game_library.hpp"

namespace arcade {

std::string VulkanGameLibrary::getName() const {
    return "Vulkan";
}

extern "C" GameLibrary *create() {
    return new VulkanGameLibrary();
}

}