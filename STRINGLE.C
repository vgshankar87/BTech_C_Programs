#include<stdio.h>
#include<conio.h>
void main(void)
{
char string[30]={"\n"},revstr[30]={"\n"};
char * c, * r;
int length=0,i=0,flag=1;
c=string;
r=revstr;
clrscr();
printf("Enter a string : ");
for(i=0;i<30;i++)
{
scanf("%c",c+i);
if(*(c+i)=='\n') break;
}

//find length
for(length=0;*(c+length)!='\n';length++);

printf("\n String Length Is : %d",length--);

//reverse

for(i=0;length>=0;length--,i++)
	*(r+i)= *(c+length);

for(i=0;string[i]!='\n';i++)
{
if(string[i]!=revstr[i])
	{
	flag=0;
	}
}
if(flag==1) printf("\n\n It is a Palindrome ! ");
else printf("\n\n It is a Not Palindrome. ");


getch();
}

