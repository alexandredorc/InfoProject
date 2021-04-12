#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/joueur.h"
#include "headers/plateau.h"
#include "headers/game.h"
#include <time.h>
#define N 30

void incr_score(Joueur *j){
    j->score+=1;
}

void pop(plateau *p, int indice){
    
    for (int i=indice-1; i < 24 - 1; i++)
         p->liste_Tresor[i] = p->liste_Tresor[i+1];
}

void attribute_tresor(plateau *p, Game *g, int nombre){
    srand(time(NULL));
    int r;
    
    for(int i=0;i<g->nbJoueurs;i++){
        g->joueurs[i].tresor=malloc(sizeof(char)*g->nbTresor);    
        for(int j=0;j<g->nbTresor;i++){
            r=rand()%g->nbTresor*g->nbJoueurs;
            g->joueurs[i].tresor[j]=p->liste_Tresor[r];
            pop(p, r);
        }
    }
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