project(arcade_game_libraries)
cmake_minimum_required(VERSION 3.17)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(arcade_sdl2 SHARED src/sdl/sdl_game_library.cpp ../include/IGraphicLibrary.hpp src/graphic_library.cpp)
find_package(SDL2 REQUIRED)
target_include_directories(arcade_sdl2 PUBLIC ${SDL2_INCLUDE_DIRS} SDL2_ttf)
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES} SDL2_ttf)
target_link_libraries(arcade_sdl2 ${SDL2})
add_custom_command(TARGET arcade_sdl2
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sdl2> ${CMAKE_BINARY_DIR}/lib)
add_custom_command(TARGET arcade_sdl2
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sdl2> ${CMAKE_SOURCE_DIR}/lib)

add_library(arcade_ncurses SHARED src/ncurses/ncurses_game_library.cpp ../include/IGraphicLibrary.hpp src/graphic_library.cpp)
find_package(Curses REQUIRED)
target_include_directories(arcade_ncurses PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

add_custom_command(TARGET arcade_ncurses
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_ncurses> ${CMAKE_BINARY_DIR}/lib)
add_custom_command(TARGET arcade_ncurses
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_ncurses> ${CMAKE_SOURCE_DIR}/lib)