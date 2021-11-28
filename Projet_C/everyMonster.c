#include <stdio.h>
#include <stdlib.h>
#include "everyMonster.h"
#include "fightingFonction.h"

 Player initPlayer(){
    struct Player player1;
    player1.level = 1;
    player1.XP_current = 0;
    player1.XP_next = 50;
    player1.HP_max = 100;
    player1.HP_current = 100;
    player1.attack = 10;
    player1.defense = 0;

     return player1;
}

Monster newMonster(int id, int dmg, int health, char* name, int xpGiven){
    struct Monster monster;
    monster.dmg = dmg;
    monster.id = id;
    monster.health = health;
    monster.name = name;
    monster.xpGiven = xpGiven;
}




void fighting(int monsterNumber, Player player1,  Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss) {

    switch(monsterNumber){
        case 12:
            fightingCombat(monstre12,  player1);
        case 13:
            fightingCombat( monstre13,  player1);
        case 14:
            fightingCombat( monstre14,  player1);
        case 22:
            fightingCombat( monstre22,  player1);
        case 23:
            fightingCombat( monstre23,  player1);
        case 24:
            fightingCombat( monstre24,  player1);
        case 32:
            fightingCombat( monstre32,  player1);
        case 33:
            fightingCombat( monstre33,  player1);
        case 34:
            fightingCombat( monstre34,  player1);
        case 99:
            fightingCombat( boss,  player1);
    }
}




