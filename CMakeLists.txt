cmake_minimum_required(VERSION 3.29)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(compiler
    Affichage.c
    Affichage.h
    lex.yy.c
    readme.txt
    rendu.l
    rendu.tab.c
    rendu.y
    structs.c
    structs.h
    tokens.h
    y.tab.c
    y.tab.h)
