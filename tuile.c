#include <stdbool.h>
#include <stdio.h>

struct tuile{
    bool mobile;
    int x;
    int y;
    bool passage
};

typedef struct tuile tuile;

/*struct table{
    tuile *tuiles;
};*/

void init_Tuiles(bool bas, bool haut, bool droite, bool gauche){
        bool * tuile =malloc(9*sizeof(bool));
        for (int i=0;i<9;i++){
            tuile[i]=0;
        }
        tuile[1]=haut;
        tuile[3]=gauche;
        tuile[5]=droite;
        tuile[7]=bas;
        tuile[4]=1;
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%d ", tuile[j+3*i]);
                }
                printf("\n");
        }
        printf("\n");
        free()
        return 0;
}

int main(){
    init_Tuiles(1,1,1,1);
    init_Tuiles(0,0,1,1);
    init_Tuiles(1,1,0,0);
    init_Tuiles(0,0,0,0);
    return 0;
}