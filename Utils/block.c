
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "extgraph.h"
#include "block.h"

int Direction[16][2] = {
        {0,  0},
        {-1, 0},
        {-2, 0},
        {-1, 1},
        {0,  0},
        {0,  1},
        {0,  2},
        {1,  1},
        {0,  0},
        {1,  0},
        {2,  0},
        {1,  -1},
        {0,  0},
        {0,  -1},
        {0,  -2},
        {-1, -1}
};
int BlockShape[8][4] = {
        {0, 0, 0,  0},
        {0, 1, 9,  10},
        {0, 1, 3,  9},
        {0, 1, 9,  7},
        {0, 9, 11, 13},
        {0, 1, 5,  7},
        {0, 1, 5,  9},
        {0, 3, 5,  9}
};
int BlockMod[8] = {1, 2, 4, 4, 1, 4, 4, 4};

void getPos(Block x) {
    int dir = x.direction % BlockMod[x.type];
    int i;
    for (i = 0; i < 4; i++) {
        int pos_x = x.x + Direction[(BlockShape[x.type][i] + 4 * dir) % 16][0];
        int pos_y = x.y + Direction[(BlockShape[x.type][i] + 4 * dir) % 16][1];
    }
}

Block randomBlock(){
    static int inited = 0;
    if(inited == 0){
        inited = 1;
        srand(time(NULL));
    }
    Block ret;
    ret.type = rand() % 7 + 1;
    ret.direction = 0;
    return ret;
}