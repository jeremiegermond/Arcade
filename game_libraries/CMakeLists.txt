project(arcade_game_libraries)
cmake_minimum_required(VERSION 3.16)

target_sources(
        arcade_sdl2 PUBLIC
        src/sdl/sdl_game_library.cpp
)

target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})
find_package(SDL2 REQUIRED)
target_include_directories(arcade_sdl2 PUBLIC ${SDL2_INCLUDE_DIRS} SDL2_ttf SDL2_image)
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES} SDL2_ttf SDL2_image)

target_sources(
        arcade_ncurses PUBLIC
        src/ncurses/ncurses_game_library.cpp
)

find_package(Curses REQUIRED)
target_include_directories(arcade_ncurses PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

target_sources(
        arcade_sfml PUBLIC
        src/sfml/sfml_game_library.cpp
)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
target_include_directories(arcade_sfml PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(arcade_sfml ${SFML_LIBRARIES})
target_link_libraries(arcade sfml-graphics sfml-audio)