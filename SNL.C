#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include <dos.h>

void midv();
void midh();
void getplayers();
struct player
{
char name[35];
int position,turns;
int active;
int num;
int coincolor;
int cointype;
int rank;
struct player * next;
};
struct player *playturn,* start, * newplayer;
int count,ctr1,ctr2,coin[]={1,2,3,4,5,6,14,15,21,30}, coinid;
int coinclr,blink=128,pnum;
int win,dice;
//                       1   2   3   4   5   6   7   8   9   10
int displacement[100]={ 37,  0,  0, 10,  0,  0,  0,  0, 22,  0,
			 0,  0,  0,  0,  0,-10,  0,  0,  0,  0,
			21,  0,  0,  0,  0,  0,  0, 56,  0,  0,
			 0,  0,  0,  0,  0,  8,  0,  0,  0,  0,
			 0,  0,  0,  0,  0,  0,  0,  0,-38,  0,
			16,  0,  0,  0,  0, -3,  0,  0,  0,  0,
			 0,-43,  0, -4,  0,  0,  0,  0,  0,  0,
			20,  0,  0,  0,  0,  0,  0,  0,  0, 20,
			 0,  0,  0,  0,  0,  0,-63,  0,  0,  0,
			 0,  0,-20,  0,-20,  0,  0,-20,  0,  0
		};
char ch;

/*void intro()
{
	char line[81];
	int i;
	FILE *fptr;
	clrscr();
	fptr=fopen("snakes.txt","r");
	while((fgets(line,80,fptr))!=NULL)
	printf("%s",line);
	getch();

} */

int x=0,y=0;
int tlcor=201,tmidj=203,mid=205,trcor=187;
int mvert=186,mleft=204,cross=206,mright=185;
int blcor=200,bmidj=202,brcor=188;

void drawdappa()
{
textbackground(0);
textcolor(13);
clrscr();
printf("%c",tlcor);
for(x=0;x<9;x++)
	{
	printf("%c%c%c%c%c",mid,mid,mid,mid,tmidj);
	}
printf("%c%c%c%c%c\n",mid,mid,mid,mid,trcor);
for(y=0;y<9;y++)
	{
	midv();
	midh();
	}
midv();
printf("%c",blcor);
for(x=0;x<9;x++)
	{
	printf("%c%c%c%c%c",mid,mid,mid,mid,bmidj);
	}
printf("%c%c%c%c%c\n",mid,mid,mid,mid,brcor);

gotoxy(60,7);
printf("Numbers On Dice");

}

void marknum()
{
int numcount,x,y,temp;
for(numcount=0;numcount<100;numcount++)
	{
	temp=numcount;
	x=temp%10;
	temp/=10;
	y=temp%10;

	if(y%2)	gotoxy(48-5*x,21-(2*y));
	else gotoxy(3+5*x,21-(2*y));
	printf("%d",numcount+1);
	}
}

void showsnakenlad()
{
int numcount,x,y,temp;
for(numcount=0;numcount<100;numcount++)
	{
	if(displacement[numcount]!=0)
		{
		temp=numcount;
		x=temp%10;
		temp/=10;
		y=temp%10;

		if(y%2)	gotoxy(47-5*x,20-(2*y));
		else gotoxy(2+5*x,20-(2*y));
		if(displacement[numcount]>0)
			printf("L %2d",numcount+1+displacement[numcount]);
		else if(displacement[numcount]<0)
			printf("S %2d",numcount+1+displacement[numcount]);
		}
	}
}


void midv()
{
for(x=0;x<11;x++)
	printf("%c    ",mvert);
printf("\n");
}

void midh()
{
printf("%c",mleft);
for(x=0;x<9;x++)
	printf("%c%c%c%c%c",mid,mid,mid,mid,cross);
printf("%c%c%c%c%c\n",mid,mid,mid,mid,mright);
}

void getplayers()
{
int key=0;
textcolor(3);
printf("Enter Number of Players (1 - 4) : ");
scanf("%d",&count);
fflush(stdin);
for(ctr1=0;ctr1<count;ctr1++)
	{
	newplayer=(struct player *) malloc(sizeof(struct player));
	newplayer->next=NULL;
	newplayer->turns=newplayer->active=0;
	newplayer->position=-1;
	textcolor(3);
	printf("Enter Name For Player %d : ",ctr1+1);
	scanf("%s",&newplayer->name);
	fflush(stdin);
	newplayer->num=ctr1;
	fflush(stdin);
	if(start==NULL)
		start=newplayer;
	else
		{
		for(playturn=start;playturn->next;playturn=playturn->next);
		playturn->next=newplayer;
		}
	clrscr();

	ctr2=0;
	coinclr=1;
	textcolor(coinclr);
	printf("Coin : ");
	cprintf("%c",coin[ctr2]);

	do
	   {
		key=bioskey(0);

		if(key==19200)
		{
			ctr2--;
			if(ctr2==-1) ctr2=9;
			printf("\b");
			cprintf("%c",coin[ctr2]);
		}


		if(key==19712)
		{
			ctr2++;
			if(ctr2==10) ctr2=0;
			printf("\b");
			cprintf("%c",coin[ctr2]);
		}

		if(key==18432)
		{
			coinclr++;
			if(coinclr==16) coinclr=1;
			printf("\b");
			textcolor(coinclr);
			cprintf("%c",coin[ctr2]);
		}

		if(key==20480)
		{
			coinclr--;
			if(coinclr==0) coinclr=15;
			printf("\b");
			textcolor(coinclr);
			cprintf("%c",coin[ctr2]);
		}
		if(key==7181)
		{
			newplayer->coincolor=coinclr;
			newplayer->cointype=coin[ctr2];
		}


	   }while(key!=7181);

	textcolor(3);

	clrscr();
	}

newplayer->next=start;

}


void freememory(struct player * plyr)
{
if(plyr->next!=start)
	freememory(plyr->next);
free(plyr);
}

void clearcoin()
{
int pos=playturn->position,x,y;
if(pos>=0)
	{
	x=pos%10;
	pos/=10;
	y=pos%10;
	pnum=playturn->num;
	if(y%2)	gotoxy(45-5*x+2+pnum,20-(2*y));
	else gotoxy((5*x+2)+pnum,20-(2*y));
	printf(" ");
	}
}

void placecoin()
{
int pos=playturn->position,x,y;
x=pos%10;
pos/=10;
y=pos%10;
pnum=playturn->num;
if(y%2)	gotoxy(45-5*x+2+pnum,20-(2*y));
else gotoxy((5*x+2)+pnum,20-(2*y));
textcolor(playturn->coincolor);
cprintf("%c",playturn->cointype);
textcolor(11);
}

void displayer()
{
gotoxy(55,1);
printf("                          ");
gotoxy(55,1);
textcolor(playturn->coincolor);
cprintf("%c ",playturn->cointype);
textcolor(13);
printf("%s\'s Turn No:%3d",playturn->name,playturn->turns);
}

int randnum()
{
	struct time t;
	int ran;
	gettime(&t);
	ran=(t.ti_hund)%6;
	return(ran+1);
}

void main()
{
//intro();
textcolor(11);
clrscr();
getplayers();
drawdappa();
marknum();
showsnakenlad();

/* for(playturn=start,ctr1=0;ctr1<count;playturn=playturn->next,ctr1++)
	{
	placecoin();
	} */

gotoxy(55,3);
textcolor(10+blink);
cprintf("Press Enter To Throw Dice");
textcolor(13);
ch='a';
for(playturn=start;win<count&&ch!='q'&&ch!='Q';playturn=playturn->next)
	{
	if(playturn->position<99)
		{
		playturn->turns++;
		displayer();
//		dice=random(6)+1;
		dice=randnum();
		gotoxy(67,9);
		printf("  ");
		getch();
		gotoxy(67,9);
		printf("%2d",dice);
		clearcoin();
		playturn->position+=dice;
		if(playturn->position>99)
			playturn->position-=dice;
		playturn->position+=displacement[playturn->position];
		placecoin();
		if(playturn->position==99)
			{
			win++;
			playturn->rank=win;
			gotoxy(63,8+win*3);
			printf("Rank %d",win);
			gotoxy(55,9+win*3);
			printf("%s in %d Turns !",playturn->name,playturn->turns);
			}
		ch=getch();
		}
	}
freememory(start);
}