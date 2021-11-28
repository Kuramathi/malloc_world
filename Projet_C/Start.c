//
// Created by RAPH on 28/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "map.h"
#include "everyMonster.h"
#include "deplacementJoueur.h"
void StartMaps() {

//***********************CREATION DE LA MAP**************************//
    int sizeX = 10;
    int*** all_maps = createMaps(sizeX);
    addTeleport(all_maps,sizeX);
    addPnjAndPlayer(all_maps,sizeX);
    addRessources(all_maps,sizeX);
    addMonsters(all_maps,sizeX);
    printMaps(all_maps, sizeX);
//*******************************************************************//

}


void startMonsterPlayer(){


    //PLAYER
    Player player1 = initPlayer();

    //MONSTRE
    Monster monstre12 = newMonster(12,5,10,"piyaikipu",10);
    Monster monstre13 = newMonster(13,7,15,"piyaikipu",12);
    Monster monstre14 = newMonster(14,10,17,"piyaikipu",15);
    Monster monstre22 = newMonster(22,15,25,"piyaikipu",20);
    Monster monstre23 = newMonster(23,20,30,"piyaikipu",25);
    Monster monstre24 = newMonster(24,30,50,"piyaikipu",50);
    Monster monstre32 = newMonster(32,40,60,"piyaikipu",60);
    Monster monstre33 = newMonster(33,50,70,"piyaikipu",70);
    Monster monstre34 = newMonster(34,60,80,"piyaikipu",80);
    Monster boss = newMonster(99,100,250,"piyaikipu",100);


}

void chargeMap(){
    FILE* fichier = NULL;

    fichier = fopen("sauvegarde.txt", "r");

    if (fichier != NULL)
    {
        printf("test charge fichier");
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier sauvegarde.txt");
    }
}
void gameControl(int ***map, int size,Player player1, Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss) {
    int tall = 10;
    int looper = 1;
    while (looper == 1) {
        printMaps(map, tall);
        movingPlayer(map, size, player1, monstre12, monstre13, monstre14, monstre22, monstre23, monstre24, monstre32,
                     monstre33, monstre34, boss);

    }
}
