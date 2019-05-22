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
#include<math.h>

#define PI 3.1415926
#define SquarLength 0.3  /*正方形边长*/ 
void DrawSquar(double x,double y, double dx, double dy);/*绘制（x,y)为中心绘制矩形*/ 


void Main(){
	InitGraphics();
 
	SetPenColor("Dark Gray");
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			DrawSquar(3.2+i*SquarLength,1+j*SquarLength,SquarLength,SquarLength);/*左上角坐标(4.0,6.0)，(4.0,2.0+边长*20)*/ 
		}
	}

}

void DrawSquar(double x,double y, double dx, double dy){
	MovePen(x-dx/2,y-dx/2);
	DrawLine(dx,0);
	DrawLine(0,dy);
	DrawLine(-dx,0);
	DrawLine(0,-dy); 
	
}	
