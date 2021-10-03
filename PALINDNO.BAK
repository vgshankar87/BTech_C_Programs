#include<stdio.h>
#include<conio.h>
void main(void)
{
int n,m,rem,rev=0;
clrscr();
printf("Enter a number to check whether it is a palindrome or not : ");
scanf("%d",&n);
m=n;
while(m>0)
{
rev*=10;
rem=m%10;
m=m/10;
rev=rev+rem;
}
if(rev==n)
printf("\nIts a Palindrome ! :-)");
else
printf("\nIts Not a Palindrome :-(");
getch();
}