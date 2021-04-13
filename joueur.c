#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/joueur.h"
#include "headers/plateau.h"
#include "headers/game.h"
#include <time.h>
#define N 30
//incrémentation du score
void incr_score(Joueur *j){
    j->score+=1;
}

//mélange de la liste de trésor 
void shuffle(char *array, int n)
{
    srand(time(NULL));
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = rand()%n;
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

//attribution de trésor à chaque joueur
void attribute_tresor(plateau *p, Joueur *jou, int nombre,int nbJoueur){
    
    shuffle(p->listeTresor,nombre);
    int k =0;
    for(int i=0;i<nbJoueur;i++){
        jou[i].tresor=malloc(sizeof(char)*nombre);
        for(int j=0;j<nombre;j++){
            jou[i].tresor[j]=p->listeTresor[k];
            k++;
        }
    }
}

//Expulsion du joueur à l'opposé du plateau
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
        j->x=a;
        j->y=b;
    }
}

//libération mémoire des trésors
void free_joueurs(Joueur *j,int nbJoueurs){
    for (int i = 0; i < nbJoueurs; i++)
    {
        free(j[i].tresor);
    }
}