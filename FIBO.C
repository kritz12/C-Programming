#include<stdio.h>
#include<conio.h>
void main()
{
int fibo[100],i,n;
clrscr();
printf("\n enter the number of elements in the series \n");
scanf("%d",&n);
fibo[0]=0;
fibo[1]=1;
for(i=2;i<n;i++);
fibo[i]=fibo[i-1]+fibo[i-2];
for(i=0;i<n;i++)
printf("%d of the fibo %d \n",i,fibo[i]);
getch();
}