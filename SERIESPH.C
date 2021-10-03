#include<stdio.h>
#include<conio.h>
void main(void)
{
int call,prevcall=0,count1=0,count2=0,run1=0,run2=0,maxrun1=0,maxrun2=0,rf=0,rl=1;
clrscr();
printf("Enter Series of phone calls. Enter 0 to terminate : ");
do
	{
	scanf("%d,",&call);

	if(call==1)
		count1++;
	else if(call==2)
		count2++;

	if(call==prevcall)
		{
		if(rf==0) rf=1;
		rl++;
		}
	if(rf==1&&call!=prevcall)
		{
		if(prevcall==1)
			{
			run1++;
			if(rl>maxrun1) maxrun1=rl;
			}
		else if(prevcall==2)
			{
			run2++;
			if(rl>maxrun2) maxrun2=rl;
			}

		rf=0;
		rl=1;
		}
	prevcall=call;
	} while(call!=0);
printf("count1=%d count2=%d\nrun1  =%d  run2 =%d\nMaxrun1= %d Maxrun2= %d",count1, count2,run1,run2,maxrun1,maxrun2);
getch();
}