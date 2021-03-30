#ifndef _PLATEAU_
#define _PLATEAU_

struct plateau{
    int taille; 
    struct tuile **grille;
    struct tuile *solo;
    bool *ligne_mobile;
    bool *colonne_mobile;
};

typedef struct plateau plateau;

plateau* initplat_alloc(const int taille);
void free_plat(plateau* p);

#endif