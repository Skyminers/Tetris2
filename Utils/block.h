int Direction[16][2];
int TetrominoShape[8][4];
int TetrominoDirectionMod[8];

typedef struct {
    int x, y;
    int direction;
    int type;
} Block;

void getPos(Block x);