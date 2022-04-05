target_sources(
        arcade PUBLIC
        src/main.cpp
        src/dynamic_library.cpp
        src/Score.cpp
)

target_link_libraries(arcade ${CMAKE_DL_LIBS})