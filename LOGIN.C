#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setcolor(CYAN);
setbkcolor(0);
//Main box
rectangle(150,100,480,360);
//Textbox and password
setcolor(WHITE);
rectangle(450,200,300,180);
rectangle(450,220,300,240);
setfillstyle(SOLID_FILL,RED);
floodfill(200,200,BLACK);
//Buttons
setcolor(CYAN);
rectangle(300,300,380,280);
rectangle(300,300,450,280);
setfillstyle(SOLID_FILL,BLACK);
floodfill(250,250,BLACK);
//Text
outtextxy(220,185,"LOGIN ID");
outtextxy(220,225,"PASSWORD");
setcolor(WHITE);
outtextxy(315,285,"LOGIN");
setcolor(WHITE);
outtextxy(395,285,"RESET");
outtextxy(150,103,"*******---------------------------*******");
outtextxy(150,350,"*******---------------------------*******");
arc(250,205,60,300,50);
getch();
closegraph();
}