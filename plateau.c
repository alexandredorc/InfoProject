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
    for (int i = 0; i < 4; i++)
    {
        for (int  j = 0; j < 4; j++)
        {
            P->TabTuiles[posCorner[i]].passage[(i+j)%4]=Lshape[j];
        }
        P->TabTuiles[posCorner[i]].couleur=P->couleur[i];
    }
    P->ligne_mobile = malloc(taille*sizeof(bool));
    P->colonne_mobile = malloc(taille*sizeof(bool));
    P->solo=taille*taille;
    init_Tuiles(&(P->TabTuiles[P->solo]),' ',false);
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

plateau deplacementhorizontal(plateau* p, const int ligne, const bool direction){
    //direction 0=vers la gauche, 1=la droite
    int temp;
    if (direction==false){
        temp=p->grille[ligne][0];
        
        for (int i=0;i<7;i++){
            p->grille[ligne][i]=p->grille[ligne][i+1];
        }
        p->grille[ligne][7]=p->solo;
        p->solo=temp;
    }

    else if (direction==true){
        temp=p->grille[ligne][7];
        
        for (int i=7;i>0;i--){
            p->grille[ligne][i]=p->grille[ligne][i-1];
        }
        p->grille[ligne][0]=p->solo;
        p->solo=temp;
    }
}

plateau deplacementvertical(plateau* p, const int colonne, const bool direction){
    //direction 0=vers le haut, 1=le bas
    int temp;
    printf("test5");
    if(direction==false){
        printf("test6");
        temp=p->grille[1][colonne];
        
        for (int i=0;i<7;i++)
        {
            p->grille[i][colonne]=p->grille[i+1][colonne];
        }
        printf("test7");
        p->grille[colonne][7]=p->solo;
        p->solo=temp;
    }
    else 
    {
        temp=p->grille[7][colonne];
        printf("test");
        for (int i=7;i>=1;i--)
        {
            p->grille[i][colonne]=p->grille[i-1][colonne];
        }
        printf("test2");
        p->grille[0][colonne]=p->solo;
        p->solo=temp;
    }
}
