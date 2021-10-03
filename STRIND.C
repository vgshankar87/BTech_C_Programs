#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<float.h>

int calcstore(int, int , int);
void addemp();
void removeemp();
void listall();
void list();
void update();
typedef struct
{
int empno;
long offset;
} INDEX;
typedef struct
{
       int dd:5;
       int mm:4;
       int yy:7;

}DATE;
union x
{
	DATE test;
	int datevalue;
};

typedef struct
{
	int empno;
	char empname[46];
	union x dob, doj;
	char mobilenum[14];
}EMP;
char ch ;
EMP rec;
INDEX indrec;
FILE *fp, *indfp;
int d,m,y;

int ctr;
void main(void)
{
int choice;

do
{
clrscr();
printf("Menu :\n 1.Add Employee\n 2.Remove Employee\n 3.List all\n 4.List\n 5. Update\n 6. Index it\n 7.Exit\n Enter your choice : ");
scanf("%d",&choice);
fflush(stdin);

switch(choice)
{
case 1 : addemp();
	break;
case 2 : removeemp();
	break;
case 3 : listall();
	break;
case 4 : list();
	break;
case 5 : update();
	break;
case 6 : indexit(); break;
}
}while(choice!=7);

}

void floatcall(float * fptr)
{
float a=3.14;
floatcall(&a);

}


int calcstore(int d, int  m, int y)
{
return d+m*32+(y-1980)*512;
}

convertdate(int datval)
{
y = (datval / 512) + 1980;
datval = datval % 512;
m = datval / 32;
d = datval % 32;
}

void addemp()
{
FILE *fp;
fp=fopen("emp.dat","a+");

   do{
   clrscr();
   printf("enter th employee number : ");
   scanf("%d", &rec.empno);
fflush(stdin);
   printf("enter th employee name   : ");
   scanf("%s", rec.empname);
fflush(stdin);
   printf("enter th employee DOB    : ");
   scanf("%d/%d/%d", &d,&m, &y);
fflush(stdin);
rec.dob.datevalue=calcstore(d,m,y);
   printf("enter th Date Of Joining : ");
scanf("%d/%d/%d", &d,&m, &y);
fflush(stdin);
rec.doj.datevalue=calcstore(d,m,y);
printf("Enter Mobile Number : ");
scanf("%s",rec.mobilenum);
fflush(stdin);

fwrite(&rec,sizeof(rec),1,fp);
   printf("do u want 2 continue     : ");
   scanf("%c", &ch);
fflush(stdin);
}while(ch=='y');
fclose(fp);
}



void removeemp()
{


}

void list()
{
int res=0,tempnum;
char found = 'n';
fp = fopen("emp.dat","r");
indfp = fopen("emp.ndx","r");

do
{
printf("Enter the Employee number : ");
scanf("%d", &tempnum);
fflush(stdin);
found='n';
do
{
res=fread(&indrec, sizeof(indrec), 1, indfp);
if(rec.empno==tempnum)
{
fseek(fp,indrec.offset,0);
   printf("Employee number : %d\n", rec.empno);     ;
   printf("Employee name   : %s\n", rec.empname);
   convertdate(rec.dob.datevalue);
   printf("Employee DOB    : %d/%d/%d\n", d,m, y);
   convertdate(rec.doj.datevalue);
   printf("Employee DOJ    : %d/%d/%d\n", d,m, y);
   printf("Mobile Number   : %s ",rec.mobilenum);
found='y';
getch();

}
else res = fread(&rec, sizeof(rec), 1 , fp);
}while (res!=0 && found == 'n');
} while (tempnum!=0);

}


void listall()
{
   fp = fopen("emp.dat","r");
while(fread(&rec,sizeof(rec),1,fp))
{
   clrscr();
   printf("Employee number : %d\n", rec.empno);
   printf("Employee name   : %s\n", rec.empname);
   convertdate(rec.dob.datevalue);
   printf("Employee DOB    : %d/%d/%d\n", d,m, y);
   convertdate(rec.doj.datevalue);
   printf("Employee DOJ    : %d/%d/%d\n", d,m, y);
   printf("Mobile Number   : %s ",rec.mobilenum);
getch();
}
fclose(fp);
}


void update()
{
}





indexit()
{
long tempoffset;
       int res;
   fp = fopen("emp.dat","r");
   indfp  =fopen("emp.ndx","w");
   indrec.offset = ftell(fp);
fread(&rec,sizeof(rec),1,fp);
indrec.empno  = rec.empno;
if(indrec.offset!=-1L)
{
do
{
fwrite(&indrec, sizeof(indrec), 1, indfp);
indrec.offset = ftell(fp);
res=fread(&rec,sizeof(rec),1,fp);
indrec.empno  = rec.empno;

}while(res!=0);

}
fclose(fp); fclose(indfp);
}