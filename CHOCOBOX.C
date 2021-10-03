#include<stdio.h>
#include<conio.h>
void main(void)
#define SIZE 20
{
int chocobox[SIZE],i,startn,jumpn,jumpcount=0,del=0,j=0;
clrscr();
for(i=0;i<SIZE;i++) chocobox[i]=1;
printf("Welcome to ChocolateBox !\n From which box to start ?\n : > ");
scanf("%d",&startn);
i=startn-1;
printf("How many boxes to jump ?\n : > ");
scanf("%d",&jumpn);
chocobox[i]=0;
del++;
for(;del<SIZE;i++)
{
	if(i==(SIZE)) i=0;
	if(chocobox[i]==1)
	{
	jumpcount++;
	if(jumpcount==jumpn)
		{
		chocobox[i]=0;
		del++;
		jumpcount=0;
		for(j=0;j<SIZE;j++)
			{
			printf("%d ",chocobox[j]);
			}
		printf("\n");
		}
	}

}
printf("\n%d is the last box...",i);

getch();
}

