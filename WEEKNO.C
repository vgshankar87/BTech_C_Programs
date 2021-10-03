#include<stdio.h>
#include<conio.h>
void main(void)
{
int d,m,y,refyr=1900,refm=0,rem,i,diff;
int mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
long nod=0;
clrscr();
printf("Enter a date (DD MM YYYY) : ");
scanf("%d %d %d",&d,&m,&y);

if(!(y%4))
	{
	mon[1]++;
	if(!(y%100)&&(y%400))
		{
		mon[1]--;
		}
	}

for(;refyr<y;refyr++)
	{
	nod+=365;
	if(!(refyr%4))
		{
		nod++;
		if(!(refyr%100)&&(refyr%400))
			{
			nod--;
			}
		}
	}
diff=nod%7;
nod=0;
for(;refm<m-1;refm++)
	{
	nod+=mon[refm];
	}
nod+=d-1;
nod+=diff;
printf("\n%ld",nod);
rem=nod/7;
printf("\nWeek No. : %d",rem+1);
getch();
}