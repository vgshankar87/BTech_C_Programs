#include<stdio.h>
#include<conio.h>
void main(void)
{
int d,m,y,refyr=1900,refm=0,rem,i,j,w=0,dc=1;
int mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
char day[7][3]={'M','O','N','T','U','E','W','E','D','T','H','U','F','R','I','S','A','T','S','U','N'};
long nod=0;
char c;
clrscr();
printf("Enter a date after the year 1900 (DD MM YYYY) : ");
scanf("%d %d %d",&d,&m,&y);
if(!(y%4))
	{
	mon[1]++;
	if(!(y%100)&&(y%400)) mon[1]--;
	}
for(;refyr<y;refyr++)
	{
	nod+=365;
	if(!(refyr%4))
		{
		nod++;
		if(!(refyr%100)&&(refyr%400)) nod--;
		}
	}
for(;refm<m-1;refm++)
	{
	nod+=mon[refm];
	}
rem=nod%7;
printf("\n\n");
for(j=0;j<7;j++)
	{
	for(i=0;i<3;i++)
		{
		printf("%c",day[j][i]);
		}
	printf("\t");
	}
printf("\n");
for(;rem>0;rem--)
	{
	printf("\t");
	w++;
	}
for(;dc<=mon[m-1];dc++)
	{
	printf(" %2d\t",dc);
	w++;
	if(w==7)
		{
		printf("\n");
		w=0;
		}
	}
getch();
}
