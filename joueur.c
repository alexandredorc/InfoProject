#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/joueur.h"
#include "headers/plateau.h"
#define N 30

void incr_score(Joueur *j){
    j->score+=1;
}

void joueur_tuile_solo(Joueur *j,plateau *plateau){
    int a;
    int b;
    if(plateau->solopos[1]==1){
        if(plateau->solopos[2]==1){
            a=plateau->taille-1;
            b=plateau->solopos[0]-1;
        }
        else{
            a=0;
            b=plateau->solopos[0]-1;
        }
    }
    else{
        if(plateau->solopos[2]==1){

            b=plateau->taille-1;
            a=plateau->solopos[0]-1;
        }
        else{
            b=0;
            a=plateau->solopos[0]-1;
        }
    }
    if(j->position==plateau->solo){
        j->position=plateau->grille[b][a];
    }
}