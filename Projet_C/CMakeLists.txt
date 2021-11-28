cmake_minimum_required(VERSION 3.17)
project(Projet_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_C
        deplacementJoueur.c
        deplacementJoueur.h
        everyMonster.c
        everyMonster.h
        fightingFonction.c
        main.c
        map.c
        map.h
        Menu.c
        Menu.h Start.c gameControl.c gameControl.h inventory.c inventory.h tpPassage.c tpPassage.h)
