project(arcade_core)
cmake_minimum_required(VERSION 3.17)
add_executable(
    core 
    src/main.cpp
    src/dynamic_library.cpp
)
target_link_libraries(core ${CMAKE_DL_LIBS})