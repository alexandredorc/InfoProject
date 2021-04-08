#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/plateau.h"
#include "headers/joueur.h"
#include "headers/tuiles.h"

#define COULEUR_MUR1 "\033[48;5;18m"
#define COULEUR_MUR2 "\033[48;5;21m"
#define COULEUR_MUR_FIXE "\033[48;5;17m"
#define COULEUR_PASSAGE "\033[48;5;252m"
#define EFFACER "clear"

void resetsolo(plateau *P){
	P->solopos[0]=3;
	P->solopos[1]=1;
	P->solopos[2]=1;
}


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

int menusolo(Game *G){
	printf("1 top, 2 right, 3 down, 4 left\n");
	int res; 
	scanf("%d",&res);
	switch (res)
		{
		case 1:
			if (G->plateau->solopos[1]==1 && G->plateau->solopos[0]>1)
			{
				G->plateau->solopos[0]-=1;
			}
			else if (G->plateau->solopos[1]==0 && G->plateau->solopos[2]==1)
			{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[2]=1;
				}
				else{
					G->plateau->solopos[2]=0;
				}
			}
			else {
				if (G->plateau->solopos[2]==0){
					
					G->plateau->solopos[0]=1;
				}
				else{
					
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=0;
				G->plateau->solopos[2]=0;
			}
			break;
		case 2:
			if (G->plateau->solopos[1]==0 && G->plateau->solopos[0]<G->plateau->taille)
			{
				G->plateau->solopos[0]+=1;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[2]==0)
			{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[2]=1;
				}
				else{
					G->plateau->solopos[2]=0;
				}
			}
			else{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=1;
				G->plateau->solopos[2]=1;
			}
			break;
		case 3:
			if (G->plateau->solopos[1]==1 && G->plateau->solopos[0]<G->plateau->taille)
			{
				G->plateau->solopos[0]+=1;
			}
			else if(G->plateau->solopos[1]==0 && G->plateau->solopos[2]==1)
			{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[2]=1;
				}
				else{
					G->plateau->solopos[2]=0;
				}
			}
			else{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=0;
				G->plateau->solopos[2]=1;
			}
			break;
		case 4:
			if (G->plateau->solopos[1]==0 && G->plateau->solopos[0]>1)
			{
				G->plateau->solopos[0]-=1;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[2]==1)
			{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[2]=1;
				}
				else{
					G->plateau->solopos[2]=0;
				}
				
			}
			else{
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=1;
				G->plateau->solopos[2]=0;
			}
			break;

		default:
			break;
		}
	return res;
}

int startgame(Game *G){
	resetsolo(G->plateau);
	while(G->run){
		int posJ=G->joueurs[G->actif].position;
		if(G->plateau->TabTuiles[posJ].tresor==G->joueurs[G->actif].tresor[G->joueurs[G->actif].score]){
			incr_score(&(G->joueurs[G->actif]));        
    	}
		system(EFFACER);
		afficher(G);
		int choix=menusolo(G);
		
		
		
		
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

int *soloReal(plateau *P){
	int *pos=malloc(sizeof(int)*2);
	//[0] est la distance depuis 0;0 [1] si c'est une ligne ou colone [2] si c'est dans la col ou ligne oposé ou non
	if(P->solopos[1]==1){
		pos[0]=P->solopos[0];
		pos[1]=P->solopos[2]*(P->taille+1);
	}
	else{
		pos[1]=P->solopos[0];
		pos[0]=P->solopos[2]*(P->taille+1);
	}
	return pos;
}

void afficher(Game *G){
	int contraste=0;
	int taille=G->plateau->taille;
	tuile * TabTuiles=G->plateau->TabTuiles;
	int ** grille=G->plateau->grille;
	int * soloposi= soloReal(G->plateau);
	printf("%d %d\n",soloposi[0],soloposi[1]);
	int solo=G->plateau->solo;
	for(int i=0;i<(taille+2)*3;i++){
		for(int j=0;j<(taille+2)*3;j++){
			int x=i/3;
			int y=j/3;
			int a=i%3;
			int b=j%3;
			if (x>=1 && x<=taille && y>=1 && y<=taille){
				int pos=grille[x-1][y-1];
				if(a==1 && b==1){
					printf(COULEUR_PASSAGE"\033[30m%c \033[m",TabTuiles[pos].tresor);
				}
				else if(a!=1 && b!=1){ //mur
					if(TabTuiles[pos].couleur!=-1 ){
						printf( "\033[48;5;%dm\033[30m  \033[m",TabTuiles[pos].couleur);
					}
					else if (x==G->plateau->solopos[0] && G->plateau->solopos[1]==1 || y==G->plateau->solopos[0] && G->plateau->solopos[1]==0){
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
					if (x==G->plateau->solopos[0] && G->plateau->solopos[1]==1 || y==G->plateau->solopos[0] && G->plateau->solopos[1]==0){
						if (TabTuiles[pos].mobile){
						printf(COULEUR_MUR2);
						}
						else{
							printf(COULEUR_MUR_FIXE);
						}
					}
					else {
						if (TabTuiles[pos].mobile){
						printf(COULEUR_MUR1);
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
			else if(soloposi[0]==x && soloposi[1]==y){
				if(a==1 && b==1){
					printf(COULEUR_PASSAGE "\033[30m%c \033[m",TabTuiles[solo].tresor);
				}
				else{
					printf(COULEUR_MUR2);
					if(i%3==0 && j%3==1 && TabTuiles[solo].passage[0]){
						printf(COULEUR_PASSAGE);
					}
					else if(i%3==1 && j%3==2 && TabTuiles[solo].passage[1]){
						printf(COULEUR_PASSAGE);
					}
					else if(i%3==2 && j%3==1 && TabTuiles[solo].passage[2]){
						printf(COULEUR_PASSAGE);
					}
					else if (i%3==1 && j%3==0 && TabTuiles[solo].passage[3])
					{
						printf(COULEUR_PASSAGE);
					}
					printf("  ");
				}
			}
			else{
				printf("  ");
			}

			printf("\033[m");
		}
		printf("\n");
	}
}