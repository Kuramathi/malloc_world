//
// Created by RAPH on 28/11/2021.
//

#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

#endif //GAME_INVENTORY_H

int** initialisation(int** inventory, int size);
void printInventory(int** inventory, int size);
int** addNewElement(int** inventory, int size, int element);
int** removeElement(int** inventory, int size, int element);

typedef struct weapon weapon ;
struct weapon{
    int id;
    char name;
    int dmg;
    int dura;
};