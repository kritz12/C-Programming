#include<stdio.h>
#include<conio.h>
void main()
{
int num,*intptr;
char ch,*chptr,str[20],*strptr;
clrscr();
printf("enter any integer: ");
scanf("%d",&num);
intptr=&num;
printf("enter any character: ");
scanf("\n %c",&ch);
chptr=&ch;
printf("enter any string: ");
scanf("\n %s",str);
strptr=str;
printf("%d is stored in the address %u\n",*intptr,intptr);
printf("%c is stored in the address %u\n",*chptr,chptr);
printf("%s is stored in the address %u\n",*strptr,strptr);
getch();
}