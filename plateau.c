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
            if(i%2!=1 && j%2!=1){
                fix=false;
            }
            init_Tuiles(&(P->TabTuiles[k]),' ',fix);
            k++;
        }
    }
    P->TabTuiles[7].tresor='o';
    P->TabTuiles[9].tresor='g';
    bool Lshape[4]={true,false,false,true};
    int posCorner[4]={taille*taille-1,taille*(taille-1),0,taille-1};
    int couleur[4]={1,3,201,2};
    for (int i = 0; i < 4; i++)
    {
        for (int  j = 0; j < 4; j++)
        {
            P->TabTuiles[posCorner[i]].passage[(i+j)%4]=Lshape[j];
        }
        P->TabTuiles[posCorner[i]].couleur=couleur[i];
    }
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
