#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Define M_PI for Turbo C
#define M_PI 3.14159265358979323846

void main() {
    float Pn[3][3];
    int a, x1, x2, x3, y1, y2, y3;
    int gd = DETECT, gm = 0;
    float angle, sine, cosine;
    float R[3][3], P[3][3];
    int i, j, k;

    clrscr();
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input coordinates
    printf("Enter the first coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the second coordinates: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the third coordinates: ");
    scanf("%d %d", &x3, &y3);

    // Input angle of rotation
    printf("Enter the angle of rotation in degrees: ");
    scanf("%d", &a);

    // Draw the original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Convert angle to radians
    angle = a * (M_PI / 180.0);

    // Calculate cosine and sine
    cosine = cos(angle);
    sine = sin(angle);

    // Manually assigning elements to the rotation matrix R
    R[0][0] = cosine;  R[0][1] = sine;    R[0][2] = 0;
    R[1][0] = -sine;   R[1][1] = cosine;  R[1][2] = 0;
    R[2][0] = -x2 * cosine + y2 * sine + x2;
    R[2][1] = -x2 * sine - y2 * cosine + y2;
    R[2][2] = 1;

    // Manually assigning elements to the point matrix P
    P[0][0] = x1; P[0][1] = y1; P[0][2] = 1;
    P[1][0] = x2; P[1][1] = y2; P[1][2] = 1;
    P[2][0] = x3; P[2][1] = y3; P[2][2] = 1;

    // Matrix multiplication for transformation
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Pn[i][j] = 0;
            for (k = 0; k < 3; k++) {
                Pn[i][j] += P[i][k] * R[k][j];
            }
        }
    }

    // Draw the transformed triangle
    line(Pn[0][0], Pn[0][1], Pn[1][0], Pn[1][1]);
    line(Pn[1][0], Pn[1][1], Pn[2][0], Pn[2][1]);
    line(Pn[2][0], Pn[2][1], Pn[0][0], Pn[0][1]);
    
    outtextxy(2, 2 + 2, "ROTATED TRIANGLE");

    getch();
    cleardevice();

    // Draw the original triangle again for comparison
    line(x1, y1, x2, y2);
    outtextxy(x2 + 2, y2 + 2, "ORIGINAL TRIANGLE");
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
}
