#ifndef _JOUEUR_
#define _JOUEUR_
#define N 30

struct Joueur
{
        char nom[N];
        int score;
        int position;
        char tresor[6];
        int couleur;
        int x;
        int y;
};
typedef struct Joueur Joueur;

void incr_score(Joueur *j);



#endif