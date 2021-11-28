#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "everyMonster.h"
//#include "inventory.h"
#include "Start.h"
#include "deplacementJoueur.h"
#include "gameControl.h"

void Menu(){
    int choix;
    printf("Bienvenue dans Malloc World\n\n");
    printf("1 : Nouvelle Partie\n");
    printf("2 : Chargé la sauvegarde\n");
    printf("3 : Free and Quit ?\n");
    printf("Quel est votre choix? taper 1, 2 ou 3 \n\n");
    scanf("%d", &choix);
    printf("\n");

    switch (choix){
        case 1: ;
            int i = 0;
            printf("1 : Nouvelle map\n");
            printf("2 : Garder la map\n");
            printf("Quel est votre choix? taper 1 ou 2\n\n");
            scanf("%d", &i);
            switch(i){
                case 1:
                    //start complet
                    StartMaps();
                    startMonsterPlayer();
                    //initialiseRespawnRessource;

                    //gameControl( );
                case 2:
                    //start sans map + chargé map dans le fichier

                    initialiseRespawnRessource;
                    chargeMap;
                default:
                    printf("Vous n'avez pas rentre un nombre correct.\n\n");

           }

        case 2: ;
            //chargé la map et l'inventaire avec le fichier


        case 3: ;
            exit(EXIT_FAILURE);


        default:
           printf("Vous n'avez pas rentre un nombre correct.\n\n");


    }
      printf("\n\n");

}


