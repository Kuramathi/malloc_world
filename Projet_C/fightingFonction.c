#include <stdio.h>
#include <stdlib.h>
#include "everyMonster.h"


void gainLevel(struct Player player);

void fightingCombat(struct Monster monstreX, struct Player playerX){
    int dead = 0;
    while(dead != 1){
        monstreX.health = monstreX.health - playerX.attack;
        if(monstreX.health <= 0){ //monstre dead
            printf("Vous avez tué le %s", monstreX.name);
            playerX.XP_current = playerX.XP_current + monstreX.xpGiven;
            dead = 1;
        if(playerX.XP_current >= playerX.XP_next){ //si t'as assez de XP
            gainLevel(playerX);//fonction gain de niveau
        }
        }else{//monstre pas dead
            playerX.HP_current = playerX.HP_current - (monstreX.dmg - (playerX.defense / monstreX.dmg)); // NE PAS OUBLIER L'ARMURE DU JOUEUR
            if(playerX.HP_current <= 0){
                printf("GAME OVER, le %c vous a tué", monstreX.name);

                //fonction fin du jeu
            }else{
                printf("Vous n'avez pas tué le %c, il lui reste %d de PV. \nIl vous reste %d de PV", monstreX.name, monstreX.health, playerX.HP_current);
        }
        }
}
    }

void gainLevel(struct Player playerX) {
    if(playerX.XP_current > playerX.XP_next){
        playerX.XP_current = playerX.XP_current - playerX.XP_next;
    }else{
        playerX.XP_current = 0;
    }
    playerX.XP_next = playerX.XP_next + 50;
    if(playerX.level < 5){
        playerX.HP_max = playerX.HP_max + (playerX.level * 10);
        playerX.HP_current = playerX.HP_current + (playerX.level * 10);
    }else if(playerX.level < 8){
        playerX.HP_max = playerX.HP_max + 50;
        playerX.HP_current = playerX.HP_current + 50;
    }else if(playerX.level < 10){
        playerX.HP_max = playerX.HP_max + 75;
        playerX.HP_current = playerX.HP_current + 75;
    }
    if (playerX.level < 10){
        playerX.level = playerX.level + 1;
    }
}


