#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include "headers/tuiles.h"

void init_Tuiles(tuile *tuile,char tresor, bool mobile,bool haut,bool droite,bool bas,bool gauche){
        tuile->passage=malloc(sizeof*(tuile->passage)*4);
        tuile->passage[0]=haut;
        tuile->passage[1]=droite;
        tuile->passage[2]=bas;
        tuile->passage[3]=gauche;
        tuile->mobile=mobile;
        tuile->tresor=tresor;
}

