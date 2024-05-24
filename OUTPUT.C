#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main()
{
int i;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
settextstyle(8,0,8);
for(i=0;i<250;i++)
{
cleardevice();
setcolor(i);
settextstyle(8,0,8);
outtextxy(60,-120+5+250,"THANK YOU");
delay(5);
}
getch();
}
