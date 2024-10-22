// 60 60
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood(int x, int y, int fillcolor, int bordercolor);

int main()
{
int a,b;
int gd = DETECT , gm = 0;
detectgraph(&gd, &gm);
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
printf("Enter the seeds:\n");
scanf("%d %d", &a,&b);

setcolor(4);
line(50, 50, 100, 50);
line(50, 50, 50, 100);
line(50, 100, 100, 50);
flood(a, b, 9, 4);

getch();
closegraph();
return 0;
}
void flood(int x, int y, int fillcolor, int bordercolor)
{

int targetColor;
 targetColor = getpixel(x,y);
 if(targetColor!= bordercolor && targetColor!= fillcolor)
 {
 putpixel(x,y, fillcolor);
 delay(20);
 flood(x+1,y,fillcolor,bordercolor);
 flood(x-1,y,fillcolor,bordercolor);
 flood(x,y+1,fillcolor,bordercolor);
 flood(x,y-1,fillcolor,bordercolor);

}
}
