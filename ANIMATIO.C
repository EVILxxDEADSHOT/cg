#include <stdio.h> #include <conio.h> #include <graphics.h> void main()
{
int gd = DETECT, gm, i, x = 0;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
for (i = 0; i <= 600; i++)  {
line(10,10,10,600);
line(615,10,615,600);
circle(x, 310, 10); // Update the circle's x-coordinate
x++;
delay(3);
 
cleardevice();
}
getch(); closegraph();
}	
