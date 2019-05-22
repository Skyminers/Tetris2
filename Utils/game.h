#include <block.h>

#define normalDown 1
#define speederDown 2
#define normalDownTime 600
#define speederdownTime 60

typedef struct{
    int map[12][22];
    Block current;
    Block hold;
    Block next;
} GameInfo;


GameInfo gameInfo;


void KeyboardEventProcess(int key,int event);
void CharEventProcess(char ch) 
void TimerEventProcess(int timerID);
void endOneRound();
void nextRound();
void checkEliminate();
void Start();
void gameOver();
int checkLine(int line);