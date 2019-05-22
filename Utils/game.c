#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <game.h>
#include <judge.h>
#include <block.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>


void TimerEventProcess(int timerID){
	if((timerID == normalDown) || (timerID == speederDown)){
		gameInfo.current.y --;
		if(!judgeInter(gameInfo)){
			gameInfo.current.y ++;
			if(endOneRound()) gameOver();
			else nextRound();
		}
	}
}

void CharEventProcess(char ch) {
    uiGetChar(ch);
    switch(ch){
		case 'z': case 'Z':
//			Block tmp = 
            break;
        default:
            break;
    }
}

void KeyboardEventProcess(int key,int event){
 	
    switch (event) {
	 	case KEY_DOWN:
			switch (key) {
			    case VK_UP:
					(gameInfo.current.direction += 1) %= 4;
					if(!judgeInter(gameInfo)){
						(((gameInfo.current.direction -= 1) += 4) %= 4)
					}
                    break;
			    case VK_DOWN:
					cancelTimer(normalDown);
					startTimer(speederDown,speederDownTime);
                    break;
			    case VK_LEFT:
					gameInfo.current.x --;
					if(!judgeInter(gameInfo)){
						gameInfo.current.x ++;
					}
                    break;
			    case VK_RIGHT:
					gameInfo.current.x ++;
					if(!judgeInter(gameInfo)){
						gameInfo.current.x --;
					}
                    break;
				case VK_SPACE:
					while(1){
						gameInfo.current.y --;
						if(!judgeInter(gameInfo)) break;
					}
					gameInfo.current.y ++;
					if(endOneRound()) gameOver();
					else nextRound();
					break;
			}
			break;
		case KEY_UP:
			switch(key){
				case VK_DOWN:
					cancelTimer(speederDown);
					startTimer(normalDown,normalDownTime);
					break;
			}
			break;
	 }	 
}

int endOneRound(){
	Block x = gameInfo.current;
	int dir = x.direction % BlockMod[x.type];
    int i;
    for (i = 0; i < 4; i++) {
        int pos_x = x.x + Direction[(BlockShape[x.type][i] + 4 * dir) % 16][0];
        int pos_y = x.y + Direction[(BlockShape[x.type][i] + 4 * dir) % 16][1];
		if(pos_y > 20) return 1;
		gameInfo.map[pos_x][pos_y] = gameInfo.current.type;
    }
	int sco = checkEliminate();
	return 0;
}

int checkEliminate(){
	int i,j,k;
	int EliminateLines = 0;
	for(i=1;i<=20;++i){
		if(checkLine(i)){
			++ EliminateLines;
			for(j=i;j<20;++j) for(k=1;k<=10;++k){
				gameInfo.map[j][k] = gameInfo.map[j+1][k];
			}
			for(k=1;k<=10;++k) gameInfo.map[20][k] = 0;
		}
	}
	return EliminateLines*(EliminateLines+1)/2;
}

int checkLine(int line){
	int i;
	for(i = 1;i<=10;++i){
		if(gameInfo.map[i][line] == 0) return 0;
	}
	return 1;
}

void nextRound(){
	gameInfo.current = gameInfo.next;
	gameInfo.current.x = 5;
	gameInfo.current.y = 20;
	gameInfo.next = randomBlock();
}

void Start(){
	int i,j,k;
	for(i=1;i<=10;++i) for(j=1;j<=20;++j) gameInfo.map[i][j] = 0;
	gameInfo.current = randomBlock();
	gameInfo.next = randomBlock();
	gameInfo.current.x = 5;
	gameInfo.current.y = 20;
}

void gameOver(){
	cancelTimer(normalDown);
	cancelTimer(speederDown);
	drawGameOver();
	// and a lot of thing.
}