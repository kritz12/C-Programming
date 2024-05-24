#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#define size 100
int main()
{
  int j;
  int gdriver=DETECT,gmode;
  char pwrd[]="1234";
  char temp1[25],temp2[25],uname[]="admin",ch;
  int i=0;
  initgraph(&gdriver,&gmode,"c://turboc3//bgi");
 // margin();
  setcolor(GREEN);
  setfillstyle(1,4);
  rectangle(150,130,500,330);
  rectangle(155,135,495,325);
  floodfill(154,134,GREEN);
  setcolor(LIGHTGREEN);
  settextstyle(7,0,8);
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
     setcolor(CYAN);
     outtextxy(180,300,"PLEASE ENTER CORRECT PASSWORD");
     delay(1500);
     return 0;
     }
}