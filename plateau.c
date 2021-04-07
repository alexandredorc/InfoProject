#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/tuiles.h"
#include "headers/plateau.h"

void initplat_alloc(plateau* P,int taille)
{
    P->taille=taille;
    P->TabTuiles = malloc(((taille*taille)+1)*sizeof(*P->TabTuiles));
    P->grille=malloc(sizeof *P->grille * taille);
	for (int i = 0; i < taille; i++)
	{
		P->grille[i] = malloc(sizeof **P->grille * taille);
	}
    int k=0;
    for(int i = 0; i <taille;i++){
        for(int j = 0; j <taille;j++){
            P->grille[i][j]=k;
            bool fix=true;
            if(i%2!=0 && j%2!=0){
                fix=false;
            }
            init_Tuiles(&(P->TabTuiles[k]),' ',fix);
            k++;
        }
    }
    P->TabTuiles[7].tresor='o';
    P->TabTuiles[9].tresor='g';
    P->TabTuiles[9].passage[2]=false;
    P->ligne_mobile = malloc(taille*sizeof(bool));
    P->colonne_mobile = malloc(taille*sizeof(bool));
    fix(P);
}

void fix(plateau *P ){
    for(int i=0;i<P->taille;i++){
        P->colonne_mobile[i]=true;
        P->ligne_mobile[i]=true;  
    }
    for(int i=0;i<P->taille;i++){
        for(int j=0;j<P->taille;j++){
            if(!P->TabTuiles[P->grille[i][j]].mobile){
                P->colonne_mobile[j]=false;
                P->ligne_mobile[i]=false;
            }
        }
    }
    
}

void free_plat(plateau* p)
{
    free(p->ligne_mobile);
    free(p->colonne_mobile);
    for(int i=0;i<p->taille;i++){
        free(p->grille[i]);
    }
    free(p->grille);
    free(p);
}
