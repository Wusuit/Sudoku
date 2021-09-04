cmake_minimum_required(VERSION 3.17)
project(Sudoku C)

set(CMAKE_C_STANDARD 99)

add_executable(Sudoku c/main.c)
target_link_libraries(Sudoku mingw32 SDL2main SDL2 SDL2_ttf)