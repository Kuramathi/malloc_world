/*
#include <time.h>
#include "everyMonster.h"
#include "tpPassage.h"
void tpMove(int tpNumber, ***map, Player playerX, *positionPlayer, size){


srand(time(NULL));

int randY = 0;


if(positionPlayer[0] ==  1){//passage en zone 2

    while(map[1][0][randY] != 0){
        randY = rand() % size;
    }
    map[1][0][randY] = 1;

}else if(positionPlayer[0] == 2){//passage en zone 1 et 3

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

}
 */