#include<stdio.h>
#include<conio.h>
void midv();
void midh();

int x=0,y=0;
int tlcor=201,tmidj=203,mid=205,trcor=187;
int mvert=186,mleft=204,cross=206,mright=185;
int blcor=200,bmidj=202,brcor=188;

void main()
{
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





getch();
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