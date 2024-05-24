#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<values.h>
#include<alloc.h>
#include<process.h>
#include<time.h>
#define size 100
struct Graph
{
int E;
int V;
};
struct edge
{
int start;
int end;
int weight;
};
void grap();
void application();
void matrix();
void description();
void algorithm();
void maincall();
void main()
{
int driver=DETECT,mode;
int n,i,j,c,d,k;
initgraph(&driver,&mode,"C://TURBOC3//BGI");
k=login();
if(k==1)
{
cleardevice();
setcolor(YELLOW);
settextstyle(8,0,3);
outtextxy(120,8,"THE NATIONAL DEGREE COLLEGE");
setcolor(CYAN);
settextstyle(0,0,0);
outtextxy(260,360,"[AUTONOMOUS]");
setcolor(12);
settextstyle(0,0,0);
outtextxy(210,375,"BASAVANAGUDI, BANGALORE-04");
setcolor(13);
settextstyle(11,0,0);
outtextxy(255,390,"YEAR:2022-2023");
setcolor(BLACK);
setcolor(CYAN);
delay(1000);
settextstyle(10,0,2);
outtextxy(40,120,"WELCOME TO THE PROJECT OF");
delay(1000);
settextstyle(10,0,2);
outtextxy(10,170,"PRIM'S WITH MINIMUM SPANNING TREE");
delay(1000);
settextstyle(10,0,2);
outtextxy(30,220,"SIMULATION ON SPANNING TREES");
setcolor(CYAN);
delay(1000);
cleardevice();
settextstyle(1,0,3);
setcolor(GREEN);
outtextxy(150,15,"SIMULATION ON TREES");
delay(1000);
for (i=0;i<=260;i++)
{
putpixel(150+i,49,YELLOW);
delay(10);
}
setcolor(CYAN);
settextstyle(0,0,2);
delay(500);
outtextxy(0,160,"1. KRITHIK GUHAN.S      20NCBC1066");
delay(700);
outtextxy(0,190,"2. MUTHU RAJ.S          20NCBC1069");
delay(700);
outtextxy(0,220,"3. TARUN.M              20NCBC1077");
delay(700);
settextstyle(1,0,2);
setcolor(MAGENTA);
outtextxy(0,290,"UNDER THE GUIDENCE OF ");
delay(1000);
for(i=0;i<258;i++)
{
putpixel(0+i,315,MAGENTA);
delay(10);
}
for(i=0;i<7;i++)
{
settextstyle(1,0,6);
setcolor(WHITE);
delay(100);
outtextxy(0,320,"Prof SATISH SIR");
setcolor(LIGHTGRAY);
settextstyle(2,HORIZ_DIR,4);
outtextxy(70,380,"Press any key to continue....");
delay(20);
}
delay(100);
//cleardevice();
while(1)
{
cleardevice();
setcolor(WHITE);
rectangle(0,0,600,450);
rectangle(5,5,595,445);
setfillstyle(SOLID_FILL,CYAN);
floodfill(1,1,WHITE);
settextstyle(4,0,6);
outtextxy(200,25,"MENU");
settextstyle(1,0,2);
setcolor(CYAN);
outtextxy(30,100,"1. ABOUT THE PROJECT.");
delay(100);
outtextxy(30,150,"2. ALGORITHM.");
delay(100);
outtextxy(30,200,"3. DEMONSTRATION.");
delay(100);
outtextxy(30,250,"4. APPLICATION OF THE PROJECT.");
delay(100);
outtextxy(30,300,"5. EXIT");
delay(100);
outtextxy(30,350,"ENTER YOUR OPTION");
delay(100);
gotoxy(33,23);
scanf("%d",&n);
switch(n)
//cleardevice();
{
//cleardevice();
case 1:cleardevice();
setcolor(WHITE);
rectangle(0,0,630,450);
rectangle(5,5,625,445);
setfillstyle(SOLID_FILL,LIGHTGREEN);
floodfill(1,1,WHITE);
setcolor(WHITE);
settextstyle(4,0,6);
outtextxy(30,20,"ABOUT THE PROJECT");
delay(600);
setcolor(YELLOW);
settextstyle(3,0,2);
outtextxy(1,120,"->Prim's Algorithm is a greedy algorithm that finds a \n ");
delay(600);
outtextxy(1,140,"\n minimum spanning tree for a connected weighted \n");
delay(600);
outtextxy(1,160,"\n undirected graph. It finds a subset of the edges that forms \n");
delay(600);
outtextxy(1,180,"\n a tree that includes every vertex, where the total weight \n");
delay(600);
outtextxy(1,200,"\n of all edges in the tree are minimised. This algorithm is \n");
delay(600);
outtextxy(1,220,"\n directly based on Minimum Spanning Tree property.");
getch();
break;
case 2:
cleardevice();
{
int x,y;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
setcolor(WHITE);
rectangle(0,0,630,450);
rectangle(5,5,625,445);
setfillstyle(SOLID_FILL,LIGHTGREEN);
floodfill(1,1,WHITE);
setcolor(WHITE);
settextstyle(4,0,6);
outtextxy(100,20,"ALGORITHM");
for(x=160,y=80;x<=420;x++)
{
putpixel(x,y,WHITE);
delay(10);
}
setcolor(CYAN);
settextstyle(3,0,2);
outtextxy(10,75,"There are some steps");
delay(600);
outtextxy(10,110,"->Step 1 : \n Input:The cost adjacency matrix C and number of vertices n \n");
delay(600);
outtextxy(10,125,"->Step 2 : \n Output:Minimum Weight Spanning Tree T \n");
delay(600);
outtextxy(10,145,"for(i=1;i<=n;i++)");
delay(600);
outtextxy(10,165,"VISITED[i]=0; \n ");
delay(600);
outtextxy(10,185,"U=1 \n");
delay(600);
outtextxy(10,200,"VISITED[u]=1; \n");
delay(600);
outtextxy(10,225,"While (there is still unchosen vertex)do \n");
delay(600);
outtextxy(10,245,"Step 3 : \n Let(u,v)be the least edge between any chosen u to any chossen vertex v \n");
delay(600);
outtextxy(10,260,"VISITED[v]=1; \n");
delay(600);
outtextxy(10,280,"T=union(T,<u,v>); \n");
delay(600);
outtextxy(10,125,"->Step 4 :Return T; \n");
while(!kbhit()){}
}
//printf("Step 5: Exit\n\n\n\n");
getch();
break;
case 3:
cleardevice();
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
setcolor(BLUE);
settextstyle(0,0,2);
outtextxy(70,50,"This is the graph which is choosen to be solved using Prim's Algorithm");
settextstyle(0,0,1);
setcolor(RED);
circle(60,170,7);
outtextxy(57,167,"S");
delay(600);
circle(140,170,7); //a
delay(600);
outtextxy(138,167,"a");
delay(600);
circle(210,110,7); //b
delay(600);
outtextxy(208,107,"b");
delay(600);
circle(300,110,7); //c
delay(600);
outtextxy(298,107,"c");
delay(600);
circle(212,230,7); //d
delay(600);
outtextxy(210,228,"d");
delay(600);
circle(300,230,7); //e
delay(600);
outtextxy(298,226,"e");
delay(600);
circle(400,170,7); //f
delay(600);
outtextxy(398,167,"f");
delay(600);
circle(480,170,7);
delay(600);//ending point
outtextxy(478,167,"V");
delay(600);
dcircle(208,170,7);
delay(600);
outtextxy(206,167,"g");
delay(600);
setcolor(GREEN);
delay(600);
line(66,170,132,170);
delay(600);  //line s to a
line(142,163,203,110);
delay(600);  //line a to b
line(217,110,292,110);
delay(600);  //line b to c
line(209,117,209,164);
delay(600);  //line b to g
line(142,177,205,226);
delay(600);  //line a to d
line(210,222,210,177);
delay(600);  //line d to g
line(220,230,292,230);
delay(600);  //line d to e
line(307,226,392,170);
delay(600);  //line e to f
line(307,110,396,162);
delay(600);  //line c to f
line(407,170,472,170);
delay(600);  //line f to e
while(!kbhit){}
}
{
int n=10,i,j,w[10],e[10];
int E=10;
int V=6;
struct Graph*graph=createGraph(E,V);
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
cleardevice();
grap();
delay(1000);
for(i=0;i<10;i++)
{
cleardevice();
gotoxy(4,2);
printf("As number of vertices is fixed to 6,enter value for edges");
printf("\n Enter value for 10 Edges(%d Remaining):",n);
scanf("%d",&w[i]);
n=n-1;
}
graph->edge[0].start=1;
graph->edge[0].end=2;
graph->edge[0].weight=e[0];
graph->edge[4].start=3;
graph->edge[4].end=4;
graph->edge[4].weight=e[4];
graph->edge[5].start=2;
graph->edge[5].end=6;
graph->edge[5].weight=e[5];
//edge:A--C
graph->edge[6].start=3;
graph->edge[6].end=6;
graph->edge[6].weight=e[6];
//edge:B--C
graph->edge[7].start=6;
graph->edge[7].end=4;
graph->edge[7].weight=e[7];
//edge:D--C
graph->edge[9].start=4;
graph->edge[9].end=5;
graph->edge[9].weight=e[9];
prim(graph);
settextstyle(0,0,1);
setcolor(RED);
circle(80,100,7);//a
outtextxy(78,98,"a");
circle(140,40,7);//b
outtextxy(138,38,"b");
for(i=0;i<5;i++)
{
if(w[i]==1&&p[i]==5)
line(84,104,167,168);
if(w[i]==2&&p[i]==3)
line(145,40,214,40);
if(w[i]==2&&p[i]==6);
{
line(140,44,166,96);
}
}
}
getch();
break;
case 4:cleardevice();
//applications();
break;
case 5:cleardevice();
//getch();
exit(0);
break;
default:outtextxy(350,350,"INVALID CHOICE");
getch();
}
}
}
}
int login()
{
int j;
int gdriver=DETECT,gmode;
char pwrd[]="12345";
char temp1[25],temp2[25],uname[]="admin",ch;
int i=0;
initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
setcolor(GREEN);
setfillstyle(1,4);
rectangle(150,130,500,330);
rectangle(155,135,495,325);
floodfill(154,134,GREEN);
setcolor(GREEN);
settextstyle(7,0,8);
outtextxy(210,28,"LOGIN");
setcolor(CYAN);
setcolor(YELLOW);
settextstyle(0,0,0);
outtextxy (210,340,"THE NATIONAL DEGREE COLLEGE");
setcolor(CYAN);
settextstyle(0,0,0);
outtextxy(260,360,"[AUTONOMOUS]");
setcolor(12);
settextstyle(0,0,0);
outtextxy(210,375,"BASAVANGUDI,BANGALORE-560004");
setcolor(13);
settextstyle(11,0,0);
outtextxy(255,390,"Year:2022-2023");
setcolor(BLACK);
rectangle(300,158,480,180);
settextstyle(0,0,1);
rectangle(300,230,480,256);
setcolor(YELLOW);
setfillstyle(1,4);
settextstyle(3,0,3);
setcolor(LIGHTCYAN);
outtextxy(180,150,"USER NAME");
rectangle(300,158,480,180);
gotoxy(40,11);
gets(temp1);
outtextxy(180,230,"PASSWORD");
rectangle(300,230,480,256);
setcolor(GREEN);
setfillstyle(1,4);
rectangle(150,130,500,330);
rectangle(155,135,495,325);
floodfill(154,134,GREEN);
gotoxy(40,16);
while(1)
{
ch=getch();
if(ch==13)
break;
printf("*");
temp2[i++]=ch;
}
temp2[i]='\0';
if(!strcmp(uname,temp1)&&!strcmp(temp2,pwrd))
{
rectangle(8,435,639,458);
setcolor(LIGHTRED);
settextstyle(6,0,1);
outtextxy(220,400,"LOADING......PLEASE WAIT");
for(i=0;i<622;i++)
{
setcolor(GREEN);
line(8+i,436,8+i,457);
delay(5);
}
return 1;
}
else
{
settextstyle(100,0,5);
setcolor(CYAN);
outtextxy(180,300,"PLEASE ENTER THE CORRECT PASSWORD");
delay(1500);
return 0;
}
}
