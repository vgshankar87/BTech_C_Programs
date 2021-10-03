#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void addnum();
void printasc(struct tree *);
void printdesc(struct tree *);
void makenode();
void addtotree(struct tree *);
void removenum();
struct tree
{
int num;
struct tree *left,*right;
};
struct tree *root=NULL,*ptr,*prev,*newnode;
void main()
{
int choice;
do
{
clrscr();
printf("MENU \n 1.ADD \n 2.PRINT ASC \n 3.PRINT DESC \n 4.REMOVENUM 5.QUIT\n ENTER CHOICE :");
scanf("%d",&choice);
fflush(stdin);
switch(choice)
{
case 1 :addnum();break;
case 2 :printasc(root);
	getch();
	break;
case 3 :printdesc(root);
	getch();
	break;
case 4 :removenum();
	break;
}
}
while(choice!=5);
}

void addnum()
{
makenode();
printf("Enter the number : ");
scanf("%d",&newnode->num);
fflush(stdin);
addtotree(newnode);
}


void makenode()
{
newnode=(struct tree *)malloc(sizeof(struct tree ));
newnode->left=newnode->right=NULL;
}


void addtotree(struct tree * newnode)
{
for(ptr=root;ptr;prev=ptr,ptr=ptr->num>newnode->num?ptr->left:ptr->right);
if(ptr==root)
root=newnode;
else if(prev->num>newnode->num)
prev->left=newnode;
else
prev->right=newnode;
}

void printasc(struct tree * dptr)
{
if(dptr)
{
printasc(dptr->left);
printf("%d\t",dptr->num);
printasc(dptr->right);
}
}

void printdesc(struct tree * dptr)
{
if(dptr)
{
printdesc(dptr->right);
printf("%d\t",dptr->num);
printdesc(dptr->left);
}
}

void removenum()
{
int num2rem;
struct tree *tptr;
printf("Enter the number to be removed  :  ");
scanf("%d",&num2rem);
fflush(stdin);
for(ptr=root;ptr&&ptr->num!=num2rem;prev=ptr,ptr=ptr->num>num2rem?ptr->left:ptr->right);
if(ptr)
	{
	//FOR DELETION OF NODES WITH SINGLE CHILD//

	if(!ptr->left||!ptr->right)
		{

		if(prev->num>num2rem) prev->left=ptr->left?ptr->left:ptr->right;
		else prev->right=ptr->left?ptr->left:ptr->right;
		}
	else
		{
		for(tptr=ptr->left;tptr->right;tptr=tptr->right);
		tptr->right=ptr->right;
		if(prev->num>num2rem)
		prev->left=ptr->left;
		else prev->right=ptr->left;

		}
	}
else printf("\n Number Not Found . . . ");
}
