#include <stdio.h>
#include <stdlib.h>

//fonction surement obsolete mais qui sert à lister les différents types de variables
void variables(){
    //nom des variables. Déclaration de variables
    int aireDuCarre=0; //bon nom de variable
    int aireducarre; //variable moins clair, à éviter
    int nombreEntier;
    float nombreDecimal;
    long longNombreEntier;
    signed char petitNombreQuiPeutEtreNegatif;
    unsigned char petitNombrePositif;
    const float PI=3.14; //variable non modifiable (à mettre en MAJ par convention)
    nombreDecimal = 134,56;
    nombreEntier = (int)nombreDecimal;//134
    /*  
        %d : nombre entier (int)
        %f : nombre decimal (float)
        %c : charactère (char)
        %s : chaine de charactère (texte)
    */
    printf("%f",nombreDecimal);
}

void lireDonneeAuClavier(){//fonctionne pas bien
    char question[100];
    char reponse[100];
    printf("Votre question : ");
    scanf("%s\n", &question);
    printf("%s\n", question);
    printf("Votre reponse : ");
    scanf("%s\n", &reponse);
    /*
    maVariable : contenu de la variable
    &maVariable : pointeur/emplacement de la variable
    */
    printf("La reponse de %s est : %s\n",question, reponse);
}

float additioner(float x,float y){
    return x+y;
}
float soustraction(float x,float y){
    return x-y;
}
float multiplier(float x, float y){
    return x*y;
}
float diviser(float x, float y){
    return x/y;
}
float resteFloat(float x, float y){
    while(x>0){
        if(x-y<=0){
            return x;
        }
        else{
            x-=y;
        }
    }
}


/* programme qui sert à s'entrainer, à tester des trucs, aucun rapport avec le projet*/
int main(int argc, char **argv){
    printf("Hello World");
    float x=5.6;
    float y=2.53;
    float rest=resteFloat(x,y);
    float add=additioner(x,y);
    float sous=soustraction(x,y);
    float mult=multiplier(x,y);
    float div=diviser(x,y);

    printf("Pour les variables x= %f et y=%f\nx+y = %f\nx-y=%f\nx*y=%f\nx/y=%f\nEt enfin, le reste de la division euclidienne de x par y est egale a %f.\n", x, y, add, sous, mult, div, rest);

    return 0;
}  