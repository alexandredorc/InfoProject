#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/tuiles.h"
#include "headers/plateau.h"

plateau* initplat_alloc(const int taille)
{
    plateau *res = malloc(sizeof(*res));
    res->taille=taille;
    res->grille = malloc(taille*sizeof(*res->grille));
    for(int i=0; i<taille;i++){
        res->grille[i] = malloc(taille*sizeof(*res->grille[i]));
    }
    res->ligne_mobile = malloc(taille*sizeof(bool));
    res->colonne_mobile = malloc(taille*sizeof(bool));
    res->solo = malloc(sizeof(*res->solo));
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
/*
plateau deplacementvertical(plateau* p, const int colonne, const bool direction){
    //direction 0=vers le bas, 1=le haut
    tuiles temp;
    if (direction==0){
        temp=p->grille[colonne][0];
        
        for (int i=0;i<6;i++){
            p->grille[colonne][i]=p->grille[colonne][i+1];
        }
        p->grille[colonne][7]=p->solo;
        p->solo=temp;
    }

    if (direction==1){
        temp=p->grille[colonne][7];
        
        for (int i=0;i<6;i++){
            p->grille[colonne][i-1]=p->grille[colonne][i];
        }
        p->grille[colonne][7]=p->solo;
        p->solo=temp;
    }
}

plateau deplacementhorizontal(plateau p, int ligne, bool direction){
    //direction 0=vers la droite, 1=la gauche
    tuiles temp;
    if (direction==0){
        temp=p.grille[7][ligne];
        
        for (int i=1;i<=7;i++){
            p.grille[ligne][i]=p.grille[ligne][i-1];
        }
        p.grille[ligne][0]=p.solo;
        p.solo=temp;
    }

    if (direction==1){
        temp=p.grille[ligne][0];
        
        for (int i=7;i>=1;i--){
            p.grille[ligne][i]=p.grille[ligne][i+1];
        }
        p.grille[ligne][7]=p.solo;
        p.solo=temp;
    }
}*/