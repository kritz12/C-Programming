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
}
struct Graph
{
int E;
int V;
struct Edge*edge;
}
struct subset
{
int parent;
int rank;
}
struct Graph*createGraph(int E,int V)
{
struct Graph*graph=(struct Graph*)malloc(sizeof(struct Graph));
graph->E=E;
graph->V=V;
graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
return graph;
}
int find(struct subset subsets[],int i)
{
if(subsets[i].parent!=i)
subsets[i].parent=Find(subsets,subsets[i].parent);
return subsets[i],parent;
}
//else if

void Union(struct subset subsets[],int vertXsubset,int vertYsubset)
{
int rootofX=Find(subsets,vertXsubset);
int rootofY=Find(subsets,vertYsubset);
if(subsets[rootofX].rank[rootofY].rank)
{
subset[rootofY].parent=rootofY;
}
//}
else if(subsets[rootofX].rank>subsets[rootofY].rank)
{
subsets[rootofY].parent=rootofX;
}
else
{
subsets[rootofY].parent=rootofX;
subsets[rootofX].rank++;
}
}

void sort(struct Graph*graph)
{
int i,j,noofEdges=graph->E;
struct Edge*tempEdge=(struct Edge*)malloc(sizeof(struct Edge));
for(i=1;i<noofEdges;i++)
{
for(j=0;j<noofEdges-i;j++)
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

void app()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
settextstyle(0,0,1);
outtextxy(10,30,"This is a simple application of landline network connect to some group of");
outtextxy(10,50,"offices using prim's algorithm with the Minimum Spanning tree. The relustant");
outtextxy(10,70,"connection from house are in such a way that it choses minimum distance.");
setcolor(YELLOW)
line(140,120,200,120);
line(240,120,360,120);
line(240,240,360,240);
//line(220,240,360,140);
line(360,220,240,140); //diagonal line
line(220,220,220,140);
line(380,220,380,140);

//line(220,360,360,220);
//line(400,420,200,100);
//lineto(600,380);
//line(400,250,90,250);

setcolor(WHITE);
rectangle(200,100,240,140);
rectangle(200,220,240,260);
rectangle(140,100,105,140);
rectangle(400,100,360,140);
rectangle(400,220,360,260);
setcolor(WHITE);
outtextxy(170,90,"Head Office");
outtextxy(70,150,"Phone Connection");
outtextxy(200,270,"Branch 1");
outtextxy(360,270,"Branch 2");
outtextxy(340,90,"Branch 3");
outtextxy(10,360,"A office wants least phone lines to connect them up with each other");
outtextxy(10,370,"branches & phone company charges different amount of money to connect");
outtextxy(10,380,"different pairs of cities.You  want a set of lines that connects all your");
outtextxy(10,390,"office with a minimum total cost.");
while(!kbhit())
{}
}

void algo()
{
int x,y;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
settextstyle(0,0,3);
setcolor(YELLOW);
outtextxy(200,40,"ALGORITHM");
for(x=160,y=80;x<=420;x++)
{
putpixel(x,y,WHITE);
delay(10);
}
settextstyle(0,0,1);
outtextxy(100,110,"Step 1: \n Input:The cost adjacency matrix C and number of vetices n\n");
outtextxy(100,125,"Step 2: \n Output:Minimum weight spanning Tree T\n");
outtextxy(100,145,"Visited[i]=0;\n");
outtextxy(100,165,"U=1\n");
outetxtxy(100,185,"Visited[u]=1;\n");
outetxtxy(100,200,"While(there is stile unchosen vertex)do\n");
outetxtxy(100,225,"Step 3: \n Let(u,v)be the least edge between any chosen u to any chosen vertex v\n");
outetxtxy(100,245,"Visited[v]=1;\n");
outetxtxy(100,260,"T=union(T,<u,v>);\n");
outetxtxy(100,125,"Step 4: Return T;\n");
while(!kbhit)
{
}
}

void about()
{
int x,y;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
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
settextstyle(0,0,1);
setcolor(WHITE);
outtextxy(1,100,"\nPrim's Algorithm is a greedy algorithm that finds a minimum spanning \n");
outtextxy(1,120,"\ntree for a connected weighted undirected graph.It finds a subset of \n");
outtextxy(1,140,"\nthe edges that forms a tree that includes every vertex,where the\n");
outtextxy(1,160,"\ntotal weight of all edges in the tree are minimised.This algoirthm\n");
outtextxy(1,180,"\nis directly based on Minimum Spanning Tree property");
while(!kbhit)
{}
getch();
}

void displayMS(struct Graph*graphMST)
int i,nofEdges=graphMST->E,wt,a=0;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(50,100,"Path chosen");
gotoxy(10,10);
for(i=0;i<nofEdges;i++)
//for(i=0;i<nofEdges;i++)
{
//wt=a+graphMST->edge[i].weight;
wt=30;
printf("Total weight=%d",wt); //edited
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
//while(!kbhit())
}
}
}


void displayMST(struct Graph*graphMST)
{
int i, noofEdges=graphMST->E,wt,a=0;
//int gdriver=DETECT,gmode;
//initgraph(&gdriver,&gmode,"c://turboc3//bgi");
setcolor(YELLOW);
settextstyle(3,0,5);
outtextxy(50,100,"Path chosen");

//wt=a+graphMST->E; //edited
wt=20;  //edited
gotoxy(10,15);
printf("Total Weight=%d",wt);
while(!kbhit())
{
for(i=0;i<noofEdges;i++)
printf("%d-%d",w[i],p[i])
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
int i,j,vertXSubset,vertYsubset; //edited
//total number of vertices in the graph
int V=graph->V;
int E=graph->E;
struct subset*subsets=(struct subset*)malloc(V*sizeof(struct subset));
//initialize subset
for(i=0;i<V;i++)
{
subsets[i].parent=1;
subsets[i].rank=0;
}
for(j=0;j<E;j++)
{
vertXSubset=Finf(subsets,graph->edge[j].start);
}
}


void prim(struct Graph*graph)
{
//variables
int i,j;
int V=6,E=8;
struct Graph*graphMST=createGraph(V-1,V);
sort(graph);
//struct graph?*graphMST=creategraph(V-1,V);

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


void prims(struct Graph*graph)
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
displayMST(graphMST);
}

 void work()
 {
 int n=10,i,j,w[10],e[10];
 int E=10;
 int V=6;
 struct Graph*graph=createGraph(E,V);
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 cleardevice();
 //grap();
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


void appli()
{
int n=5,j,m[10];  //total number og edges and vetices
int E=5;
int V=4;
struct Graph*graph=createGraph(E,V);
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c://turboc3//bgi");
cleardevice();
while(!kbhit())
{
app();
}
for(i=0;i<5;i++)
{
cleardevice();
gotoxy(4,2);
printf("As number of vertices is fixed to 4,Enter value for edges");
printf("\nEnter values for 5 Edges(%d Remaining):",n);
scanf("%d",&m[i]);
n=n-1;
}
app();
gotoxy(37,9);
printf("%d",m[0]);    //1 to 3
gotoxy(37,20);
printf("%d",m[1]);    //2 to 4
gotoxy(26,14);
printf("%d",m[2]);    //1 to 2
delay(1000);
cleardevice();        //add edges to graph
//edge:A--B
graph->edge[0].start=1;
graph->edge[0].end=2;
graph->edge[0].weight=m[2];
//edge:A--C
graph->edge[1].start=1;
graph->edge[1].end=3;
graph->edge[1].weight=m[0];
//edge:B--C
graph->edge[2].start=1;
graph->edge[2].end=4;
graph->edge[2].weight=m[4];
//edge:B--D
graph->edge[3].start=2;
graph->edge[3].end=4;
graph->edge[3].weight=m[1];
outtextxy(180,50,"Path chosen to travel");
prim(graph);
cleardevice();
app();
setcolor(RED);
for(i=0;i<10;i++)
{
delay(600)
if(w[i]==2&&p[i]==4)
line(240,320,350,320);
}
delay(1600);
while(!kbhit())
{
}
for(i=2;i<n-1;i++)
{
w[i]=w[i+1];
p[i]=p[i+1];
}
delay(1500);
getch();
}
/*
void app()
{
int cost[N][N]i,j,w,ch,co;
int source,target,x,y;
clrscr();
printf("The Shortest Path Prims ALGORITHM \n\n");
printf("\n A.BANGALORE\nB.HINDUPURA\nC.BELLARY\nD.KGF\nE.GOWRIBIDANUR\nF.TUMKUR\n");
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
printf("\n");
}
printf("\n Enter the source:");
scanf("%d",&source);
printf("\n Enter the target");
scanf("%d",&target);
co=prims(cost,source,target);
printf("\n The Shortest Path:%d",co);
//getch();
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
*/
void main()
{
int i=0,ch;
int gdriver=DETECT,gmode;
initgraph(&driver,&mode,"C://TURBOC3//BGI");
cleardevice();
settextstyle(0,0,1);
while(!kbhit())
{
setcolor(YELLOW);
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
outtextxy(0,320,"Prof SATISH KUMAR.G");
setcolor(LIGHTGRAY);
settextstyle(2,HORIZ_DIR,4);
outtextxy(70,380,"Press any key to continue....");
delay(20);
}
while(i<5)
{
cleardevice();
settextstyle(0,0,1);
setcolor(LIGHTGREEN);
rectangle(170,8,400,320);
settextstyle(3,0,8);




