#ifndef DEPLACEMENTJOUEUR_H_INCLUDED
#define DEPLACEMENTJOUEUR_H_INCLUDED
#include "everyMonster.h"



typedef struct RessourceRespawn RessourceRespawn;
struct RessourceRespawn{
    RessourceRespawn *next;
    int timer;
    int ressource;
    int *position;
};
typedef struct Liste Liste;
struct Liste{
    RessourceRespawn *first;
};
void initialiseRespawnRessource();

void addRespawnRessource();

int* whereIsPlayer(int***map,int size);

void movingPlayer(int ***map, int size,Player player1, Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss);

char validEntry();

int optionMovement(int x, Player player1,  Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss);

int*** move(int *positionStart,int *positionEnd,int ***map);
#endif // DEPLACEMENTJOUEUR_H_INCLUDED