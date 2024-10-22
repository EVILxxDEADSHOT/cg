#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main()
{ int gd=DETECT,gm;
int xc,yc,x,y;
float p,r;
clrscr();
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
printf("enter the center coordinate");
scanf("%d%d",&xc,&yc);
printf("enter radius");
scanf("%f",&r);
x=0;
y=r;
p=(5/4)-r;
do{
putpixel(xc+x,yc+y,YELLOW);
putpixel(xc-x,yc+y,YELLOW);
putpixel(xc+x,yc-y,YELLOW);
putpixel(xc-x,yc-y,YELLOW);
putpixel(xc+y,yc+x,YELLOW);
putpixel(xc-y,yc+x,YELLOW);
putpixel(xc+y,yc-x,YELLOW);
putpixel(xc-y,yc-x,YELLOW);
if(p<0)
{
p=p+((2*x)+3);
}
else{
p=p+((2*(x-y))+5);
y--;
}
x++;
}
while(x<y);
getch();
closegraph();
}
