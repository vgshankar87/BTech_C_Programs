#include<stdio.h>
#include<conio.h>
void main(void)
{
long int num=0,numc=0;
int i=0,tens=0,ones=0;
char zero[5]={"Zero\n"};

char upto20[20][10]={"One\n","Two\n","Three\n","Four\n","Five\n","Six\n","Seven\n","Eight\n",\
		"Nine\n","Ten\n","Eleven\n","Twelve\n","Thirteen\n","Fourteen\n",\
		"Fifteen\n","Sixteen\n","Seventeen\n","Eighteen\n","Nineteen\n","Twenty\n"};

char upto100[9][8]={"Twenty\n","Thirty\n","Forty\n","Fifty\n","Sixty\n",\
		"Seventy\n","Eighty\n","Ninety\n","Hundred\n"};
clrscr();
printf("Enter a Number : ");
scanf("%d",&num);
numc=num;

if(num==0)
	for(i=0;zero[i]!='\n';i++)
		printf("%c",zero[i]);

else if(num<=20)
	for(i=0;upto20[num-1][i]!='\n';i++)
		printf("%c",upto20[num-1][i]);

else if(num<=100)
	{
	ones=numc%10;
	numc=numc/10;
	tens=numc%10;
	for(i=0;upto100[tens-2][i]!='\n';i++)
			printf("%c",upto100[tens-2][i]);
	printf(" ");
	if(ones!=0)
		for(i=0;upto20[ones-1][i]!='\n';i++)
		printf("%c",upto20[ones-1][i]);



	}


getch();
}