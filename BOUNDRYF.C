//seed points : 60 60
//fill color and boundry : 1  4 

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void boundryfill(int x,int y,int fill,int boundry)
{

     int current;
     current=getpixel(x,y);
     if((current!=boundry)&&(current!=fill))
     {

	  setcolor(fill);
	  putpixel(x,y,fill);
	  delay(3);
	  boundryfill(x+1,y,fill,boundry);
	 boundryfill(x-1,y,fill,boundry);
	 boundryfill(x,y+1,fill,boundry);
	 boundryfill(x,y-1,fill,boundry);
    }
}


void main()
{
     int gd=DETECT,gm,a,b,c,d;
     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     printf("enter seed point:");
     scanf("%d %d",&c,&d);
     printf("enter fill color and boundry color:");
     scanf("%d %d",&b,&a);
     setcolor(a);
     rectangle(50,50,100,100);
     boundryfill(c,d,b,a);
     getch();
 }


