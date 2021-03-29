#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "headers/joueur.h"

#define N 30



struct Game{
        bool run;
        int nbJoueurs;
        struct Joueur *joueurs;
}; 
typedef struct Game Game;

int startgame(struct Game G){
        while(G.run){

        }
        return 0; 
}

struct Game propgame(){
        printf("entrer le nombre de joueurs: ");
        int nbJoueurs;
        scanf("%d", &nbJoueurs);
        printf("le nombre de joueurs est %d \n",nbJoueurs);
        struct Joueur j[nbJoueurs];
        for (int i = 0; i < nbJoueurs; i++)
        {
                printf("entrer le nom du joueur %d: ",i+1);
                scanf("%s",j[i].nom);
        }
        
        struct Game g={true,nbJoueurs};
        g.joueurs=j;
        return g;
}

int main() {   
        
        struct Game G=propgame();
        char nom[N];
        strcpy(nom, G.joueurs[0].nom);
        printf("%s",nom);
        //startgame(G);
        return 0;
}