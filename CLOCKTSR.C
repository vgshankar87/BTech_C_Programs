#include<dos.h>
void interrupt(*prevtimer)();
void interrupt ourtimer();
void writechar(char ch, int row, int col, int attr);

char far * scr, *mode;
void main()
{
 if((*mode & 0x30)==0x30) scr=(char far *) 0xB0000000;
 else scr=(char far *) 0xB8000000;
 prevtimer=getvect(8);
 setvect(8,ourtimer);
 keep(0,1000);
}
void interrupt ourtimer()
{
unsigned long far *time=(unsigned long far *)0x46c;
unsigned char hours,minutes,seconds;

hours=*time/65520;
minutes=(*time-hours*65520)/1092;
seconds=(*time-hours*65520-minutes*1092)*10/182;
writechar(hours/10,0,72,112);
writechar(hours%10,0,73,112);
writechar(':',0,74,112);
writechar(minutes/10,0,75,112);
writechar(minutes%10,0,76,112);
writechar(':',0,77,112);
writechar(seconds/10,0,78,112);
writechar(seconds%10,0,79,112);
(*prevtimer)();
}

void writechar(char ch, int row, int col, int attr)
{
*(scr+row*160+col*2)=ch;
*(scr+row*160+col*2+1)=attr;
}

