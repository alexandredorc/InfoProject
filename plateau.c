#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "headers/tuiles.h"
#include "headers/plateau.h"

//retourne un entier entre 0 et k
int randomInt (int k)
{
   static int first = 0;
   
   if (first == 0)
   {
      srand (time (NULL));
      first = 1;
   }
   return (rand ()%k);
}

//allocation mémoire du plateau et de ses composants + placement aléatoire des trésors
void initplat_alloc(plateau* P,int taille, int nbJoueur, int nbTresor)
{
    P->taille=taille;
    P->TabTuiles = malloc(((taille*taille)+1)*sizeof(*P->TabTuiles));
    P->grille = malloc(sizeof *P->grille * taille);
    P->listeTresor = malloc(24*sizeof(char));
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
    for(int j=0;j<24;j++){
        P->listeTresor[j]=(char) 65+j;
    }
    int nbTresort=nbTresor*nbJoueur;
    for(int k=0;k<nbTresort;k++){
        int pos=0;
        while(pos==0 || pos==taille-1 || pos==taille*taille-taille || pos==taille*taille-1 || P->TabTuiles[pos].tresor!=' '){
            pos=randomInt(taille*taille);
        }
        P->TabTuiles[pos].tresor=P->listeTresor[k];
    }
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
    init_Tuiles(&(P->TabTuiles[P->solo]),' ',true);
    fix(P);
}


//modification de certaines tuiles pour les rendre immobile
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

//libération mémoire du plateau et des tuiles
void free_plat(plateau* p)
{
    free(p->ligne_mobile);
    free(p->colonne_mobile);
    free(p->listeTresor);
    for(int i=0;i<p->taille;i++){
        int *current=p->grille[i];
        free(current);
    }
    for (int i = 0; i < (p->taille*p->taille)-1; i++)
    {
        free(p->TabTuiles[i].passage);
        
    }
    free(p->TabTuiles);
    free(p->grille);
}

//deplacement de la tuile solo autour du plateau 
int deplacement(plateau* p){
    p->lastPos[0]=p->solopos[0];
    p->lastPos[1]=p->solopos[1];
    p->lastPos[2]=p->solopos[2];
    int temp;
    int num=p->solopos[0]-1;
    int res;
    if(p->solopos[1]==1){
        if (p->solopos[2]==0){
            res=1;
            temp=p->grille[num][p->taille-1];
            for (int i=p->taille-1;i>0;i--){
                p->grille[num][i]=p->grille[num][i-1];
            }
            p->grille[num][0]=p->solo;
            p->solo=temp;
        }
        else{
            res=2;
            temp=p->grille[num][0];
            for (int i=1;i<p->taille;i++){
                p->grille[num][i-1]=p->grille[num][i];
            }
            p->grille[num][p->taille-1]=p->solo;
            p->solo=temp;
        }
    }else{

        if (p->solopos[2]==0){
            res=3;
            temp=p->grille[p->taille-1][num];
            for (int i=p->taille-1;i>0;i--){
                p->grille[i][num]=p->grille[i-1][num];
            }
            p->grille[0][num]=p->solo;
            p->solo=temp;
        }
        else{
            res=4;
            temp=p->grille[0][num];
            for (int i=1;i<p->taille;i++){
                p->grille[i-1][num]=p->grille[i][num];
            }
            p->grille[p->taille-1][num]=p->solo;
            p->solo=temp;
        }
    }
    return res;
}
