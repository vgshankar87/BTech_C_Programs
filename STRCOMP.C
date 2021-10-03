#include<stdio.h>
#include<conio.h>
void main(void)
{
char str1[30]={"\n"},str2[30]={"\n"};
char * c, * r;
int i=0,flag=1;
c=str1;
r=str2;
clrscr();
printf("Enter First string : ");
for(i=0;i<30;i++)
{
scanf("%c",c+i);
if(*(c+i)=='\n') break;
}

printf("Enter Second string : ");
for(i=0;i<30;i++)
{
scanf("%c",r+i);
if(*(r+i)=='\n') break;
}

for(i=0;*(c+i)!='\n'&&*(r+i)!='\n' ;i++)
{
if(*(c+i)!=*(r+i))
	{
	flag=0;
	}
}
if(flag==1) printf("\n Both Strings are Equal ! ");
else printf("\n Both are different strings.");


getch();
}

