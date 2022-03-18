/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade
** File description:
** exception
*/

#pragma once

#include <exception>
#include <string>

namespace arcade {

class Exception : public std::exception {
    private:
        std::string message;
    public:
        Exception(const std::string &message) : message(message) {}
        const char *what() const noexcept override { return this->message.c_str(); }
};

}