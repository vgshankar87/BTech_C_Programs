#include<stdio.h>
#include<graphics.h>
#include<alloc.h>
void main()
{
int gd=DETECT,gm,area,x=25,y=25,ch,xdirn=1,ydirn=1;
int maxx,maxy;
char *buff;

initgraph(&gd,&gm,"");
setcolor(WHITE);
setfillstyle(SOLID_FILL,GREEN);
circle(50,50,25);
floodfill(50,50,WHITE);

area=imagesize(25,25,75,75);
buff=malloc(area);
getimage(25,25,75,75,buff);

maxx=getmaxx();
maxy=getmaxy();
rectangle(0,20,maxx,maxy);
outtextxy(250,10,"Animation");

while(1)
	{
	if(kbhit())
		{
		ch=getch();
		if(ch=='\r')
			{
			xdirn *=-1;
			ydirn *=-1;
			}
		else
			{
			if(ch==27)
				break;
			}
		}
	putimage(x,y,buff,XOR_PUT);
	delay(0);
	x+=xdirn*1;
	y+=ydirn*1;
	putimage(x,y,buff,XOR_PUT);

	if(x>maxx-51 || x<0)
		{
		sound(800);
		delay(50);
		nosound();
		xdirn*=-1;
		}
	if(y>maxy-51 || y<20 )
		{
		sound(800);
		delay(50);
		nosound();
		ydirn*=-1;
		}
	}
getch();
closegraph();
restorecrtmode();
}