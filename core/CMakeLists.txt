project(arcade_core)
cmake_minimum_required(VERSION 3.17)
add_executable(
    arcade
    src/main.cpp
    src/dynamic_library.cpp
        ../include/IGraphicLibrary.hpp)
target_link_libraries(arcade ${CMAKE_DL_LIBS})
add_custom_command(TARGET arcade
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade> ${CMAKE_SOURCE_DIR})
add_custom_command(TARGET arcade
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade> ${CMAKE_BINARY_DIR})