#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/tuiles.h"
#include "headers/plateau.h"

plateau* initplat_alloc(const int taille)
{
    plateau *res = malloc(sizeof(res));
    res->taille=taille;
    res->tuiles = malloc((taille*taille+1)*sizeof(*res->tuiles));
    res->grille=malloc(sizeof *res->grille * taille);
    for (int i = 0; i < taille; i++)
    {
        res->grille[i] = malloc(sizeof **res->grille * taille);
    }
    res->ligne_mobile = malloc(taille*sizeof(bool));
    res->colonne_mobile = malloc(taille*sizeof(bool));
    return res;
}

void free_plat(plateau* p)
{
    free(p->solo);
    free(p->ligne_mobile);
    free(p->colonne_mobile);
    for(int i=0;i<p->taille;i++){
        free(p->grille[i]);
    }
    free(p->grille);
    free(p);
}

plateau deplacementvertical(plateau* p, const int colonne, const bool direction){
    //direction 0=vers le bas, 1=le haut
    int temp;
    if (direction==1){
        temp=p->grille[colonne][0];
        
        for (int i=0;i<p->taille;i++){
            p->grille[colonne][i]=p->grille[colonne][i+1];
        }
        p->grille[colonne][p->taille]=p->solo;
        p->solo=temp;
    }

    else if (direction==0){
        temp=p->grille[colonne][p->taille];
        
        for (int i=p->taille;i>0;i--){
            p->grille[colonne][i]=p->grille[colonne][i-1];
        }
        p->grille[colonne][0]=p->solo;
        p->solo=temp;
    }
}

plateau deplacementhorizontal(plateau* p, const int ligne, const bool direction){
    //direction 0=vers la droite, 1=la gauche
    int temp;
    if (direction==1){
        temp=p->grille[p->taille][ligne];
        
        for (int i=p->taille;i>0;i--){
            p->grille[ligne][i]=p->grille[ligne][i-1];
        }
        p->grille[ligne][0]=p->solo;
        p->solo=temp;
    }

    else if (direction==1){
        temp=p->grille[ligne][0];
        
        for (int i=0;i<p->taille;i++){
            p->grille[ligne][i]=p->grille[ligne][i+1];
        }
        p->grille[ligne][p->taille]=p->solo;
        p->solo=temp;
    }
}
