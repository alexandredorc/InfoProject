#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"


#define N 30

int main() {
        
        /*
        //Liste des couleurs possibles de background pour le jeu
        for (int i = 0; i < 256; i++)
        {
                printf("Couleur numero %d : \033[48;5;%dm   \033[m\n",i , i);
        }
        */

        Game *G=propgame();
        char nom[N];
        strcpy(nom, G->joueurs[0].nom);
        afficher(G);
        //⊛ ⊗ ╔╗ ╠╕ ╤╛ ╠╗ ◠☰☰ ⎣⎤  ╬╪ ▒░ 
        //startgame(G);
        endgame(G);
        return 0;
}