#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define SIZE 8
void main()
{
int gd=DETECT,gm,maxx,maxy,x,y,a,b,c,d,button,ctr1,ctr2;
char patternw[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
char patternb[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

clrscr();
initgraph(&gd,&gm,"d:\\tc3\\bgi");
maxx=getmaxx();
maxy=getmaxy();

//rectangle(10,10,maxx-10,maxy-10);
//setviewport(1,1,maxx-1,maxy-1,1);
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


for(ctr1=0;ctr1<SIZE;ctr1++)
for(ctr2=0;ctr2<SIZE;ctr2++)
{
if((ctr1+ctr2)%2)
setcolor(BLACK);
else
setcolor(WHITE);
settextstyle(4,0,3);
outtextxy(20+ctr1*50,15+ctr2*50,"Q");
}


getch();
clrscr();

}

