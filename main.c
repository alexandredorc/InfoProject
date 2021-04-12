#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/game.h"


#define N 30

int main() {
        Game *G=propgame();
        startgame(G);
        endgame(G);
        return 0;
}