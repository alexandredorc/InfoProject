#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "headers/plateau.h"

int main()
{ 
        printf("debut\n");
        plateau* p = initplat_alloc(7);
        printf("milieu\n");
        free_plat(p);
        printf("fin\n");
        return 0;
}