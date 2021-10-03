#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define SIZE 8
#define TRUE 1
#define FALSE -1

int check(int,int);
void draw();

int a[8]={-1,-1,-1,-1,-1,-1,-1,-1};

int ctr1,ctr2;

	char patternw[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	char patternb[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void main()
{
	int gd=DETECT,gm,ctr1,ctr2;
	int i,j,k;
	initgraph(&gd,&gm,"d:\\tc3\\bgi");
	for(k=0;k<=7;k++)
	{
	// Reset Position array, a[]
	for(i=0;i<=7;i++) a[i]=-1;
	a[0]=k-1; // Sets First Coin's position to 'k'
	draw();
	getch();
	for(i=0;i<=7;i++)
	{
//		for((j=a[i]==-1?0:a[i]+1),a[i]=-1;j<=7;j++)
	if(a[i]==-1) j=0;
	else  {
	//No Erase
		if(a[i]==7)  // Checks whether Backtracking is needed
		{
		if((a[i-1]+i-1)%2)
		setfillpattern(patternw,WHITE);
		else
		setfillpattern(patternb,BLACK);
		setcolor(WHITE);
		bar(5+(a[i-1])*50,5+(i-1)*50,5+(a[i-1])*50+49,5+(i-1)*50+49);
		 delay(500);
		 a[i]=-1;    //
		 i-=2;       // Backtrack
		continue;
		}
		j=a[i]+1;     // After Backtracking, continue from next position
		a[i]=-1;
		}
	while(j<=7)
	{
	if(check(i,j)==FALSE)  // Checks Whether Any other Queen is in attacking position.
	{
	//Display Q;
	 a[i]=j;
	 if((a[i]+i)%2)
	 setcolor(BLACK);
	else
	setcolor(WHITE);
	settextstyle(4,0,3);
	outtextxy(22+a[i]*50,13+i*50,"Q");
		 delay(500);
	 break;
	 }
	 if(j==7)
	 {
	 if((a[i-1]+i-1)%2)  //  Clear Q
		setfillpattern(patternw,WHITE);
		else
		setfillpattern(patternb,BLACK);
		setcolor(WHITE);
		bar(5+(a[i-1])*50,5+(i-1)*50,5+(a[i-1])*50+49,5+(i-1)*50+49);
		delay(500);
	 i-=2;
	 }
	j++;
	}
	}
	getch();
	}
	closegraph();
}

void draw()
{
setcolor(WHITE);
for(ctr1=0;ctr1<SIZE;ctr1++)
for(ctr2=0;ctr2<SIZE;ctr2++)
{
if((ctr1+ctr2)%2)
setfillpattern(patternw,WHITE);
else
setfillpattern(patternb,BLACK);
bar(5+ctr1*50,5+ctr2*50,5+ctr1*50+49,5+ctr2*50+49);
}
rectangle(5,5,405,405);

}

int check(int i,int j)
{
	int x,y;
	for(x=i,y=j;(x>=0)&&(y>=0);x--,y--)  // Checks Left Diagonal for Attacking Queens
	if(a[x]==y)
	return TRUE;

	for(x=i,y=j;x>=0;x--)  // Checks Downwards for Attacking Queens
	if(a[x]==y)
	return TRUE;

	for(x=i;(x>=0)&&(y<=7);x--,y++)  // Checks Right Diagonal for Attacking Queens
	if(a[x]==y)
	return TRUE;

	return FALSE;  // Says No Attacking Queens Found
}