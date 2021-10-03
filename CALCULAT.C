#include<dos.h>
#include<stdio.h>
#include<conio.h>
enum BOOL {FALSE,TRUE};
union REGS i,o;
struct SREGS s;
int x1,x,y1,y,click,key,optr;
enum BOOL dot,opr;
double ans,temp;
char array[31];
int ctr;

void main()
{
drawcalc();
gotoxy(55,5);
initmouse();
showmouseptr();
while(click!=3)
{
getpositionstatus();
if(!(x==x1 &&y==y1)) click=0;
if(click==1)
{
if((key=whatclicked(x,y))==whatclicked(x1,y1))
{
process(key);
}

}
}
}

process(int key)
{
if(key<10)
{
if(opr==TRUE)
{
ctr=0;
opr=FALSE;
}
array[ctr++]=key+48;
}
if(key==10 && dot!=TRUE)
{
array[ctr++]='.';
dot=1;
}
array[ctr]=NULL;
if(key>11 && key< 19) operate(key);
gotoxy(25,5);
printf("%30s",array);
}

operate(int key)
{
gotoxy(1,1);
printf("%d",key);
temp=atof(array);
if(!optr)
{ ans=temp;
optr=key;
opr=TRUE;
return;
}
else
{
if(key==12) ans+=temp;
else if(key==13) ans-=temp;
else if(key==14) ans*=temp;
else if(key==15) ans/=temp;
opr=TRUE;
gotoxy(25,5);
printf("%le",ans);
}
}

int whatclicked(int x,int y)
{
// 0
if(x>=184 && x<=216 && y>=152 && y<=168) return 0;
// .
if(x>=240 && x<=272 && y>=152 && y<=168) return 10;

// +/-
if(x>=296 && x<=328 && y>=152 && y<=168) return 11;
// %
if(x>=352 && x<=384 && y>=152 && y<=168) return 16;

// 1
if(x>=184 && x<=216 && y>=128 && y<=144) return 1;
// 2
if(x>=240 && x<=272 && y>=128 && y<=144) return 2;

// 3
if(x>=296 && x<=328 && y>=128 && y<=144) return 3;
// sqrt
if(x>=352 && x<=384 && y>=128 && y<=144) return 17;

// 4
if(x>=184 && x<=216 && y>=104 && y<=120) return 4;
// 5
if(x>=240 && x<=272 && y>=104 && y<=120) return 5;

// 6
if(x>=296 && x<=328 && y>=104 && y<=120) return 6;
// +
if(x>=352 && x<=384 && y>=104 && y<=120) return 12;

// 7
if(x>=184 && x<=216 && y>=80 && y<=96) return 7;
// 8
if(x>=240 && x<=272 && y>=80 && y<=96) return 8;
// 9
if(x>=296 && x<=328 && y>=80 && y<=96) return 9;
// X
if(x>=352 && x<=384 && y>=80 && y<=96) return 14;

if(y>=56 && y<=72)
{
	if(x>=184 && x<=216)
	return 22;
	else if(x>=240 && x<=272)
	return 20;
	else if(x>=296 && x<=328)
	return 21;
	else if(x>=352 && x<=384)
	return 19;
	else if(x>=408 && x<=440)
	return 23;
}
else if(x>=408 && x<=440)
{
	if(y>=80 && y<=96)
	return 15;
	else if(y>=104 && y<=120)
	return 13;
	else if(y>=128 && y<=168)
	return 18;
}
}


drawcalc()
{
FILE *fptr;
int ch;
fptr=fopen("d:\\tc3\\bin\\calc.txt","r");
textcolor(15);
clrscr();
while((ch=fgetc(fptr))!=EOF) putc(ch,stdout);
fclose(fptr);
}

initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}
showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
}

getpositionstatus()
{
i.x.ax=0x0003;
int86(0x33,&i,&o);
x=o.x.cx;
y=o.x.dx;
click=o.x.bx;
while(getreleasestatus()==1);
}

getreleasestatus()
{
i.x.ax=0x0006;
i.x.bx=0x0000;
int86(0x33,&i,&o);
x1=o.x.cx;
y1=o.x.dx;
return o.x.ax;
}