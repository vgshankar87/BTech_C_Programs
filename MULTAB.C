#include<stdio.h>
#include<conio.h>
#define RANGE 20
void main(void)
{
long int num,i;
clrscr();
printf("Enter a number to get its multiplication table : ");
scanf("%ld",&num);
for(i=1;i<=RANGE;i++)
{
printf("%ld X %ld = %ld\n",num,i,num*i);
}
getch();
}