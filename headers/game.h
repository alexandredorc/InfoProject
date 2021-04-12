#ifndef _GAME_
#define _GAME_

#include "joueur.h"
#include "plateau.h"
#define N 30

struct Game{
        bool run;
        int nbTresor;
        int nbJoueurs;
        Joueur *joueurs;
        int actif;
        plateau *plateau;
        int *couleur;
}; 
typedef struct Game Game;

int startgame(Game *G);

Game *propgame();

void create_joueurs(Game *G, int nbJoueurs);

void resultat(Game *G);

void endgame(Game *G);

void afficher(Game *G);

#endif
