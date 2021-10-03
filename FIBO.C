#include<stdio.h>
#include<conio.h>
void main(void)
{
int n,sum,p,c,temp;
clrscr();
printf("%50s\nEnter number of terms : ","FIBONACCI SERIES");
scanf("%d",&n);

sum=1;
p=0;
c=1;
printf("\n%d\t%d",p,c);
for(;n>2;n--)
{
temp=c;
c=p+c;
p=temp;
sum+=c;
printf("\t%d",c);
}
printf("\n\nSUM = %d",sum);

getch();
}