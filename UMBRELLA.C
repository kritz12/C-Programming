#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
void main()
{
int driver=DETECT,mode,i,j;
int x1,x2,x3,x4,x5;
int y1,y2,y3,y4,y5;
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
setcolor(2);
x1=100;y1=300;
x2=150;y2=330;
x3=125;y3=280;
x4=0;y4=332;
x5=600;y5=332;
for(i=0;i<300;i+=10)
for(x1=100,x2=150;x1<150,x2>100;x1+=2,x2-=2)
{
delay(15);
cleardevice();
line(x3+i,240,150+i,240);
line(x3+i,240,x1+i,270);
line(150+i,240,150+i,150);
setfillstyle(SOLID_FILL,BLUE);
ellipse(150+i,150,0,180,50,40);
floodfill(150+i,150,2);
line(100+i,150,200+i,150);
line(x1+i,y1,x3+i,y3);
line(x2+i,y2,x3+i,y3);
ellipse(125+i,255,0,360,10,40);
circle(125+i,200,14);
setfillstyle(SOLID_FILL,RED);
ellipse(124+i,195,0,360,3,2);
floodfill(125+i,195,2);
setfillstyle(SOLID_FILL,RED);
ellipse(138+i,202,0,360,3,2);
floodfill(138+i,202,2);
line(x4,y4,x5,y5);
}
return;
}