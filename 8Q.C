#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE -1

int check(int,int);
void draw();

int a[8]={-1,-1,-1,-1,-1,-1,-1,-1};

void main()
{
	int i,j;
	textcolor(15);
	clrscr();
	draw();
	for(i=0;i<=7;i++)
	{
//		for((j=a[i]==-1?0:a[i]+1),a[i]=-1;j<=7;j++)
	if(a[i]==-1) j=0;
	else  {
	//No Erase
		if(a[i]==7)
		{
		 gotoxy(a[i-1]*4+2,(i-1)*2+2);
		 printf("%d,%d",i-1,a[i-1]);
		 getch();
		 a[i]=-1;
		 i-=2;
		continue;
		}
		j=a[i]+1;
		a[i]=-1;
		}
	while(j<=7)
	{
	if(check(i,j)==FALSE)
	{
	//Display Q;
	 a[i]=j;
	 gotoxy(a[i]*4+2,i*2+2);
	 printf(" Q ");
	 getch();
	 break;
	 }

	 if(j==7)
	 {
	 gotoxy(a[i-1]*4+2,(i-1)*2+2);
	 printf("%d,%d",i-1,a[i-1]);
	 getch();
	 i-=2;
	 }


	j++;
	}

	}

	getch();
}

void draw()
{
	int ctr1,ctr2;
	printf("+---+---+---+---+---+---+---+---+");
	for(ctr1=0;ctr1<=7;ctr1++)
	{
	printf("\n|   |   |   |   |   |   |   |   |");
	printf("\n+---+---+---+---+---+---+---+---+");
	}

	for(ctr1=0;ctr1<8;ctr1++)
	for(ctr2=0;ctr2<8;ctr2++)
	{
		gotoxy(ctr2*4+2,ctr1*2+2);
		printf("%d,%d",ctr1,ctr2);
	}

}

int check(int i,int j)
{
	int x,y;
	for(x=i,y=j;(x>=0)&&(y>=0);x--,y--)
	if(a[x]==y)
	return TRUE;

	for(x=i,y=j;x>=0;x--)
	if(a[x]==y)
	return TRUE;

	for(x=i;(x>=0)&&(y<=7);x--,y++)
	if(a[x]==y)
	return TRUE;

	return FALSE;
}