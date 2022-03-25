target_sources(
    arcade PUBLIC
    src/main.cpp
    src/dynamic_library.cpp
)

target_link_libraries(arcade ${CMAKE_DL_LIBS})