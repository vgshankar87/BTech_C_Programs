#include<stdio.h>
#include<conio.h>
void main(void)
{
char string[30]={"\n"};
char * c;
int i=0;
c=string;
clrscr();
printf("Enter a string : ");
for(i=0;i<30;i++)
	{
	scanf("%c",c+i);
	if(*(c+i)=='\n') break;
	}

for(i=0;i<30;i++)
	{
	if(*(c+i)>='a' && *(c+i)<='z')
		*(c+i)-=32;
	}

printf("\n");

for(i=0;*(c+i)!='\n';i++)
	printf("%c",*(c+i));


getch();
}

