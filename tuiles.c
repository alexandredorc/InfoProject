#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tuiles.h"

struct tuiles{
    int x;
    int y;
    bool direction[4];//[haut,droite,bas,gauche]
};
typedef struct tuiles tuiles;