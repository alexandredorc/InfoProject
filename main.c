#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"


#define N 30

int main() {
        
        Game *G=propgame();
        char nom[N];
        strcpy(nom, G->joueurs[0].nom);
        afficher(G);
        // ⊛ ⊗ ╔ ╗ ╠ ╕ ╤ ╛ ╠ ╗ ◠ ☰ ☰ ⎣ ⎤  ╬ ╪ ▒ ░ 
        startgame(G);
        endgame(G);
        return 0;
}