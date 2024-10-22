#include<graphics.h>
#include <stdio.h>

int main() {
 float xc, yc;
 float p0, p1;
 int x, y;
 float rx,ry;
 int gd = DETECT, gm = 0;
 detectgraph(&gd, &gm);
 initgraph(&gd, &gm, "C:\\TC\\BGI");

 printf("Enter radius rx and ry: ");
 scanf("%f %f" , &rx,&ry);

 printf("Enter centre coordinates: ");
 scanf("%f %f", &xc, &yc);

 x = 0;
 y = ry;

 p0 = ry*ry - rx*rx*ry + (rx*rx)/4;

 do {
  putpixel(x+xc, y+yc, RED);
  putpixel(x+xc, -y+yc, RED);
  putpixel(-x+xc, y+yc, RED);
  putpixel(-x+xc, -y+yc, RED);


  if (p0 < 0) {
   x = x + 1;
   p0 = p0 + 2*ry*ry*x + ry*ry;
  } else {
   x = x + 1;
   y = y - 1;
   p0 = p0 + 2*ry*ry*x - 2*rx*rx*y + ry*ry;
  }
 } while (2*ry*ry*x <= 2*rx*rx*y);

 p1 = (x+0.5)*(x+0.5)*ry*ry + (y-1)*(y-1)*rx*rx - rx*rx*ry*ry;

 do
 {
  putpixel(x+xc,y+yc,RED);
  putpixel(x+xc,-y+yc, RED);
  putpixel(-x+xc,y+yc, RED);
  putpixel(-x+xc,-y+yc,RED);

  if(p1>0)
  {
   y=y-1;
   p1=p1 - 2*rx*rx*y + rx*rx;
  }
  else
  {
   x=x+1;
   y=y-1;
   p1= p1 + 2*ry*ry*x - 2*rx*rx*y + rx*rx;
  }
 }while(y>=0);



 getch();
 closegraph();
 return 0;
}
