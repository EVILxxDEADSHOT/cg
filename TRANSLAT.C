#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main() {
    int Pn[3][3];
    int tx, ty, x1, x2, x3, y1, y2, y3;
    int T[3][3], P[3][3];
    int i, j, k;
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input coordinates
    printf("Enter the first coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the second coordinates: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the third coordinates: ");
    scanf("%d %d", &x3, &y3);
    printf("Enter the value of tx and ty (Translation values): ");
    scanf("%d %d", &tx, &ty);

    // Draw the initial triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Initialize the transformation matrix T (for translation)
    T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
    T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
    T[2][0] = tx; T[2][1] = ty; T[2][2] = 1;

    // Initialize the point matrix P (for the vertices of the triangle)
    P[0][0] = x1; P[0][1] = y1; P[0][2] = 1;
    P[1][0] = x2; P[1][1] = y2; P[1][2] = 1;
    P[2][0] = x3; P[2][1] = y3; P[2][2] = 1;

    // Matrix multiplication for transformation (P' = P * T)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Pn[i][j] = 0;
            for (k = 0; k < 3; k++) {
                Pn[i][j] += P[i][k] * T[k][j];
            }
        }
    }

    // Draw the transformed triangle
    line(Pn[0][0], Pn[0][1], Pn[1][0], Pn[1][1]);
    line(Pn[1][0], Pn[1][1], Pn[2][0], Pn[2][1]);
    line(Pn[2][0], Pn[2][1], Pn[0][0], Pn[0][1]);

    getch();
    closegraph();
}
