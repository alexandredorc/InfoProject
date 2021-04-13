#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/plateau.h"
#include "headers/joueur.h"
#include "headers/tuiles.h"


#define COULEUR_MUR1 "\033[48;5;21m"
#define COULEUR_MUR2 "\033[48;5;27m"
#define COULEUR_MUR_FIXE "\033[48;5;17m"
#define COULEUR_PASSAGE "\033[48;5;252m"
#define EFFACER "clear"

//placement initiale de la tuile solo
void resetsolo(plateau *P){
	P->solopos[0]=1;//eloignement par rapport au plateau en haut à gauche
	P->solopos[1]=0;//deplacement sur ligne ou colonne (1=colonne, 0=ligne)
	P->solopos[2]=0;//quelle colonne ou ligne (numero de la colonne ou ligne)
}

//méthode de création des joueurs
void create_joueurs(Game *G, int nbJoueurs){
	G->nbJoueurs=nbJoueurs;
    Joueur *j=malloc(sizeof(Joueur)*G->nbJoueurs);
	int taille=G->plateau->taille;
	int pos[4]={taille*taille-1,taille*(taille-1),0,taille-1};
	
    for (int i = 0; i < G->nbJoueurs; i++)
	{
		printf("entrer le nom du joueur %d: ",i+1);
		scanf("%s",j[i].nom);
		j[i].couleur=G->couleur[i];
		j[i].position=pos[i];
		j[i].positionFinale=pos[i];
		j[i].x=pos[i]%taille;
		j[i].y=pos[i]/taille;
    }
	
    G->joueurs=j;
}

//méthode de déplacement des joueurs sur le plateau
bool menujoueur(Joueur* joueur, plateau* plateau, bool *run,int nbTresor){

	printf("au tour de %s\n",joueur->nom);
	if(joueur->score!=nbTresor){
		printf("ton score est %d\n",joueur->score);
		printf("Ta cible est %c\n", joueur->tresor[joueur->score]);
	}
	else{
		printf("tu as récolté tous les trésors retourne vite à ta case!!\n");
	}
	printf("deplacement fléches directionelles, ENTER valider\n");
	
	int posJ=joueur->position;
	int x =joueur->x;
	int y =joueur->y;
	int res=-1;
	while(res==-1 || res==27 || res==91){
		if(system("/bin/stty raw")) {exit(EXIT_FAILURE);} 
            res = getchar();
            if(system("/bin/stty cooked")) {exit(EXIT_FAILURE);}
	}
	switch (res)
	{
	case 65:
		if (y!=0){
			
			int posC= plateau->grille[y-1][x];
			
			if(plateau->TabTuiles[posJ].passage[0] && plateau->TabTuiles[posC].passage[2]){
				joueur->y--;
				joueur->position=posC;
			}
		}
		break;
		case 67:
		if (x!=plateau->taille-1){


			int posC= plateau->grille[y][x+1];
			
			if(plateau->TabTuiles[posJ].passage[1] && plateau->TabTuiles[posC].passage[3]){
				joueur->x++;
				joueur->position=posC;
			}
		}
		break;
		case 66:
		if (y!=plateau->taille-1){
			
			int posC= plateau->grille[y+1][x];
			if(plateau->TabTuiles[posJ].passage[2] && plateau->TabTuiles[posC].passage[0]){
				joueur->y++;
				joueur->position=posC;
			}
		}
		break;
		case 68:
		if (x!=0){
			int posC= plateau->grille[y][x-1];
			if(plateau->TabTuiles[posJ].passage[3] && plateau->TabTuiles[posC].passage[1]){
				joueur->x--;
				joueur->position=posC;
			}
		}
		break;
	case 13:
		return true;
	case 127:
			*run=false;
			return false;
			break;
	default:
		break;
	}
	return false;
}

//méthode de déplacement de la tuile solo
bool menusolo(Game *G){
	printf("au tour de %s\n",G->joueurs[G->actif].nom);
	if(G->joueurs[G->actif].score!=G->nbTresor){
		printf("ton score est %d\n",G->joueurs[G->actif].score);
		printf("Ta cible est %c\n", G->joueurs[G->actif].tresor[G->joueurs[G->actif].score]);
	}
	else{
		printf("tu as récolté tous les trésors retourne vite à ta case!!\n");
	}
	printf("fleches directionelles pour ce deplacer \n A tourner anti hor ,Z tourner hor, ENTER valider\n");
	int res=-1;
	while(res==-1 || res==27 || res==91){
		if(system("/bin/stty raw")) {exit(EXIT_FAILURE);} 
            res = getchar();
            if(system("/bin/stty cooked")) {exit(EXIT_FAILURE);}
	}
	switch (res)
		{
		case 65:
			if (G->plateau->solopos[1]==1 && G->plateau->solopos[0]>1)
			{
				G->plateau->solopos[0]-=1;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[0]==1){
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=0;
				G->plateau->solopos[2]=0;
			}
			else if (G->plateau->solopos[1]==0 && G->plateau->solopos[2]==1)
			{
				G->plateau->solopos[2]=0;
			}
			break;
		case 67:
			if (G->plateau->solopos[1]==0 && G->plateau->solopos[0]<G->plateau->taille)
			{
				G->plateau->solopos[0]+=1;
			}
			else if(G->plateau->solopos[1]==0 && G->plateau->solopos[0]==G->plateau->taille){
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=1;
				G->plateau->solopos[2]=1;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[2]==0)
			{
					G->plateau->solopos[2]=1;	
			}
			break;
		case 66:
			if (G->plateau->solopos[1]==1 && G->plateau->solopos[0]<G->plateau->taille)
			{
				G->plateau->solopos[0]+=1;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[0]==G->plateau->taille){
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=0;
				G->plateau->solopos[2]=1;
			}
			else if(G->plateau->solopos[1]==0 && G->plateau->solopos[2]==0)
			{	
				G->plateau->solopos[2]=1;
			}
			
			break;
		case 68:
			if (G->plateau->solopos[1]==0 && G->plateau->solopos[0]>1)
			{
				G->plateau->solopos[0]-=1;
			}
			else if(G->plateau->solopos[1]==0 && G->plateau->solopos[0]==1){
				if (G->plateau->solopos[2]==0){
					G->plateau->solopos[0]=1;
				}
				else{
					G->plateau->solopos[0]=G->plateau->taille;
				}
				G->plateau->solopos[1]=1;
				G->plateau->solopos[2]=0;
			}
			else if(G->plateau->solopos[1]==1 && G->plateau->solopos[2]==1)
			{
				G->plateau->solopos[2]=0;
			}
			break;
		case 122:
			tourner(&G->plateau->TabTuiles[G->plateau->solo],1,true);
			break;
		case 97:
			tourner(&G->plateau->TabTuiles[G->plateau->solo],1,false);
			break;
		case 13:
			if ((G->plateau->colonne_mobile[G->plateau->solopos[0]-1] && G->plateau->solopos[1]==0 
			|| G->plateau->ligne_mobile[G->plateau->solopos[0]-1] && G->plateau->solopos[1]==1) && 
			!(G->plateau->lastPos[0]==G->plateau->solopos[0] && G->plateau->lastPos[1]==G->plateau->solopos[1] 
			&& G->plateau->lastPos[2]!=G->plateau->solopos[2])){

				int res=deplacement(G->plateau);
				for (int i = 0; i < G->nbJoueurs; i++)
				{
					if (G->plateau->grille[G->joueurs[i].y][G->joueurs[i].x]!=G->joueurs[i].position)
					{
						switch (res)
						{
						case 1:
							G->joueurs[i].x++;
							break;
						case 2:
							G->joueurs[i].x--;
							break;
						case 3:
							G->joueurs[i].y++;
							break;
						case 4:
							G->joueurs[i].y--;
							break;
						default:
							break;
						}
					}
					joueur_tuile_solo(&G->joueurs[i],G->plateau);
				}
				
				
				G->plateau->solopos[2]=(G->plateau->solopos[2]+1)%2;
				return true;
			}
			break;
		case 127:
			G->run=false;
			return false;
			break;
		default:
			break;
		}
	return false;
}

//Boucle de la partie et condition de victoire
int startgame(Game *G){
	resetsolo(G->plateau);
	int state=1;
	
	while(G->run){
		int posJ=G->joueurs[G->actif].position;
		system(EFFACER);
		afficher(G);
		if (state==1) {
			if (menusolo(G)){
				state=2;
			}
		}
		else if(state==2){
			if (menujoueur(&(G->joueurs[G->actif]),G->plateau,&G->run,G->nbJoueurs)){
				state=1;
				if(G->plateau->TabTuiles[posJ].tresor==G->joueurs[G->actif].tresor[G->joueurs[G->actif].score]){
					incr_score(&(G->joueurs[G->actif]));        
    			}
				G->actif=(G->actif+1)%G->nbJoueurs;
				if (G->joueurs[G->actif].score==G->nbTresor && G->joueurs[G->actif].position==G->joueurs[G->actif].positionFinale){
					printf("C'est juste win en fait pour %s\n", G->joueurs[G->actif].nom);
					G->run=false;
				}
			}
		}
	}
	
	return 0; 
}

//Initialisation de la partie
Game *propgame(){
	Game *G=malloc(sizeof(Game));
	G->run=true;
	printf("le plateau a une taille de :");
	int taille;
	scanf("%d",&taille);
	printf("Le nombre de tresor a trouver par personne est :");
	scanf("%d",&G->nbTresor);
	int nbJoueurs;
	printf("entrer le nombre de joueurs: ");
	scanf("%d", &nbJoueurs);
	int color[4]={1,2,3,201};
	G->couleur=color;
	G->plateau=malloc(sizeof(plateau));
	for (int i = 0; i < 4; i++)
	{
		G->plateau->couleur[i]=color[i];
	}
	
	initplat_alloc(G->plateau,taille, nbJoueurs, G->nbTresor);
	fix(G->plateau);
	G->actif=0;
	create_joueurs(G, nbJoueurs);
	attribute_tresor(G->plateau, G->joueurs, G->nbTresor,G->nbJoueurs);
	return G;
}

//Affichage des résultats finaux
void resultat(Game *G){
	for(int i=0;i<G->nbJoueurs;i++){
		printf("Le score de %s est %d\n", G->joueurs[i].nom, G->joueurs[i].score);
	}
}

//libération mémoire de tout ce qui reste avant fermeture du programme
void endgame(Game *G){
	resultat(G);
	free_joueurs(G->joueurs,G->nbJoueurs);
	free(G->joueurs);
    free_plat(G->plateau);
	free(G->plateau);
	free(G);
}

//coordonnée de la tuile solo
void soloReal(plateau *P,int* pos){
	//[0] est la distance depuis 0;0 
	//[1] si c'est une ligne ou colone 
	//[2] si c'est dans la col ou ligne oposé ou non
	if(P->solopos[1]==1){
		pos[0]=P->solopos[0];
		pos[1]=P->solopos[2]*(P->taille+1);
	}
	else{
		pos[1]=P->solopos[0];
		pos[0]=P->solopos[2]*(P->taille+1);
	}
}

//méthode d'affichage du jeu
void afficher(Game *G){
	int contraste=0;
	int taille=G->plateau->taille;
	tuile * TabTuiles=G->plateau->TabTuiles;
	int ** grille=G->plateau->grille;
	int * soloposi=malloc(sizeof(int)*2);
	soloReal(G->plateau,soloposi);
	int solo=G->plateau->solo;
	int offset=-10;
	for(int i=offset;i<(taille+2)*3;i++){
		for(int j=offset;j<(taille+2)*3;j++){
			int x=i/3;
			int y=j/3;
			if(i<0 || j<0){
				x=-1;
				y=-1;
			}
			int a=i%3;
			int b=j%3;
			
			if (x>=1 && x<=taille && y>=1 && y<=taille){
				int pos=grille[x-1][y-1];
				if(a==1 && b==1){
					bool play=true;
					for (int k = 0; k < G->nbJoueurs; k++)
					{
						if(pos==G->joueurs[k].position){
							printf("\033[48;5;%dm%c%c\033[m",G->joueurs[k].couleur,G->joueurs[k].nom[0],TabTuiles[pos].tresor);
							play=false;
							break;
						}
					}
					if(play) {
						printf(COULEUR_PASSAGE"\033[30m%c \033[m",TabTuiles[pos].tresor);
					}
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
			else if(soloposi[0]==x && soloposi[1]==y){//affichage de la case solo
				if(a==1 && b==1){
					printf(COULEUR_PASSAGE "\033[30m%c \033[m",TabTuiles[solo].tresor);
				}
				else{
					if(TabTuiles[solo].couleur!=-1 ){
						printf( "\033[48;5;%dm",TabTuiles[solo].couleur);
					}
					else{

					printf(COULEUR_MUR2);
					}
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
	free(soloposi);
}