
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tuiles.h"

struct plateau{
    struct tuiles grille[7][7];
    struct tuiles solo;
    bool mobile[7][7]; 

};

typedef struct plateau plateau;

plateau deplacementvertical(plateau p, int colonne, bool direction){
    //direction 0=vers le bas, 1=le haut
    tuiles temp;
    if (direction==0){
        temp=p.grille[colonne][7];
        
        for (int i=1;i<=7;i++){
            p.grille[colonne][i]=p.grille[colonne][i-1];
        }
        p.grille[colonne][0]=p.solo;
        p.solo=temp;
    }

    if (direction==1){
        temp=p.grille[colonne][0];
        
        for (int i=7;i>=1;i--){
            p.grille[colonne][i]=p.grille[colonne][i+1];
        }
        p.grille[colonne][7]=p.solo;
        p.solo=temp;
    }
}