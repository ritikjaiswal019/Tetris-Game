#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<DOS.H>
#include<time.h>
#include<string.h>
#include<fstream.h>
int tet[20][14];
int i,j,a,ch=1,score=0,temp,spd=210,hscore;
int cx,cy,dx,dy,ex,ey,fx,fy;
char b;
class Shapes
{ public:
  void b1();
  void b2();
  void b3();
  void b4();
}te;
void op();
void menu();
void setd();
void display();
int end();
int gameover();
void update();
void game();
void pulldown(int);
void moveright();
void moveleft();
void scsave();
int gdriver=DETECT,gmode;
void op()
{
setbkcolor(2);
settextstyle(1,HORIZ_DIR,6);
outtextxy(260,40,"TETRIS");
settextstyle(1,HORIZ_DIR,3);
outtextxy(165,150,"Designed By - RITIK JAISWAL ");
settextstyle(1,HORIZ_DIR,2);
outtextxy(190,400,"Press Any Key to Continue...");
}
void menu()
{
cleardevice();
setbkcolor(2);
settextstyle(1,HORIZ_DIR,5);
outtextxy(220,40,"Main Menu");
settextstyle(1,HORIZ_DIR,2);
outtextxy(180,150,"Enter Your Choice");
settextstyle(1,HORIZ_DIR,2);
outtextxy(190,200,"1.PLAY");
outtextxy(190,250,"2.Set Difficulty Level");
outtextxy(190,300,"3.EXIT");
ch=getch();
if(ch==49||ch==79)
game();
else if(ch==50||ch==80)
setd();
else if(ch==51||ch==81)
exit(0);
else
{outtextxy(190,350,"Wrong Choice, Try Again");delay(500);menu();}
}
void setd()
{
cleardevice();
setbkcolor(2);
settextstyle(1,HORIZ_DIR,4);
outtextxy(220,40,"Set DIFFICULTY LEVEL");
settextstyle(1,HORIZ_DIR,2);
outtextxy(180,150,"Enter Your Choice");
settextstyle(1,HORIZ_DIR,3);
outtextxy(190,200,"1.EASY");
outtextxy(190,250,"2.MEDIUM");
outtextxy(190,300,"3.HARD");
ch=getch();
if(ch==49||ch==79)
{spd=300;menu();}
else if(ch==50||ch==80)
{spd=240;menu();}
else if(ch==51||ch==81)
{spd=180;menu();}
else
{outtextxy(190,350,"Wrong Choice, Try Again");delay(500);setd();}
}

void main()
{
clrscr();
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
op();
getch();
menu();
closegraph();
getch();
}
void game()
{
   setbkcolor(4);
   for(i=0;i<20;i++)
   for(j=0;j<14;j++)
   {
      tet[i][j]=0;
   }
   time_t t;
   srand((unsigned) time(&t));
   while(gameover()!=1)
   {
      a=rand()%4;
      if(a==0)
      te.b1();
      if(a==1)
      te.b2();
      if(a==2)
      te.b3();
      if(a==3)
      te.b4();
   }
   fstream f;
   f.open("HighScoreTETRIS.txt",ios::in);
   f>>hscore;
   if(hscore<score)
   f<<score;
   cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n\ \n \n \n \n"
       <<"\t    You Scored : "<<score
       <<"\n\n     The Previous HIGHSCORE is : "<<hscore
       <<"\n \n \t \t GAME OVER"
       <<"\n\n  Press any key to continue to Main menu"
       <<"\n\n\t    Press ESC to Exit"
       <<endl;
   a=getch();
   if(a==27)
      exit(1);
   score=0;
   menu();
}
void Shapes:: b1()        //t shape//
   {
   cleardevice();
   cx=6;cy=0;
   dx=7;dy=0;
   ex=8;ey=0;
   fx=7;fy=1;
   tet[cy][cx]=1;
   tet[dy][dx]=1;
   tet[ey][ex]=1;
   tet[fy][fx]=1;
   while(end()!=1)
   {
      tet[cy][cx]=0;
      tet[dy][dx]=0;
      tet[ey][ex]=0;
      tet[fy][fx]=0;
      cy++;dy++;ey++;fy++;
      tet[cy][cx]=1;
      tet[dy][dx]=1;
      tet[ey][ex]=1;
      tet[fy][fx]=1;
      display();
      if(kbhit())
      {  b=getch();
	 if(b==75 && cx!=0)
	 {
	    moveleft();
	 }
	 else if(b==77 && ex!=13)
	{
	    moveright();
	}
	else if(b==27)
	    exit(1);
	delay(spd);
      }
      else
	delay(spd);
   }
update();
display();
}
void Shapes:: b2()    //line shape//
{
cleardevice();
cx=6;cy=0;
dx=7;dy=0;
ex=8;ey=0;
fx=9;fy=0;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
while(end()!=1)
{
tet[cy][cx]=0;
tet[dy][dx]=0;
tet[ey][ex]=0;
tet[fy][fx]=0;
cy++;dy++;ey++;fy++;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
if(kbhit())
   {    b=getch();
	if(b==75 && cx!=0)
	{
	moveleft();
	}
       else if(b==77 && fx!=13)
       {
	moveright();
       }
	else if(b==27)
	    exit(1);
	delay(spd);
      }
      else
	delay(spd);
  }
update();
display();
}
void Shapes:: b3()	     //box shape//
{
cleardevice();
cx=6;cy=0;
dx=7;dy=0;
ex=6;ey=1;
fx=7;fy=1;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
while(end()!=1)
{
tet[cy][cx]=0;
tet[dy][dx]=0;
tet[ey][ex]=0;
tet[fy][fx]=0;
cy++;dy++;ey++;fy++;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
if(kbhit())
{ b=getch();
if(b==75 && cx!=0)
{
moveleft();}
else if(b==77 && dx!=13)
{
moveright();
}
else if(b==27)
exit(1);
delay(spd);
}
else
delay(spd);
}
update();
display();
}

void Shapes::b4()     //L shape//
{
cleardevice();
cx=6;cy=0;
dx=6;dy=1;
ex=6;ey=2;
fx=7;fy=2;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
while(end()!=1)
{
tet[cy][cx]=0;
tet[dy][dx]=0;
tet[ey][ex]=0;
tet[fy][fx]=0;
cy++;dy++;ey++;fy++;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
display();
if(kbhit())
{ b=getch();
if(b==75 && cx!=0)
	{
moveleft();}
else if(b==77 && fx!=13)
{
moveright();
}
else if(b==27)
exit(1);
delay(spd);
}
else
delay(spd);
}
update();
display();
}
void display()
{
settextstyle(1,HORIZ_DIR,6);
outtextxy(60,40,"TETRIS");
settextstyle(1,HORIZ_DIR,1);
outtextxy(40,120,"      INSTRUCTIONS:");
outtextxy(40,240,"Press ESC Any time to Exit");
outtextxy(40,160,"Left  Arrow - Move Left");
outtextxy(40,200,"Right Arrow - Move Right");
rectangle(300,40,580,440);
setfillstyle(SOLID_FILL,1);
floodfill(320,320,15);
for(i=0;i<20;i++)
for(j=0;j<14;j++)
{
setcolor(15);
rectangle(300+j*20,40+i*20,320+j*20,60+i*20);
if(tet[i][j]==1)
   {
   setfillstyle(SOLID_FILL,(i+3*j)%7+8);
   floodfill(310+j*20,50+i*20,15);
   }
else if(tet[i][j]==0)
    {
    setfillstyle(SOLID_FILL,1);
    floodfill(310+j*20,50+i*20,15);
    }
}
}
int end()
{
if(cy==19||dy==19||ey==19||fy==19)
return 1;
else if(a==0 &&(tet[cy+1][cx]==1||tet[ey+1][ex]==1||tet[fy+1][fx]==1))
return 1;
else if(a==1 &&(tet[cy+1][cx]==1||tet[dy+1][dx]==1||tet[ey+1][ex]==1||tet[fy+1][fx]==1))
return 1;
else if(a==2 &&(tet[ey+1][ex]==1||tet[fy+1][fx]==1))
return 1;
else if(a==3 &&(tet[ey+1][ex]==1||tet[fy+1][fx]==1))
return 1;
else
return 0;
}
int gameover()
{
for(int i=0;i<14;i++)
{if(tet[0][i]==1)
return 1;
}
return 0;
}
void update()
{
for(int i=0;i<20;i++)
{ temp=0;
for(int j=0;j<14;j++)
{if(tet[i][j]==1)
 temp++;}
if(temp>=14)
{pulldown(i);score+=100;}
}
}
void pulldown(int k)
{
for(int n=k;n>0;n--)
{for(j=0;j<14;j++)
{tet[n][j]=tet[n-1][j];}
}
for(i=0;i<14;i++)
{tet[0][i]=0;}
}
void moveright()
{
tet[cy][cx]=0;
tet[dy][dx]=0;
tet[ey][ex]=0;
tet[fy][fx]=0;
cx++;dx++;ex++;fx++;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
}
void moveleft()
{
tet[cy][cx]=0;
tet[dy][dx]=0;
tet[ey][ex]=0;
tet[fy][fx]=0;
cx--;dx--;ex--;fx--;
tet[cy][cx]=1;
tet[dy][dx]=1;
tet[ey][ex]=1;
tet[fy][fx]=1;
}
