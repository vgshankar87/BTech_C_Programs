#include<stdio.h>
#include<conio.h>
void convbin(int);
void main(void)
{
int num;
clrscr();
printf("Enter a Number : ");
scanf("%d",&num);
printf("\nOctal Code  :%5o\nHex Code    :%5x",num,num);
convbin(num);
getch();
}
void convbin(int dec)
{
int pwr=16384;
int i;
printf("\nBinary Code : 0");
for(i=0;i<15;i++)
{
if(pwr<=dec)
{
printf("1");
dec=dec-pwr;
}
else printf("0");
pwr/=2;
//if(dec<1) break;
}
}