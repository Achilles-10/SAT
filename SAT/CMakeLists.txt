cmake_minimum_required(VERSION 3.9)
project(SAT C)

set(CMAKE_C_STANDARD 11)

add_executable(SAT main.c vec.c vec.h formula.c formula.h clauses.c clauses.h sudoku.c sudoku.h toCNF.c toCNF.h menu.c menu.h)