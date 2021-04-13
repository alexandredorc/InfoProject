#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "headers/tuiles.h"

//retourne un entier entre 0 et k
int randomint (int k)
{
   static int first = 0;
   
   if (first == 0)
   {
      srand (time (NULL));
      first = 1;
   }
   return (rand ()%k);
}

//permet de tourner les tuiles
void tourner(tuile *t,int k,bool sens)
{
//sens==true->sens des aiguilles d'une montre
//sens==false->sens inverse des aiguilles d'une montre
        bool ndir[4];
        if (sens==false){
                for(int i=0;i<4;i++){
                ndir[i]=t->passage[(i+k)%4];
                }
        }
        if (sens==true){
                for(int i=0;i<4;i++){
                ndir[i]=t->passage[(i-k+4)%4];
                }
        }
        for(int i=0;i<4;i++){
                 t->passage[i]= ndir[i];   
        }
}


//déclaration des 4 formes de tuiles
void init_Tuiles(tuile *tuile,char tresor, bool mobile)
{
        tuile->passage=malloc(sizeof*(tuile->passage)*4);
        int forme = randomint(3);
        int orientation = randomint(3);
        if (forme==0){
                tuile->passage[0]=false;
                tuile->passage[1]=true;
                tuile->passage[2]=false;
                tuile->passage[3]=true;
        }
        if (forme==1){
                tuile->passage[0]=true;
                tuile->passage[1]=true;
                tuile->passage[2]=false;
                tuile->passage[3]=false;
        }
        if (forme==2){
                tuile->passage[0]=true;
                tuile->passage[1]=true;
                tuile->passage[2]=true;
                tuile->passage[3]=false;
        }
        if (forme==3){
                tuile->passage[0]=true;
                tuile->passage[1]=true;
                tuile->passage[2]=true;
                tuile->passage[3]=true;
        }
        tourner(tuile,orientation,true);
        tuile->mobile=mobile;
        tuile->tresor=tresor;
        tuile->couleur=-1;
}

