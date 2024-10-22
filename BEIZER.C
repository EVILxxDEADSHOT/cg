#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

void findMidPoint(int x1, int y1, int x2, int y2, int *midX, int *midY) {
    *midX = (x1 + x2) / 2;
    *midY = (y1 + y2) / 2;
}

void drawBezier(int x1, int y1, int x2, int y2, int x3, int y3) {
    int x12, y12, x23, y23, x123, y123;

    findMidPoint(x1, y1, x2, y2, &x12, &y12);
    findMidPoint(x2, y2, x3, y3, &x23, &y23);
    findMidPoint(x12, y12, x23, y23, &x123, &y123);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    if (abs(x1 - x123) + abs(y1 - y123) >= 5) {
        drawBezier(x1, y1, x12, y12, x123, y123);
        drawBezier(x123, y123, x23, y23, x3, y3);
    }
}

int main() {
    int gd = DETECT, gm;
	int x1,x2,x3,y1,y2,y3;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

     x1 = 100, y1 = 300;
    x2 = 200, y2 = 100;
    x3 = 300, y3 = 300;

    drawBezier(x1, y1, x2, y2, x3, y3);

    delay(5000);
    closegraph();
    return 0;
}
