#include<stdio.h>
#include<conio.h>
FILE *fp;
typedef struct
{
       int yy:7;
       int mm:4;
       int dd:5;

}DATE;
union x
{
	DATE test;
	int datevalue;
};

typedef struct
{
	int empno;
	char empname[45];
	DATE dob;
	float weight;
}EMP;


void main(void)
{
   union x test1={20,10,10};
   clrscr();
   printf("size : %d",sizeof(DATE));
   printf("%d\n",test1.datevalue);
   getch();
}


showfileinfo()
{
printf("LEVEL %d\n",fp->level);
printf("FD %d\n",fp->fd);
printf("Buffer size is %u\n",fp->bsize);
printf("BUFFER address is %u\n",fp->buffer);
printf("Active Pointer is %u\n",fp->curp);
getch();
}

/*printbuffer()
{
for(;fp->level>0;fp->level--,fp->curp++)
printf("%c",*fp->curp);
} */