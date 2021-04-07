#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/plateau.h"
#include "headers/joueur.h"
#include "headers/tuiles.h"

#define COULEUR_MUR1 "\033[48;5;20m"
#define COULEUR_MUR2 "\033[48;5;21m"
#define COULEUR_MUR_FIXE "\033[48;5;17m"
#define COULEUR_PASSAGE "\033[48;5;252m"


void create_joueurs(Game *G){
	printf("entrer le nombre de joueurs: ");
	scanf("%d", &(G->nbJoueurs));
    Joueur *j=malloc(sizeof(Joueur)*G->nbJoueurs);
    for (int i = 0; i < G->nbJoueurs; i++)
	{
		printf("entrer le nom du joueur %d: ",i+1);
		scanf("%s",j[i].nom);
		
    }
	
    G->joueurs=j;
	G->joueurs[0].position=0;
}



int startgame(Game *G){
	while(G->run){
		int posJ=G->joueurs[G->actif].position;
		if(G->plateau->TabTuiles[posJ].tresor==G->joueurs[G->actif].tresor[G->joueurs[G->actif].score]){
			incr_score(&G->joueurs[G->actif]);
			
        
    	}
	}
	
	return 0; 
}


Game *propgame(){
	Game *G=malloc(sizeof(Game));
	create_joueurs(G);
	G->run=true;
	printf("le plateau a une taille de :");
	int taille;
	scanf("%d",&taille);
	G->plateau=malloc(sizeof(plateau));
	initplat_alloc(G->plateau,taille);
	fix(G->plateau);
	G->actif=0;
	return G;
}

void resultat(Game *G){
	printf("fin de la partie\n");	
}

void endgame(Game *G){
	resultat(G);
	free(G->joueurs);
        free_plat(G->plateau);
	free(G);
	printf("fin du programme\n");
}

void afficher(Game *G){
	int contraste=0;
	int taille=G->plateau->taille;
	tuile * TabTuiles=G->plateau->TabTuiles;
	int ** grille=G->plateau->grille;
	for(int i=0;i<(taille+2)*3;i++){
		for(int j=0;j<(taille+2)*3;j++){
			int x=i/3;
			int y=j/3;
			int a=i%3;
			int b=j%3;
			
			if (x>=1 && x<=taille && y>=1 && y<=taille){  
				int pos=grille[x-1][y-1];
				if(a==1 && b==1){
					
						printf(COULEUR_PASSAGE "\033[30m%c \033[m",TabTuiles[pos].tresor);
					
					
					
				}
				else if(a!=1 && b!=1){ //mur
					if(TabTuiles[pos].couleur!=-1 ){
						printf( "\033[48;5;%dm\033[30m  \033[m",TabTuiles[pos].couleur);
					}
					else if (contraste%2==0){
						if (TabTuiles[pos].mobile){
							printf(COULEUR_MUR2);
						}
						else{
							printf(COULEUR_MUR_FIXE);
						}
						printf("  ");

					}
					else{
						if (TabTuiles[pos].mobile){
							printf(COULEUR_MUR1);
						}
						else{
							printf(COULEUR_MUR_FIXE);
						}
						printf("  ");
					}
				}
				else{ //route
					
					if (contraste%2==0){
						if (TabTuiles[pos].mobile){
						printf(COULEUR_MUR1);
						}
						else{
							printf(COULEUR_MUR_FIXE);
						}

					}
					else {
						if (TabTuiles[pos].mobile){
						printf(COULEUR_MUR2);
						}
						else{
							printf(COULEUR_MUR_FIXE);
						}
					}
					if(TabTuiles[pos].couleur!=-1 ){
						printf( "\033[48;5;%dm",TabTuiles[pos].couleur);
					}
					if(i%3==0 && j%3==1 && TabTuiles[pos].passage[0]){
						printf(COULEUR_PASSAGE);
					}
					else if(i%3==1 && j%3==2 && TabTuiles[pos].passage[1]){
						printf(COULEUR_PASSAGE);
					}
					else if(i%3==2 && j%3==1 && TabTuiles[pos].passage[2]){
						printf(COULEUR_PASSAGE);
					}
					else if (i%3==1 && j%3==0 && TabTuiles[pos].passage[3])
					{
						printf(COULEUR_PASSAGE);
					}
					printf("  ");
				}
				printf("\033[m");
				contraste += 1;
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}