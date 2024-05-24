#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#define IN 9999
#define N 6
int w[10],p[10];
struct Edge
{
int start;
int end;
int weight;
};
struct Graph
{
int E;
int V;
struct Edge*edge;
};
struct subset
{
int parent;
int rank;
};
struct Graph*createGraph(int E,int V)
{
struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
graph->E=E;
graph->V=V;
graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
return graph;
}  //edited
int Find(struct subset subsets[],int i)
{
if(subsets[i].parent!=i)
subsets[i].parent=Find(subsets,subsets[i].parent);
return subsets[i].parent;
}

void Union (struct subset subsets[],int vertXsubset,int vertYsubset)
{
int rootofX=Find(subsets,vertXsubset);
int rootofY=Find(subsets,vertYsubset);
if(subsets[rootofX].rank<subsets[rootofY].rank)   //edited
{
subsets[rootofY].parent=rootofY;
}
//}
else if(subsets[rootofX].rank>subsets[rootofY].rank)   //edited
{
subsets[rootofY].parent=rootofX;
}
else
{
subsets[rootofY].parent=rootofX;
subsets[rootofX].rank++;
}
}

void sort(struct Graph * graph)
{
int i,j,noofEdges=graph->E;
struct Edge*tempEdge=(struct Edge*)malloc(sizeof(struct Edge));
for(i=1;i<noofEdges;i++)
{
for(j=0;j<noofEdges-i; j++)
{
if(graph->edge[j].weight>graph->edge[j+1].weight)
{
graph->edge[j+1].end=tempEdge->end;
graph->edge[j+1].weight=tempEdge->weight;
}
}
}
}

void grap()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
cleardevice();
setcolor(YELLOW);
settextstyle(0,0,2);
outtextxy(70,50,"This is the graph which is choosen to be solved using prim's algorithm");
settextstyle(0,0,1);
setcolor(RED);
circle(60,170,7);//starting point
outtextxy(57,167,"S");
circle(140,170,7);//a
outtextxy(138,167,"a");
circle(210,110,7);//b
outtextxy(208,107,"b");
circle(300,110,7);//c
outtextxy(298,107,"c");
circle(212,230,7);//d
outtextxy(210,228,"d");
circle(300,230,7);//e
outtextxy(298,226,"e");
circle(400,170,7);//f
outtextxy(398,167,"f");
circle(480,170,7);//ending point
outtextxy(478,167,"V");
circle(208,170,7);
outtextxy(206,167,"g");
setcolor(GREEN);
line(66,170,132,170);//line s to a
line(142,163,203,110);//line a to b
line(217,110,292,110); //line b to c
line(209,117,209,164);//line b to g
line(142,177,205,226);// line a to d
line(210,222,210,177);//line d to g
line(220,230,292,230);//line d to e
line(307,226,392,170);//line e to f
line(307,110,396,162);// line c to f
line(407,170,472,170);//line f to e
while(!kbhit){}          //edited
getch();
}

void app()
{
int cost[N][N],i,j,w,ch,co;
int source,target,x,y;
cleardevice();
setcolor(RED);
settextstyle(8,0,3);
outtextxy(80,8,"The Shortest Path Prims ALGORITHM \n\n");
setcolor(YELLOW);
line(120,170,200,120); //diagnal line
line(120,210,200,270); //diagnal line
line(240,120,360,120);
line(240,270,360,270);
//line(220,240,360,140);
line(510,250,240,140); //diagnal line
line(220,250,220,140);
//line(380,220,380,140);
line(530,140,530,250);
line(510,270,400,270);
line(510,120,400,120);

setcolor(WHITE);
rectangle(200,100,240,140); // head office
rectangle(200,250,240,290); // branch 1
rectangle(140,170,105,210); // phone c
rectangle(400,100,360,140); //bran 3
rectangle(510,100,550,140); //last rit top
rectangle(550,250,510,290);  //last down box
rectangle(400,250,360,290); //branch 2

setcolor(WHITE);
settextstyle(3,0,2);
outtextxy(0,180,"HeadOffice");
delay(200);
outtextxy(160,60,"BANGALORE");
delay(200);
outtextxy(340,60,"MYSORE");
delay(200);
outtextxy(160,300,"MANGALORE");
delay(200);
outtextxy(360,300,"MANDYA");
delay(200);
outtextxy(500,60,"SHIVAMOGGA");
delay(200);
outtextxy(510,300,"TUMKUR");
sleep(5);
cleardevice();
for(i=1;i<N;i++)
for(j=1;j<N;j++)
cost[i][j]=IN;
for(x=1;x<N;x++)
{
for(y=x+1;y<N;y++)
{
printf("Enter the weight of the path between nodes %d and %d:",x,y);
scanf("%d",&w);
cost[x][y]=cost[y][x]=w;
}
printf(" \n");
}
printf("\n Enter the source:");
scanf("%d",&source);
printf("\n Enter the target:");
scanf("%d",&target);
co=prims(cost,source,target);
printf("\n The Shortest Path: %d",co);
getch();
}

int prims(int cost[][N],int source,int target)
{
int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
char path[N];
for(i=1;i<N;i++)
{
dist[i] = IN;
prev[i] =-1;
}
start = source;
selected[start]=1;
dist[start]=0;
while(selected[target]==0)
{
min=IN;
m=0;
for(i=1;i<N;i++)
{
d = dist[start]+cost[start][i];
if(d<dist[i]&&selected[i]==0)
{
dist[i]=d;
prev[1]=start;
}
if(min>dist[i]&&selected [i]==0)
{
min=dist[i];
m=i;
}
}
start=m;
selected[start]=1;
}
start=target;
j=0;
while(start!=-1)
{
path[j++]=start+65;
start = prev[start];
}
path[j]='\0';
strrev(path);
printf("%s",path);
return dist[target];
getch();
}

void algo()
{
int x,y;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
settextstyle(3,0,3);
setcolor(LIGHTGREEN);
outtextxy(250,10,"ALGORITHM");
for(x=250,y=40;x<=365;x++)
{
putpixel(x,y,WHITE);
delay(10);
}
setcolor(GREEN);
settextstyle(3,0,2);
outtextxy(0,50,"There are some steps:");
delay(200);
setcolor(CYAN);
outtextxy(10,80,"->Step 1: Input:The cost adjacency matrix C and number of");
outtextxy(100,110,"vertices n.");
delay(200);
outtextxy(10,140,"->Step 2: Output:Minimum weight Spanning Tree T");
delay(200);
outtextxy(120,170,"for(i=1;i<=n;i++)");
delay(200);
outtextxy(120,200,"Visited[i]=0;");
delay(200);
outtextxy(120,230,"U=1");
delay(200);
outtextxy(120,260,"Visited[u]=1;");
delay(200);
outtextxy(120,290,"While(there is still unchosen vertex)do");
delay(200);
outtextxy(10,320,"->Step 3: Let(u,v)be the lightest edge between any chosen");
outtextxy(100,340,"u to any chosen vertex v.");
delay(200);
outtextxy(120,370,"Visited[v]=1;");
delay(200);
outtextxy(120,400,"T=union(T,<u,v>);");
delay(200);
outtextxy(10,430,"->Step 4: Return T;");
//while(!kbhit){}
getch();
}

void about()
{
int x,y;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
settextstyle(0,0,1);
setcolor(YELLOW);
settextstyle(3,0,4);
outtextxy(200,40,"ABOUT PROJECT");
for(x=200,y=80;x<=440;x++)
{
putpixel(x,y,WHITE);
delay(10);
}
settextstyle(3,0,2);
setcolor(WHITE);
outtextxy(1,120,"\n Prim's algorithm is a greedy algorithm that finds a \n");
delay(200);
outtextxy(1,140,"\n minimum spanning tree for a connected weighted \n");
delay(200);
outtextxy(1,160,"\n undirected graph.It finds a subset of  the edges that forms \n");
delay(200);
outtextxy(1,180,"\n a tree that includes every vertex,where the total weight of \n");
delay(200);
outtextxy(1,200,"\n all the edges in the tree are minimised.This algorithm is ");
delay(200);
outtextxy(1,220,"\n directly based on the MST(Minimum Spanning Tree).");
delay(200);
outtextxy(1,260,"\n This algorithm takes a weighted undirected graph as an \n");
delay(200);
outtextxy(1,280,"\n input and output its Minimum Spanning Tree(MST). \n");
delay(200);
outtextxy(1,320,"\n Application of Prim's Algorithm are Network for Roads and\n");
delay(200);
outtextxy(1,340,"\n Rail tracks connecting all cities,and Used for \n");
delay(200);
outtextxy(1,360,"\n Telecommunication.");
delay(200);
while(!kbhit){}
getch();
}

void displayMS(struct Graph*graphMST)
{
int i,nofEdges=graphMST->E,wt,a=0;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(50,100,"path Chosen");
gotoxy(10,10);
for(i=0;i<nofEdges;i++)
for(i=0;i<nofEdges;i++)       //edited
{
//wt+graphMST->edge[i].weight;
//wt=30;
printf("Total weight= %d",wt);            //edited
while(!kbhit())
{
for(i=0;i<nofEdges;i++)
{
delay(600);
if(w[i]==1&&p[i]==2)
line(220,140,220,300);
if(w[i]==1&&p[i]==3)
line(240,120,350,120);
}
delay(1600);
//while(!kbhit()
}
}
}

void displayMST(struct Graph*graphMST)
{
int i,noofEdges=graphMST->E,wt,a=0;
//int gdriver=DETECT,gmode;
//initgraph(&gdriver,&gmode,"c://turboc3//bgi");
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(50,100,"path chosen");
wt=a+graphMST->E;      // edited
//wt=20;   //edited
gotoxy(10,15);
printf("Total Weight=%d",wt);
while(!kbhit())
{
for(i=0;i<noofEdges;i++)
printf("%d-%d",w[i],p[i]);
}
delay(1300);
cleardevice();
while(!kbhit())
{
}
}

int hasCycle(struct Graph*graph)
{
//variable
int i,j,vertXSubset,vertYsubset;   //edited
//total number of vertices in the graph
int V=graph->V;
int E=graph->E;
struct subset*subsets=(struct subset*)malloc(V*sizeof(struct subset));
//initialize subset
for(i=0;i<V;i++)
{
subsets[i].parent=i;
subsets[i].rank=0;
}
for(j=0;j<E;j++)
{
vertXSubset=Find(subsets,graph->edge[j].start);
}
}

void prim(struct Graph*graph)
{
//variables
int i,j;
int V=6,E=8;
struct Graph*graphMST=createGraph(V-1,V);
sort(graph);
//struct graph*graphMST=createGraph(V-1,V);
for(i=0,j=0;i<E&&j<V-1;i++)
{
graphMST->edge[j]=graph->edge[i];
graphMST->E=j+1;
if(!hasCycle(graphMST))
{
j++;
}
}
displayMST(graphMST);
}

void kruskal(struct Graph*graph)
{
//variables
int i,j;
int V=6,E=8;
struct Graph*graphMST=createGraph(V-1,V);
//now check other edges
for(i=0,j=0;i<E&&j<V-1;i++)
{
graphMST->edge[j]=graph->edge[i];
graphMST->E=j+1;
if(!hasCycle(graphMST))
{
j++;
}
}
displayMS(graphMST);
}

void work()
{
int n=10,i,j,w[10],e[10];     //total number of edges and vertices
//int E=10;
//int V=6;
int wt=0,value;
//struct Graph*graph=createGraph(E,V);
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
cleardevice();
grap();
delay(1000);
for(i=0;i<10;i++)
{
cleardevice();
gotoxy(4,2);
printf("As number of vertices is fixed to 6, Enter values for edges.");
printf("\nEnter values for 10 Edges:\n",n);
//scanf("%d",&w[i]);
n=n-1;
}
for(i=1;i<10;i++)
{
scanf("%d",&n);
wt=wt+n;
}
cleardevice();
setcolor(LIGHTGREEN);
settextstyle(3,0,5);
outtextxy(50,100,"PATH CHOSEN");
gotoxy(40,40);
printf("The Total Weight: %d",wt);
if(wt<50)
{
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
}

else if(wt>=50&&wt<=100)
{
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

setcolor(RED);
circle(318,307,7);      //d
outtextxy(315,304,"d");
setcolor(WHITE);
line(310,305,254,270);// line a to d
}


else if(wt>=100&&wt<=150)
{
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
}


else if(wt>=150&&wt<=200)
{
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
//line(408,210,467,253);// line c to f
}

else if(wt>200)
{
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
//line(408,210,467,253);// line c to f

setcolor(RED);
circle(550,260,7);     //ending point
outtextxy(547,257,"V");
setcolor(WHITE);
line(478,260,542,260);
}
getch();
}

void appli()
{
int n=5,i,j,m[10];
//int E=5;
//int V=4;
//struct Graph*graph=createGraph(E,V);
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
app();
getch();
}

void main()
{
int i=0,ch,k;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
k=login();
if(k==1)
{
cleardevice();
setcolor(YELLOW);
settextstyle(8,0,3);
outtextxy(120,8,"THE NATIONAL DEGREE COLLEGE");
delay(1000);
for(i=0;i<=410;i++)
{
putpixel(120+i,40,LIGHTGRAY);
delay(10);
}
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
outtextxy(100,120,"WELCOME TO THE PROJECT");
delay(1000);
settextstyle(10,0,2);
outtextxy(10,170,"PRIM'S WITH MINIMUM SPANNING TREE");
delay(1000);
settextstyle(10,0,2);
outtextxy(80,220,"SIMULATION OF SPANNING TREES");
setcolor(CYAN);
delay(1000);
cleardevice();
settextstyle(8,0,3);
setcolor(WHITE);
outtextxy(150,15,"PRIM'S ALGORITHM");
delay(1000);
for(i=0;i<=240;i++)
{
putpixel(150+i,49,LIGHTGRAY);
delay(10);
}
setcolor(CYAN);
settextstyle(8,0,3);
delay(500);
outtextxy(0,130,"KRITHIK GUHAN.S    [20NCBC1066]");
delay(500);
outtextxy(0,170,"MUTHU RAJ.S        [20NCBC1069]");
delay(500);
outtextxy(0,210,"TARUN.M            [20NCBC1077]");
delay(500);
//settextstyle(0,0,2);
setcolor(RED);
outtextxy(0,290,"Under Guidance of:-");
delay(600);
for(i=0;i<250;i++)
{
putpixel(0+i,320,YELLOW);
delay(10);
}
for(i=0;i<7;i++)
{
settextstyle(1,0,6);
setcolor(WHITE);
delay(100);
outtextxy(0,320,"Prof SATISH KUMAR.G");
setcolor(LIGHTGRAY);
settextstyle(2,HORIZ_DIR,4);
outtextxy(70,380,"Press any key to continue.....");
}

while(1)
{
cleardevice();
setcolor(WHITE);
rectangle(0,0,600,450);
rectangle(5,5,595,445);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(1,1,WHITE);
settextstyle(8,0,6);
outtextxy(200,28,"MENU");
line(200,90,350,90);
settextstyle(1,0,2);
setcolor(CYAN);
outtextxy(160,120,"1.ABOUT THE PROJECT");
delay(100);
outtextxy(160,160,"2.DEMONSTRATION");
delay(100);
outtextxy(160,200,"3.APPLICATION");
delay(100);
outtextxy(160,240,"4.ALGORITHM");
delay(100);
outtextxy(160,280,"5.EXIT");
delay(100);
setcolor(BROWN);
outtextxy(160,320,"Enter your choice");
gotoxy(33,24);
setcolor(DARKGRAY);
rectangle(240,360,300,385);
scanf("%d",&ch);
switch(ch)
{
case 1:cleardevice();
about();
break;
case 2:cleardevice();
work();
break;
case 3:cleardevice();
appli();
break;
case 4:cleardevice();
algo();
break;
case 5:cleardevice();
settextstyle(8,0,8);
for(i=0;i<250;i++)
{
cleardevice();
setcolor(i);
settextstyle(8,0,8);
outtextxy(60,-120+1+250,"THANK YOU");
delay(10);
}
exit(0);
break;
default:cleardevice();
settextstyle(3,0,5);
outtextxy(100,100,"INVALID CHOICE,TRY AGAIN");
delay(800);
break;
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
  initgraph(&gdriver,&gmode,"c://turboc3//bgi");
  setcolor(GREEN);
  setfillstyle(1,4);
  rectangle(150,130,500,330);
  rectangle(155,135,495,325);
  floodfill(154,134,GREEN);
  setcolor(YELLOW);
  settextstyle(8,0,8);
  outtextxy(210,28,"LOGIN");
  setcolor(YELLOW);
  setcolor(LIGHTCYAN);
  settextstyle(0,0,0);
  outtextxy(210,340,"THE NATIONAL DEGREE COLLEGE");
  setcolor(CYAN);
  settextstyle(0,0,0);
  outtextxy(260,360,"[AUTONOMOUS]");
  setcolor(12);
  settextstyle(0,0,0);
  outtextxy(210,375,"BASAVANAGUDI, BANGALORE-560004");
  setcolor(13);
  settextstyle(11,0,0);
  outtextxy(255,390,"YEAR: 2022-2023");
  setcolor(BLACK);
  rectangle(300,158,480,180);
  settextstyle(0,0,1);
  rectangle(300,230,480,256);
  setcolor(YELLOW);
  setfillstyle(1,4);
  settextstyle(3,0,3);
  setcolor(LIGHTCYAN);
  outtextxy(180,150,"USERNAME");
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
  if(!strcmp (uname,temp1)&&!strcmp(temp2,pwrd))
   {
	 rectangle(8,435,630,458);
	 setcolor(LIGHTRED);
	 settextstyle(6,0,1);
	 outtextxy(220,400,"LOADING....PLEASE WAIT");
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
	 settextstyle(100,0,1);
	 setcolor(DARKGRAY);
	 outtextxy(180,300,"PLEASE ENTER CORRECT PASSWORD");
	 delay(1500);
	 return 0;
	 }
}

