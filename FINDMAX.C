#include<stdio.h>
#include<conio.h>
#define RANGE 4
void main(void)
{
int max=-32768,n,i;
clrscr();
printf("Enter four numbers to find Maximum of them.\n");
for(i=0;i<RANGE;i++)
{
printf("< : > ");
scanf("%d",&n);
if(n>max) max=n;
}
printf("\nMaximum is : %d",max);
getch();
}

