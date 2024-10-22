#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int sign(int a)
{
if(a==0)
return 0;
else if(a<0)
return -1;
else
return 1;
}
void main()
{
int x1,y1,x2,y2,dx,dy,step,i;
float x,y,xinc,yinc;
int gd=DETECT,gm=0;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
clrscr();
printf("ENTER STARTING COORDINATES:");
scanf("%d%d",&x1,&y1);
printf("ENTER ENDING COORDINATES:");
scanf("%d%d",&x2,&y2);
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
step=abs(dx);
else
step=abs(dy);
xinc=dx/(float)step;
yinc=dy/(float)step;
x=x1+0.5*sign(dx);
y=y1+0.5*sign(dy);
for(i=0;i<=step;i++)
{
putpixel(x,y,10);
x=x+xinc;
y=y+yinc;
}
getch();
closegraph();
}