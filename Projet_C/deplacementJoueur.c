#include <stdio.h>
#include <stdlib.h>
#include "deplacementJoueur.h"

#include <time.h>


void initialiseRespawnRessource() {
    RessourceRespawn *ressourceRespawn = malloc(sizeof(*ressourceRespawn));
    Liste *elem = malloc(sizeof(*elem));

    if (ressourceRespawn == NULL || elem == NULL) {
        exit(EXIT_FAILURE);
    }

    ressourceRespawn->timer = 0; //
    ressourceRespawn->ressource = 0;
    ressourceRespawn->next = NULL;
    elem->first = ressourceRespawn;

}

void addRespawnRessource() {
    printf("sqdq");
}

int *whereIsPlayer(int ***map, int size) {

    int *positionPlayer = malloc(sizeof(int) * 3);
    for (int k = 0; k < 3; k++) {


        for (int i = 0; i < size; i++) {

            for (int j = 0; i < size; j++) {

                if (map[k][i][j] == 1) {

                    positionPlayer[0] = k;

                    positionPlayer[1] = i;

                    positionPlayer[2] = j;
                }
            }
        }
    }
    //printf("Vous etes actuellement en  %d  %d , sur la map %d \n", positionPlayer[1], positionPlayer[2], positionPlayer[3]);
    return positionPlayer;
}

void movingPlayer(int ***map, int size, Player player1,  Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss) {


    int* positionPlayer = whereIsPlayer(map, size);
    int k = positionPlayer[0];
    int i = positionPlayer[1]; //positionPlayer pour player
    int j = positionPlayer[2];

    int *positionDestination = malloc(sizeof(int) * 3);
    positionDestination[0] = k;
    positionDestination[1] = i;
    positionDestination[2] = j;
    printf("%d", positionDestination[1]);
    char entry = validEntry();


    switch (entry) {//on gere les cases du tableau ici pour le déplacement
        case 'Z' :
            if (i > 0) {
                int z = map[k][i - 1][j]; //position other pour swapPlayerAndOther
                int optionZ = optionMovement(z, player1, monstre12, monstre13, monstre14, monstre22, monstre23, monstre24, monstre32, monstre33, monstre34, boss);
                if (optionZ == 0) {
                    positionDestination[1] -= 1;
                    addRespawnRessource();
                    move(positionPlayer, positionDestination, map);
                    //traitement inversement de carte -> on doit inverser les 0 et les 1
                }
            } else {
                printf("Vous ne pouvez pas allez par la !\n\n");
            }
        case 'Q' :
            if (j > 0) {
                int q = map[k][i][j - 1];
                int optionQ = optionMovement(q, player1, monstre12, monstre13, monstre14, monstre22, monstre23, monstre24, monstre32, monstre33, monstre34, boss);
                if (optionQ == 0) {
                    //inversion des positions
                }
            } else {
                printf("Vous ne pouvez pas allez par la !\n\n");
            }

        case 'D' :
            if (j < size) {
                int d = map[k][i][j + 1];
                int optionD = optionMovement(d,  player1, monstre12, monstre13, monstre14, monstre22, monstre23, monstre24, monstre32, monstre33, monstre34, boss);
                if (optionD == 0) {
                    //inversion des positions
                }
            } else {
                printf("Vous ne pouvez pas allez par la !\n\n");
            }
        case 'S' :
            if (i < size) {
                int s = map[k][i + 1][j];
                int optionS = optionMovement(s, player1,  monstre12,  monstre13,  monstre14,  monstre22,  monstre23,  monstre24,  monstre32,  monstre33,  monstre34,  boss);
                if (optionS == 0) {
                    //inversion des positions
                }
            } else {
                printf("Vous ne pouvez pas allez par la !\n\n");
            }
        case 'W' :;
            //appelle la fonction Menu
    }
}

char validEntry() {

    char entryPlayer;
    int valid = 1;
    while (valid == 1) {

        valid = 0;
        printf("Saisissez une action  \n");
        scanf("%c", entryPlayer);
        //pensez a miniscule
        if (entryPlayer == 'Z' || entryPlayer == 'S' || entryPlayer == 'Q' || entryPlayer == 'D' ||
            entryPlayer == 'W') {

            return entryPlayer;
        } else {
            printf("Aaah mince, tu t'es apparement trompé de touche :( \n Voici la liste des touches valide : Z,Q,S,D,ESC");
            valid = 1;
        }
    }

}

int optionMovement(int x, Player player1,  Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss) {
    // 0 réussia bouger
    if (12 <= x && x <= 99) {
        fighting(  x,  player1,   monstre12,  monstre13,  monstre14,  monstre22,  monstre23,  monstre24,  monstre32,  monstre33,  monstre34,  boss);

        return 0;
    } else if (x >= 3  && x <= 11) {
        return 0; //SI RESSOURCE EST RECUP RETURN 0 SINON RETURN 1
        //fonction recources

    } else if (x == -3 || x == -2) {
        //fonction TP map
        return 1;
    } else if (x == -1) {
        printf("Ca c'est un mur, tu es face a un mur\n\n");
        return 1;
    } else if (x == 0) {
        //fonction move
        return 0;
    } else if (x == 2) {
        //fonction interaction avec le PNJ
        return 1;
    }
    printf("ERREUR MOVEMENT \n\n");
    return 2; // si c'est 2 y a un probleme
}

int ***move(int *positionStart, int *positionEnd, int ***map) {
    int k = positionStart[0];
    int i = positionStart[1];
    int j = positionStart[2];

    map[k][i][j] = 0;

    k = positionEnd[0];
    i = positionEnd[1];
    j = positionEnd[2];

    map[k][i][j] = 1;


    return map;
}

void tpMove(int tpNumber, int ***map, Player playerX, int *positionPlayer, int size){


    srand (time(NULL));
    int i = positionPlayer[1];
    int j = positionPlayer[2];
    int k = positionPlayer[3];
    int randY = 0;
    if(positionPlayer[0] ==  0){//passage en zone 2

        while(map[1][0][randY] != 0){
            randY = rand() % size;
        }
        map[1][0][randY] = 1;

    }else if(positionPlayer[0] == 1){//passage en zone 1 et 3

        if(tpNumber == -2){ //passage zone 1
            while(map[0][size][randY] != 0){
                randY = rand() % size;
            }

            map[1][size][randY] = 1;

         }else if(tpNumber == -3){ //passage zone 3

            while(map[2][0][randY] != 0){
                randY = rand() % size;
            }
            map[2][0][randY] = 1;
        }


    }else if(positionPlayer[0] == 3){//passage en 2

        while(map[1][size][randY] != 0){
            randY = rand() % size;
        }

        map[1][size][randY] = 1;

    }
    map[k][i][j] = 0;

}