#ifndef _GAME_
#define _GAME_

#include "joueur.h"
#define N 30

struct Game{
        bool run;
        int nbJoueurs;
        Joueur *joueurs;
        int actif;
        //Plateau *plateau
}; 
typedef struct Game Game;

int startgame(Game *G);

Game *propgame();

void create_joueurs(Game *G);

void resultat(Game *G);

void endgame(Game *G);

#endif
