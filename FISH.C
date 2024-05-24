#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
int x=10,y=200,x1=675,y1=380;
int stangle=35,endangle=140,radius=90;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(!kbhit())
{
cleardevice();
setbkcolor(BLACK);
if(x<640)
{
x+=5;
y+=1;
arc(x,y,stangle,endangle+35,radius);
arc(x,y-110,190,323,radius+2);
circle(x+40,y-60,5);
line(x-90,y-90,x-90,y-8);
}
else
{
x1-=5;
y1-=1;
arc(x1,y1,stangle-30,endangle+4,radius);
arc(x1,y1-110,217,350,radius+2);
circle(x1-40,y1-60,5);
line(x1+90,y1-90,x1+90,y1-10);
}
setcolor(CYAN);
delay(90);
}
closegraph();
}