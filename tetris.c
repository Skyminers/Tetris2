#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "graphics.h"
#include "genlib.h"
#include "conio.h"

#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <math.h>
#include <game.h>

#define PI 3.1415926
#define SquarLength 0.3  /*�����α߳�*/ 
void DrawSquar(double x,double y, double dx, double dy);/*���ƣ�x,y)Ϊ���Ļ��ƾ���*/ 


void Main(){
	InitGraphics();
	registerKeyboardEvent(KeyboardEventProcess);
    registerMouseEvent(MouseEventProcess);
    registerTimerEvent(TimerEventProcess);
    registerCharEvent(CharEventProcess);
	Start();
}