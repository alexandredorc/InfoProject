#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/plateau.h"
#include "headers/joueur.h"

#define N 30



void create_joueurs(Game *G){
    printf("entrer le nombre de joueurs: ");
    scanf("%d", &(G->nbJoueurs));
    Joueur *j=malloc(sizeof(Joueur)*G->nbJoueurs);
    for (int i = 0; i < G->nbJoueurs; i++)
    {
            printf("entrer le nom du joueur %d: ",i+1);
            scanf("%s",j[i].nom);
    }
    G->joueurs=j;
}

int startgame(Game *G){
        while(G->run){

        }
        return 0; 
}

Game *propgame(){
        Game *G=malloc(sizeof(Game));
        create_joueurs(G);
        G->run=true;
        return G;
        G->actif=0;
}

void resultat(Game *G){
        printf("fin de la partie\n");
}

void endgame(Game *G){
        resultat(G);
        free(G->joueurs);
        free(G);
        printf("fin du programme\n");
}

int main() {
        Game *G=propgame();
        char nom[N];
        strcpy(nom, G->joueurs[0].nom);
        
        
        printf("%s\n",nom);
        //startgame(G);
        endgame(G);
        return 0;
}