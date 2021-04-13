#ifndef _JOUEUR_
#define _JOUEUR_
#define N 30

#include "plateau.h"

struct Joueur
{
        char nom[N];
        int score;
        int position;
        char *tresor;
        int couleur;
        int x;
        int y;
        int positionFinale;
};
typedef struct Joueur Joueur;

void joueur_tuile_solo(Joueur *j,plateau *plateau);

void incr_score(Joueur *j);

void attribute_tresor(plateau *p, Joueur *jou, int nombre,int nbJoueur);

void pop(plateau *p, int indice);

void free_joueurs(Joueur *j,int nbJoueurs);

#endif