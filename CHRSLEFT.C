#include<stdio.h>
#include<conio.h>
void main(void)
{
char string[30]={"\n"};
char * c;
int l=0,i=0;
c=string;
clrscr();
printf("Enter a string : ");
for(i=0;i<30;i++)
{
scanf("%c",c+i);
if(*(c+i)=='\n') break;
}
printf("Enter How many Characters to Extract From Left : ");
scanf("%d",&l);

for(i=0;i<l;i++)
{
printf("%c",*(c+i));
}


getch();
}

