#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
cleardevice();
setcolor(YELLOW);
settextstyle(0,0,2);
//outtextxy(70,50,"This is the graph which is choosen to be solved using prim's algorithm");
settextstyle(0,0,1);

setcolor(RED);
circle(172,262,7);//starting point
outtextxy(170,260,"S");
setcolor(WHITE);
line(180,262,240,262);//line s to a

setcolor(RED);
circle(248,262,7);//a
outtextxy(245,258,"a");
setcolor(WHITE);
line(254,257,310,210);//line a to b

setcolor(RED);
circle(318,207,7);//b
outtextxy(315,204,"b");
setcolor(WHITE);
line(326,207,393,207); //line b to c

setcolor(RED);
circle(400,208,7);//c
outtextxy(397,204,"c");
//setcolor(WHITE);

setcolor(RED);
circle(318,307,7);      //d
outtextxy(315,304,"d");
setcolor(WHITE);
line(310,305,254,270);// line a to d

setcolor(RED);
circle(400,309,7); //e
outtextxy(397,306,"e");
setcolor(WHITE);
line(393,308,325,308);//line d to e

setcolor(RED);
circle(470,260,7);  //f
outtextxy(467,257,"f");
setcolor(WHITE);
line(407,310,465,267);//line e to f
line(408,210,467,253);// line c to f

setcolor(RED);
circle(318,260,7);  //g
outtextxy(315,255,"g");
setcolor(WHITE);
line(317,252,317,215);//line b to g
line(317,300,317,268);//line d to g

setcolor(RED);
circle(550,260,7);     //ending point
outtextxy(547,257,"V");
setcolor(WHITE);
line(478,260,542,260);

while(!kbhit){}          //edited
getch();
}
