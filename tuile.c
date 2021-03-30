#include <stdbool.h>
#include <stdio.h>
#include "headers/tuiles.h"

bool * init_Tuiles(bool bas, bool haut, bool droite, bool gauche){
        static bool tuile[9];
        for (int i=0;i<9;i++){
            tuile[i]=0;
        }
        tuile[1]=haut;
        tuile[3]=gauche;
        tuile[5]=droite;
        tuile[7]=bas;
        tuile[4]=1;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%d ", tuile[j+3*i]);
                }
                printf("\n");
        }
        printf("\n");
        return tuile;
}

