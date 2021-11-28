//
// Malloc Word, Piscine C, 2021
//

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int*** createMaps(int x){
    int ***all_maps = NULL;

    all_maps = malloc(sizeof(int**)*3);
    for(int i = 0; i < x; i++){
        all_maps[i] = malloc(sizeof(int*)*x);
        for(int j = 0; j<x;j++){
            all_maps[i][j] = malloc(sizeof(int)*x);
        }
    }

    for(int k = 0; k<3;k++) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                all_maps[k][i][j] = 0;
            }
        }
    }
    return all_maps;
}

void printMaps(int*** tab, int size){
    for(int k = 0; k<3; k++){
        printf("\nZONE %d\n",k+1);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", tab[k][i][j]);
            }
            printf("\n");
        }
    }

}

int*** addTeleport(int*** tab,int size){

    srand(time(NULL));

    tab[0][size-1][rand() % size] = -2;
    tab[1][0][rand() % size] = -2;
    tab[1][size-1][rand() % size] = -3;
    tab[2][0][rand() % size] = -3;
    return tab;
}

int*** addRessources(int*** tab,int size){
    srand(time(NULL));
    int randX;
    int randY;


// On parcourt les 3 tableaux
    for(int j = 0; j<3;j++) {
        int tmp = 0;

        // On répète trois fois l'opération pour les plantes, les rochers, et le bois
        while(tmp < 3) {

            //PLANTE
            randX = rand() % size;
            randY = rand() % size;
            if (tab[j][randX][randY] == 0) {
                tmp+=1;
                if (j == 0) {
                    tab[j][randX][randY] = 3;
                } else if (j == 1) {
                    tab[j][randX][randY] = 6;
                } else if (j == 2) {
                    tab[j][randX][randY] = 9;
                }
            }
        }
        tmp = 0;

            //ROCHER

        while(tmp < 3) {

            randX = rand() % size;
            randY = rand() % size;
            if (tab[j][randX][randY] == 0) {
                tmp+=1;
                if (j == 0) {
                    tab[j][randX][randY] = 4;
                } else if (j == 1) {
                    tab[j][randX][randY] = 7;
                } else if (j == 2) {
                    tab[j][randX][randY] = 10;
                }
            }
        }
        tmp=0;
            //BOIS
        while(tmp < 3){
            randX = rand() % size;
            randY = rand() % size;
            if (tab[j][randX][randY] == 0) {
                tmp+=1;
                if(j == 0){
                    tab[j][randX][randY] = 5;
                } else if(j == 1){
                    tab[j][randX][randY] = 8;
                } else if(j == 2){
                    tab[j][randX][randY] = 11;
                }
            }

        }
    }
    return tab;
}

int*** addMonsters(int*** tab,int size){

    int monsters[] = {12,13,14,22,23,24,32,33,34,99};
    int size_monsters = 10;
    int randX, randY;
    srand(time(NULL));

    for(int i = 0; i< size_monsters;i++){
        randX = rand() % size;
        randY = rand() % size;
        //Zone 1
        if(monsters[i] >= 12 && monsters[i]<= 14){
            if(tab[0][randX][randY] == 0){
                tab[0][randX][randY] = monsters[i];
            }else{
                i--;
            }
            //Zone 2
        } else if (monsters[i] >=22 && monsters[i] <= 24){
            if(tab[1][randX][randY] == 0){
                tab[1][randX][randY] = monsters[i];
            } else{
                i--;
            }
            //Zone 3
        }else if (monsters[i] >=32 && monsters[i] <= 99){
            if(tab[2][randX][randY] == 0){
                tab[2][randX][randY] = monsters[i];
            }else{

                i--;
            }
        }
    }

    return tab;
}

int*** addPnjAndPlayer(int*** tab, int size){
    srand(time(NULL));
    int randX;
    int randY;

    //Ajout du joueur
    while(tab[0][0][randY] != 0){
        randY = rand() % size;
    }
    tab[0][0][randY] = 1;
    //Ajout des PNJ
    for(int i = 0; i < 3;i++){
        randX = rand() %size;
        randY = rand() %size;
        while(tab[i][randX][randY] != 0){
            randX = rand() % size;
            randY = rand() % size;
        }
        tab[i][randX][randY] = 2;
    }
    return tab;
}


/*int*** addStop(int*** tab,int size){
    srand(time(NULL));
    int randX;
    int randY;

    tab[0][randX][]
}*/

void free_data(int ***data, int size){

    for (int i=0; i < size; ++i) {
        if (data[i] != NULL) {
            for (int j=0; j < size; ++j)
                free(data[i][j]);
            free(data[i]);
        }
    }
    free(data);
}
