#include<stdio.h>
#include<conio.h>
#define SIZE 6
void draw();
int count=1,i,j;
long ctr=0;

struct point
{
int x,y;
}activepoint,nextpoint;

struct box
{
struct point loc;
int nextmove,prevmove;
}board[SIZE][SIZE];

struct point getnext(struct box *);
struct point getprev(struct box *);

void main()
{
int ctr1,ctr2;
textcolor(15);
for(i=0;i<SIZE;i++)
for(j=0;j<SIZE;j++)
{
clrscr();
draw();
ctr=0;
count=1;
activepoint.x=i;
activepoint.y=j;
gotoxy(activepoint.y*4+2,activepoint.x*2+2);
printf("%02dK",count);
while(count<=SIZE*SIZE)
	{
	nextpoint=getnext(&board[activepoint.x][activepoint.y]);
	if(nextpoint.x!=-1)
		{
		activepoint=nextpoint;
		count++;
		ctr++;
		gotoxy(50,22); printf("ctr=%ld count=%d",ctr,count);
		gotoxy(activepoint.y*4+2,activepoint.x*2+2);
		printf("%02dK",count);
		}
	else
	{
	// Retreat back
	count--;
	ctr++;
	nextpoint=getprev(&board[activepoint.x][activepoint.y]);

	board[activepoint.x][activepoint.y].nextmove=-1;
	board[activepoint.x][activepoint.y].prevmove=-1;
	gotoxy(50,22); printf("ctr=%ld count=%d",ctr,count);
		gotoxy(activepoint.y*4+2,activepoint.x*2+2);
		printf("%d,%d",activepoint.x,activepoint.y);
		activepoint=nextpoint;
	}
	if(count==SIZE*SIZE)
	{
	getch();
	break;
	}
	if(count==0)
	{
	gotoxy(1,23);
	printf("%02d,%02d has no solution",i,j);
	getch();
	gotoxy(1,23);
	printf("                         ");
	break;
	}
	}
}
getch();
}

struct point getnext(struct box *b)
{
struct point t;
struct point nextmoves[8]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

for(b->nextmove++;b->nextmove<=7;b->nextmove++)

{
t.x=b->loc.x;
t.y=b->loc.y;

	t.x+=nextmoves[b->nextmove].x;
	t.y+=nextmoves[b->nextmove].y;
	if(t.x>=0&&t.x<SIZE&&t.y>=0&&t.y<SIZE)
		if(!havevisited(t))
		{
		 board[t.x][t.y].prevmove=(b->nextmove+4)%8;
		  return t;
		 }
}
t.x=t.y=-1;
return t;

}

struct point getprev(struct box *b)
{
struct point t;

struct point nextmoves[8]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
t.x=nextmoves[b->prevmove].x+b->loc.x;
t.y=nextmoves[b->prevmove].y+b->loc.y;
return t;
}

int havevisited(struct point boxnum)
{
if(board[boxnum.x][boxnum.y].nextmove==-1) return 0;
//if(count==SIZE*SIZE && i==board[boxnum.x][boxnum.y].loc.x && j==board[boxnum.x][boxnum.y].loc.y) return 0;
if(count==SIZE*SIZE) return 0;
return 1;
}

void draw()
{
	int ctr1,ctr2;
	printf("+---+---+---+---+---+---+---+---+");
	for(ctr1=0;ctr1<SIZE;ctr1++)
	{
	printf("\n|   |   |   |   |   |   |   |   |");
	printf("\n+---+---+---+---+---+---+---+---+");
	}

	for(ctr1=0;ctr1<SIZE;ctr1++)
	for(ctr2=0;ctr2<SIZE;ctr2++)
	{
		gotoxy(ctr2*4+2,ctr1*2+2);
		printf("%d,%d",ctr1,ctr2);
		board[ctr1][ctr2].loc.x=ctr1;
		board[ctr1][ctr2].loc.y=ctr2;
		board[ctr1][ctr2].nextmove=board[ctr1][ctr2].prevmove=-1;
	}

}
