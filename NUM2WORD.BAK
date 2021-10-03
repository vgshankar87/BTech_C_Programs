#include<stdio.h>
#include<conio.h>
void printword(long);
void main(void)
{
long int num=0,ps=0;
clrscr();
printf("Enter an Amount (Rs.Ps) : ");
scanf("%ld.%ld",&num,&ps);
printword(num);
printf("Rupee");
if(num!=0 && num!=1)
	printf("s");
printf(" and ");
printword(ps);
printf("Paise Only. ");

getch();
}

void printword(long num)
{
 int i=0,j=0,n=0,tens=0,ones=0;
//onestens,huns,ths,laks,crores,arawbones;
int digits[12]={0,0,0,0,0,0,0,0,0,0,0,0};

char upto20[20][11]={"One \n","Two \n","Three \n","Four \n","Five \n","Six \n","Seven \n","Eight \n",\
		"Nine \n","Ten \n","Eleven \n","Twelve \n","Thirteen \n","Fourteen \n",\
		"Fifteen \n","Sixteen \n","Seventeen \n","Eighteen \n","Nineteen \n","Twenty \n"};

char tensupto100[9][9]={"Twenty \n","Thirty \n","Forty \n","Fifty \n","Sixty \n",\
		"Seventy \n","Eighty \n","Ninety \n","Hundred \n"};

char htlca[6][10]={"\n","Hundred \n","Thousand \n","Lakh \n","Crore \n","Arawb \n"};
if(num==0) printf("Zero ");
else
{
for(i=11;num>0;i--)
	{
	if(i==8) i--;
	digits[i]=num%10;
	num/=10;
	}
for(j=0;j<6;j++)
	{
	n=digits[j*2];
	n*=10;
	n+=digits[j*2+1];

	if(n>0)
		{
		if(n<=20)
			{
			for(i=0;upto20[n-1][i]!='\n';i++)
				printf("%c",upto20[n-1][i]);
			}
		else if(n<100)
			{
			ones=n%10;
			n/=10;
			tens=n%10;

			for(i=0;tensupto100[tens-2][i]!='\n';i++)
				printf("%c",tensupto100[tens-2][i]);
			if(ones!=0)
				for(i=0;upto20[ones-1][i]!='\n';i++)
				printf("%c",upto20[ones-1][i]);


			}
		for(i=0;htlca[5-j][i]!='\n';i++)
		printf("%c",htlca[5-j][i]);
		if(j==4 && (digits[10] || digits[11]))
			printf("and ");
		}


	}
/*	printf("\n");
	for(i=0;i<12;i++)
	printf(" %d ",digits[i]); */
}
}