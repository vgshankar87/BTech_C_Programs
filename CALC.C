#include<stdio.h>
#include<bios.h>
#include<conio.h>
int numarray[]={2864,21040,561,20273,818,20530,1075,20787,1332,19252, \
 1589,19509,1846,19766,2103,18231,2360,18488,2617,18745\
 ,3371,20011,3117,18989,2346,14122,13615,13615,3389,7181};

long int fnum,snum,collectnum();
int optr;
void main()
{
clrscr();
fnum=collectnum();
do
{
snum=collectnum();
switch(optr)
{
case 10 : fnum=fnum+snum; optr=0; break;
case 11 : fnum=fnum-snum; optr=0; break;
case 12 : fnum=fnum*snum; optr=0; break;
case 13 : fnum=fnum/snum; optr=0; break;
}
gotoxy(10,10);
printf("%20ld",fnum);

gotoxy(70,23); printf("%d",optr);
}while(optr!=14);
getch();

}

long int collectnum()
{
int keynum,res;
long val=0;
gotoxy(30,10);

do
{
while(bioskey(1)==0);
keynum=bioskey(0);
res=keysearch(keynum);
if(res < 10)
{
val=val*10 + res;
}
gotoxy(10,10);
printf("%20ld",val);
}while(res<10);
if (optr==0) optr = res;
return val;
}

int keysearch(unsigned int key)
{
int ctr;
for(ctr=0;key!=numarray[ctr] && ctr <30;ctr++);
if(ctr<=29) return ctr/2;

}