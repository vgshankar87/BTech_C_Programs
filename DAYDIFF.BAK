#include<stdio.h>
#include<conio.h>
long calcnod(int,int,int);
void main(void)
{
int d,m,y;
long nod1,nod2,days;
char c;
do
{
clrscr();
printf("Enter First date (After 1900) (DD MM YYYY) : ");
scanf("%d %d %d",&d,&m,&y);
nod1=calcnod(d,m,y);
printf("Enter Second date (After 1900) (DD MM YYYY) : ");
scanf("%d %d %d",&d,&m,&y);
nod2=calcnod(d,m,y);
days=(nod1>nod2)?(nod1-nod2):(nod2-nod1);
printf("Days Inbetween : %ld",days);
getch();
fflush(stdin);
printf("\nTry Again ? (Y/N) : ");
scanf("%c",&c);
} while(c=='y'||c=='Y');
}


long calcnod(int d,int m,int y)
{
long nod=0,refyr=1900,refm=0;
int mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
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
for(;refm<m-1;refm++)
	{
	nod+=mon[refm];
	}
nod+=d-1;
return(nod);
}