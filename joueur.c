#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/joueur.h"
#define N 30

void incr_score(Joueur *j){
    j->score+=1;
}
