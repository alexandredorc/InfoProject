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

void shuffle(char *array, int n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void attribute_tresor(plateau *p, Joueur *jou, int nombre){
    
    shuffle(p->listeTresor,nombre);
    int k =0;
    for(int i=0;i<nombre;i++){
        jou[i].tresor=malloc(sizeof(char)*nombre);
        for(int j=0;j<nombre;j++){
            jou[i].tresor[j]=p->listeTresor[k];
            k++;
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
            printf("%d %d coor",a,b);
        }
        else{
            a=0;
            b=plateau->solopos[0]-1;
            printf("%d %d coor",a,b);
            
        }
    }
    else{
        if(plateau->solopos[2]==1){

            b=plateau->taille-1;
            a=plateau->solopos[0]-1;
            printf("%d %d coor",a,b);
        }
        else{
            b=0;
            a=plateau->solopos[0]-1;
            printf("%d %d coor",a,b);
        }
    }
    if(j->position==plateau->solo){
        j->position=plateau->grille[b][a];
        j->x=a;
        j->y=b;
        printf("%d",j->position);
    }
}