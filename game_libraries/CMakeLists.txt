project(arcade_game_libraries)
cmake_minimum_required(VERSION 3.17)

add_library(arcade_sdl2 SHARED src/sdl_game_library.cpp)
find_package(SDL2 REQUIRED)
target_include_directories(arcade_sdl2 PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})

add_library(arcade_ncurses SHARED src/ncurses_game_library.cpp)
find_package(Curses REQUIRED)
target_include_directories(arcade_ncurses PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

# add_library(arcade_sdl2 SHARED src/vulkan_game_library.cpp)
