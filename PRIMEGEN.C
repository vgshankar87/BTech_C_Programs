#include<stdio.h>
#include<conio.h>
void main(void)
{
int i,n,p,s;
clrscr();
printf("How many prime numbers to generate ?\n< : > ");
scanf("%d",&n);
for(p=3;n>0;p++)
{

for(i=2;i<=(p/2)+1;i++)
	{
	if(!(p%i)) break;
	if(i==(p/2)+1)
		{
		printf("%d\t",p);
		n--;
		}
	}
}

getch();
}
