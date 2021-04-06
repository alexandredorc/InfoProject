#include "tuiles.h"
#ifndef _PLATEAU_
#define _PLATEAU_
#include "tuile.h"

struct plateau{
    int taille; 
    int** grille;
    tuile* tuiles;
    int solo;
    bool *ligne_mobile;
    bool *colonne_mobile;
};

typedef struct plateau plateau;

plateau* initplat_alloc(const int taille);
void free_plat(plateau* p);

#endif