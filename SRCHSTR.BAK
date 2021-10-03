#include<stdio.h>
#include<conio.h>
void main(void)
{
char string[50]="\n",substr[50]="\n";
char * s, * ss;
int fl=0,len=0,i=0,j=0,ti=0,tj=0;
s=string;
ss=substr;
clrscr();
printf("Enter a string : ");
for(i=0;i<50;i++)
{
scanf("%c",s+i);
if(*(s+i)=='\n') break;
}

printf("Enter a sub string to search : ");
for(i=0;i<50;i++)
{
scanf("%c",ss+i);
if(*(ss+i)=='\n') break;
}

for(j=0;*(s+j)!='\n';j++)
{
i=0;
if(*(s+j)==(*ss+i))
	{
	for(tj=j,i=0;(*(s+tj)==*(ss+i)) && *(s+tj)!='\n';tj++,i++)
		if(*(ss+i+1)=='\n') fl=1;
	}

}
if(fl==1) printf("Substring Found !");
else printf("Not Found ");



getch();

}

