#ifndef EVERYMONSTER_H_INCLUDED
#define EVERYMONSTER_H_INCLUDED
typedef struct Monster Monster;
struct Monster {

    int id;
    char* name;
    int dmg;
    int health;
    int xpGiven;

};
typedef struct Player Player;
struct Player{
    int level;
    int XP_current;
    int XP_next;
    int HP_max;
    int HP_current;
    int attack;
    int defense;
    //POUR S'EQUIPER D'UNE ARMURE ON A QUE UNE PLACE DANS L'INVENTAIRE DONC ON PEUT DIRECTEMENT LE METTRE DANS DEFENSE
};





//void initMonster();
Monster newMonster(int id, int dmg, int health, char* name, int xpGiven);
Player initPlayer();
void fighting(int monsterNumber, Player player1, Monster monstre12, Monster monstre13, Monster monstre14, Monster monstre22, Monster monstre23, Monster monstre24, Monster monstre32, Monster monstre33, Monster monstre34, Monster boss);

#endif // EVERYMONSTER_H_INCLUDED