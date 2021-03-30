#include <stdbool.h>
#include <stdio.h>
#include "headers/tuiles.h"


tuile* inittuile_alloc()
{
    tuile *res = malloc(sizeof(res));
    res->x = malloc(sizeof(int));
    res->y = malloc(sizeof(int));
    res->mobile = malloc(sizeof(bool));
    for (int i = 0; i < 4; i++)
    {
        res->passage[i] = malloc(sizeof(bool));
    }
    return res;
}


void free_plat(tuile* t)
{
    free(t->x);
    free(t->y);
    free(t->mobile);
    for(int i=0;i<4;i++){
        free(t->passage[i]);
    }
    free(t);
}

