#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void print();
void addword();
void findrepl();
void fsave(FILE *);

char word[45]="a";
char findw[45],replw[45];
char nchar;

struct ll
{
char * word;
char nc;
struct ll *next;
} *newnode, *start=NULL, *ptr;

void dest(struct ll*);

void main()
{
FILE *fptr;
char ch='a',fname[20];
int ctr=0;
clrscr();
printf("Enter File Name : ");
scanf("%s",&fname);
fflush(stdin);

if(!(fptr=fopen(fname,"r")))
	{
	printf("File Not Found...");
	getch();
	return;
	}

while(ch!=EOF)
{
ch=fgetc(fptr);
	if(ch==' '||ch=='\n'||ch==NULL||ch==EOF||ch=='.'||ch==','||ch==';'||ch==':')
	{
	if(ch!=EOF)
	nchar=ch;
	word[ctr]=NULL;
	addword(word);
	ctr=0;
	word[0]=NULL;
	}
	else word[ctr++]=ch;
}
fclose(fptr);
print();
printf("\nEnter Word to Find : ");
scanf("%s",&findw);
fflush(stdin);
printf("Replace %s with : ",findw);
scanf("%s",&replw);
fflush(stdin);
findrepl();
print();
printf("\n\nSave Change to file ? (Y/N) : ");
scanf("%c",&nchar);
fflush(stdin);
if(nchar=='y'||nchar=='Y')
if((fptr=fopen(fname,"w+"))) fsave(fptr);
else printf("\nError Occured While Writing...");
dest(start);
getch();
}

void addword()
{
newnode=(struct ll *) malloc(sizeof(struct ll));
newnode->next=NULL;
newnode->word=(char *) malloc(sizeof(word));
strcpy(newnode->word,word);
newnode->nc=nchar;
 if(start==NULL) start=newnode;
 else
 {
 for(ptr=start;ptr->next;ptr=ptr->next);
 ptr->next=newnode;
 }
}

void print()
{
	for(ptr=start;ptr;ptr=ptr->next)
	{
	printf("%s",ptr->word);
	if(ptr->nc==' ' || '\n') printf("%c",ptr->nc);
	}
}

void dest(struct ll *st)
{
if(st->next) dest(st->next);
free(st);
}

void findrepl()
{
	for(ptr=start;ptr;ptr=ptr->next)
	{
		if(strcmp(ptr->word,findw)==0)
		{
		free(ptr->word);
		ptr->word=(char *) malloc(sizeof(replw));
		strcpy(ptr->word,replw);
		}

	}

}

void fsave(FILE *fptr)
{
	for(ptr=start;ptr;ptr=ptr->next)
	{
	fputs(ptr->word,fptr);
	fputc(ptr->nc,fptr);
	}
fclose(fptr);
printf("\nFile Saved...");
}