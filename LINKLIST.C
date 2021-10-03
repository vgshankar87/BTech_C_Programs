#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>


//FUNCTION DECLARATION//

void makenode();
void addname();
void addtolist(struct namelist*);
void removename();
void print_asc(struct namelist*);
void print_desc(struct namelist*);

//STRUCTURE DECLARATION//


struct namelist
{
char name[40];
struct namelist *next;
};
struct namelist *start=NULL,*prev,*newnode,*ptr;


//MAIN FUNCTION BEGINS HERE//


void main()
{
int choice;
clrscr();
do
{

printf("MENU \n 1.ADD NAME \n 2.REMOVE NAME\n 3.PRINT ASC\n 4.PRINT DESC\n 5.QUIT\n ENTER CHOICE : ");
scanf("%d",&choice);
fflush(stdin);

switch(choice)
{
case 1: addname();break;
case 2: removename();break;
case 3: if(start) print_asc(start);break;
case 4: if(start) print_desc(start);break;
}

}
while(choice!=5);
}

void addname()
{
makenode();
printf("Enter the name : ");
scanf("%s",newnode->name);
fflush(stdin);
addtolist(newnode);
}

void makenode()
{
newnode=(struct namelist *)malloc(sizeof(struct namelist));
newnode->next=NULL;
}

void addtolist(struct namelist *newnode)
{
for(ptr=start;ptr&&strcmp(newnode->name,ptr->name)>=0;prev=ptr,ptr=ptr->next);
if(start==ptr)
{
newnode->next=start;
start=newnode;
}
else
{
prev->next=newnode;
newnode->next=ptr;
printf("%s added after %s\n",newnode->name,prev->name);
getch();
}
}

void print_asc(struct namelist *dptr)
{
printf("Name %s at %u\n",dptr->name,dptr);
getch();
if(dptr->next)
print_asc(dptr->next);
}
void print_desc(struct namelist *dptr)
{
if(dptr->next)
print_desc(dptr->next);
printf("Name %s \n",dptr->name);
}
void removename()
{
char name2rem[40];
printf("Enter name to remove : ");
scanf("%s",name2rem);
fflush(stdin);
for(ptr=start;ptr && strcmp(ptr->name,name2rem)!=0;prev=ptr,ptr=ptr->next);
if(ptr)
{
if(ptr==start)
start=start->next;
else
prev->next=ptr->next;
free(ptr);
}
else
{
printf("Name does not exist............ \n");
}
printf("NameRemoved\n");
}

