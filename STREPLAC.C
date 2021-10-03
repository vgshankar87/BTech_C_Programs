#include<stdio.h>
#include<conio.h>
void main(void)
{
char string[50]="\n",substr[50]="\n",repl[50]="\n",newstr[50]="\n";
char * s, * ss, *r, *ns;
int fl=0,len=0,i=0,j=0,replen=0,tj=0,ti=0,sublen=0;
s=string;
ss=substr;
r=repl;
ns=newstr;
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
sublen=i;

printf("Replace with : ");
for(i=0;i<50;i++)
{
scanf("%c",r+i);
if(*(r+i)=='\n') break;
}
replen=i;

for(j=0;*(s+j)!='\n';j++)
{
i=0;
if(*(s+j)==(*ss+i))
	{
	for(tj=j,i=0;(*(s+tj)==*(ss+i)) && *(s+tj)!='\n';tj++,i++)
		if(*(ss+i+1)=='\n')
			{
			for(ti=0,i=0;i<j;i++,ti++)
				*(ns+ti)=*(s+i);
			for(i=0;i<replen;i++,ti++)
				*(ns+ti)=*(r+i);
			for(i=j+sublen;*(s+i)!='\n';i++,ti++)
				*(ns+ti)=*(s+i);
			for(i=0;*(ns+i)!='\n';i++)
				*(s+i)=*(ns+i);
                        }


	}
}

for(i=0;i<20;i++)
{
printf("%c",*(s+i));
}

getch();

}

