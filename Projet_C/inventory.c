//
// Created by RAPH on 28/11/2021.
//

#include "inventory.h"
#include "inventory.h"
#include "farm.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int** initialisation(int** inventory, int size){
    inventory = malloc(sizeof(int)*size);
    for(int i = 0; i<size;i++){
        inventory[i] = malloc(sizeof(int)*2);
    }


    for(int x = 0; x<size; x++){
        for(int y = 0; y<size; y++){
            inventory[x][y] = 0;
        }
    }

    return inventory;
}

void printInventory(int** inventory,int size){
    for(int i = 0; i<size;i++){
        for(int j =0; j<2;j++){
            printf("%d ",inventory[i][j]);
        }
        printf("\n");
    }
}


int** addNewElement(int** inventory, int size, int element){
    int tmp = 0;

    // ON VERIFIE QUE INVENTORY NE CONTIENT PAS CET ITEM
    for(int i = size-1; i==0; i--){
        if(inventory[i][0] == element){
            tmp = i;
        }
    }

    //S'IL NE CONTIENT PAS
    if(tmp == 0){
        for(int j = 0;j<size;j++){
            if(inventory[j][0] == 0){
                inventory[j][0] = element;
                inventory[j][1] = 1;
                break;
            }
        }
        //S'IL CONTIENT
    }else{
        if((element>=5 && element <=7) || (element>=16 && element<=18) || (element>=27 && element<=29)){
            inventory[tmp][1]+=1;
        } else{
            printf("Vous avez déjà cet objet dans l'inventaire\n\n");
        }
    }
    return inventory;
}


int** removeElement(int** inventory, int size, int element){
    for(int i = 0; i<size;i++){
        if(inventory[i][0] == element){
            inventory[i][1] -=1;
            if(inventory[i][1] == 0){
                inventory[i][0] = 0;
            }
            break;
        }
    }
    return inventory;
}