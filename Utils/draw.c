#include <draw.h>

void drawGameGUI(){
	InitGraphics();
	SetPenColor("Dark Gray");
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			DrawSquar(3.2+i*SquarLength,1+j*SquarLength,SquarLength,SquarLength);/*���Ͻ�����(4.0,6.0)��(4.0,2.0+�߳�*20)*/ 
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
