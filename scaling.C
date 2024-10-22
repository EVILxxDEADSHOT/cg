#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int Pn[3][2];
    int P[3][3];
    int S[3][3];
    int x1, x2, x3, y1, y2, y3, Sx, Sy;
    int i, j, k;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the first coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the second coordinates (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the third coordinates (x3, y3): ");
    scanf("%d %d", &x3, &y3);
    
    printf("Enter the scaling values for Sx and Sy: ");
    scanf("%d %d", &Sx, &Sy);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    outtextxy(10, y1 + 10, "Original Triangle");

    P[0][0] = x1; P[0][1] = y1; P[0][2] = 1;
    P[1][0] = x2; P[1][1] = y2; P[1][2] = 1;
    P[2][0] = x3; P[2][1] = y3; P[2][2] = 1;

    S[0][0] = Sx; S[0][1] = 0;  S[0][2] = 0;
    S[1][0] = 0;  S[1][1] = Sy; S[1][2] = 0;
    S[2][0] = 0;  S[2][1] = 0;  S[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            Pn[i][j] = 0;
            for (k = 0; k < 3; k++) {
                Pn[i][j] += P[i][k] * S[k][j];
            }
        }
    }

    getch();
    cleardevice();

    line(Pn[0][0], Pn[0][1], Pn[1][0], Pn[1][1]);
    line(Pn[1][0], Pn[1][1], Pn[2][0], Pn[2][1]);
    line(Pn[2][0], Pn[2][1], Pn[0][0], Pn[0][1]);
    
    outtextxy(10, Pn[0][1] + 10, "Scaled Triangle");

    getch();
    closegraph();
}
