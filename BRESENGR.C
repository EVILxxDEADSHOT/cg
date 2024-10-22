#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

void bmgreat0(int x1, int y1, int x2, int y2, int p) {
    int x, y, dx, dy;
    x = x1;
    y = y1;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    p = 2 * dx - dy;

    while (y <= y2) { 
        if (p < 0) {
            y = y + 1;
            p = p + 2 * dx;
            putpixel(x, y, RED);
            delay(100);
        } else {
            x = x + 1;
            y = y + 1;
            p = p + 2 * dx - 2 * dy;
            putpixel(x, y, RED);
            delay(100);
        }
    }
}

int main() {
    int x1, y1, x2, y2, p;
    int dx, dy;
    float m;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx != 0) {
        m = (float)dy / dx; 

        if (m >= 1) {
            bmgreat0(x1, y1, x2, y2, p);
        }
    }

    getch();
    closegraph();
    return 0;
}
