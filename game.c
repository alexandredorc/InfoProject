#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/plateau.h"
#include "headers/joueur.h"
#include "headers/tuiles.h"




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
}

int startgame(Game *G){
	while(G->run){

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
	tuile * tuiles=G->plateau->tuiles;
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
					printf("\033[43m\033[30m%c \033[m",tuiles[pos].tresor);
					
				}
				else if(a!=1 && b!=1){ //mur
					if (contraste%2==0){
						if (tuiles[pos].mobile){
							printf("\033[107m");
						}
						else{
							printf("\033[99m");
						}
						printf("  ");
					}
					else{
						if (tuiles[pos].mobile){
							printf("\033[100m");
						}
						else{
							printf("\033[99m");
						}
						printf("  ");
					}
				}
				else{ //route
					if (contraste%2==0){
						if (tuiles[pos].mobile){
						printf("\033[100m");
						}
						else{
							printf("\033[99m");
						}
					}
					else {
						if (tuiles[pos].mobile){
						printf("\033[107m");
						}
						else{
							printf("\033[99m");
						}
					}
					if(i%3==0 && j%3==1 && tuiles[pos].passage[0]){
						printf("\033[43m");
					}
					else if(i%3==1 && j%3==2 && tuiles[pos].passage[1]){
						printf("\033[43m");
					}
					else if(i%3==2 && j%3==1 && tuiles[pos].passage[2]){
						printf("\033[43m");
					}
					else if (i%3==1 && j%3==0 && tuiles[pos].passage[3])
					{
						printf("\033[43m");
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