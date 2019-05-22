int Direction[16][2];
int BlockShape[8][4];
int BlockMod[8];

typedef struct {
    int x, y;
    int direction;
    int type;
}Block;

void getPos(Block x);
Block randomBlock();