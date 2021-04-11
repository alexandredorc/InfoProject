#ifndef _PLATEAU_
#define _PLATEAU_
#include "tuiles.h"
struct plateau{
    int taille; 
    int  **grille;
    tuile *TabTuiles;
    int solo;
    bool *ligne_mobile;
    bool *colonne_mobile;
    int solopos[3];
    int *couleur;
};
typedef struct plateau plateau;

void fix(plateau *P);

void initplat_alloc(plateau* P,int taille);

void free_plat(plateau* p);

void create_tresor(plateau* p);

void deplacement(plateau* p);

#endif