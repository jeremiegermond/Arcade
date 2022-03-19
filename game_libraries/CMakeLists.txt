project(arcade_game_libraries)
cmake_minimum_required(VERSION 3.17)

add_library(SDL2 SHARED src/sdl_game_library.cpp)
find_package(SDL2 REQUIRED)
target_include_directories(SDL2 PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL2 ${SDL2_LIBRARIES})

add_library(nCurses SHARED src/ncurses_game_library.cpp)
find_package(Curses REQUIRED)
target_include_directories(nCurses PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(nCurses ${CURSES_LIBRARIES})

add_library(Vulkan SHARED src/vulkan_game_library.cpp)
