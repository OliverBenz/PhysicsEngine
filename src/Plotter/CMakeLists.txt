find_file(SDL2_INCLUDE_DIR NAMES SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAMES SDL2)

add_library(Plotter SHARED
    Window.hpp
    Window.cpp
)

target_include_directories(Plotter PRIVATE ${DSL2_INCLUDE_DIR})
target_link_libraries(Plotter PRIVATE ${SDL2_LIBRARY})