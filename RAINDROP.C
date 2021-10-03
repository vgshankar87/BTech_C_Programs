#include<dos.h>
#include<stdio.h>
#include<string.h>
char far * scr, *mode;
main()
{
 int ctr1=0,ctr2,ctr,key=0;
 char pass[]="sorry";
 char temp[]="dummy";
 if((*mode & 0x30)==0x30) scr=(char far *) 0xB0000000;
 else scr=(char far *) 0xB8000000;
 for(ctr=80*23*2;ctr>0;ctr-=2)
 {
 if(kbhit())
 key=getch();
 if(key)
 {
 temp[ctr1++]=key;
 temp[ctr1]=NULL;
 key=0;
  }
 if (strncmp(temp,pass,ctr1)!=0) { ctr1=0; temp[ctr1]=NULL;}
 else if(ctr1==5) break;

 for(ctr2=0;ctr2+(ctr/160)<23;ctr2++)
 {
 if(*(scr+ctr+ctr2*160)>32 && *(scr+ctr+ctr2*160+160)<33)
	{
	*(scr+ctr+ctr2*160+160)=*(scr+ctr+ctr2*160);
	*(scr+ctr+ctr2*160)=' ';
	delay(10);
	}
 else break;
 }

}
 for(ctr=160;ctr< 80*24*2;ctr+=2)
 {
 if(kbhit())
 key=getch();
 if(key)
 {
 temp[ctr1++]=key;
 temp[ctr1]=NULL;
 key=0;
  }
 if (strncmp(temp,pass,ctr1)!=0) { ctr1=0; temp[ctr1]=NULL;}
 else if(ctr1==5) break;

 for(ctr2=0;ctr-(ctr2*160)>160 ;ctr2++)
 {
 if(*(scr+ctr-ctr2*160)>32 && *(scr+ctr-ctr2*160-160)<33)
	{
	*(scr+ctr-ctr2*160-160)=*(scr+ctr-ctr2*160);
	*(scr+ctr-ctr2*160)=' ';
	delay(10);
	}
 else break;
 }

}

return 0;
}
