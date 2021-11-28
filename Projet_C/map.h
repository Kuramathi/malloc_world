//
// Malloc Word, Piscine C, 2021
//

#ifndef GAME_MAP_H
#define GAME_MAP_H




//********************************Déclaration fonctions***************************//
int*** createMaps(int x);
void printMaps(int*** tab, int size);
int*** addTeleport(int*** tab,int size);
int*** addRessources(int*** tab,int size);
int*** addMonsters(int*** tab,int size);
int*** addPnjAndPlayer(int*** tab, int size);
void free_data(int ***data, int size);
#endif //GAME_MAP_H