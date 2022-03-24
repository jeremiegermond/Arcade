project(arcade_games)
cmake_minimum_required(VERSION 3.17)

add_library(arcade_pacman SHARED
        src/game_library.cpp
        src/pacman/Pacman.cpp
)
add_custom_command(TARGET arcade_pacman
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_pacman> ${CMAKE_BINARY_DIR}/lib)
add_custom_command(TARGET arcade_pacman
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_pacman> ${CMAKE_SOURCE_DIR}/lib)