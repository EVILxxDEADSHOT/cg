#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void printMatrix(double matrix[3][3]) {
    int i, j;
    printf("\nMatrix:\n");
    for (i = 0; i < 3; i++) {
	for (j = 0; j < 3; j++) {
	    printf("%f\t", matrix[i][j]);
	}
	printf("\n");
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void drawTransformedTriangle(int x1, int y1, int x2, int y2, int x3, int y3, char* message) {

    printf("%s\n", message);
    drawTriangle(x1, y1, x2, y2, x3, y3);

}


void main() {
    int gd = DETECT, gm, ch;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 50, x3 = 200, y3 = 100;
    int tx, ty;
    double angle, d1;
    double sx, sy;
    double translationMatrix[3][3] = {0};
    double rotationMatrix[3][3] = {0};
    double scalingMatrix[3][3] = {0};
    int x1_old, y1_old;
    int x2_old, y2_old;
    int x3_old, y3_old;
    int x1_new, y1_new;
    int x2_new, y2_new;
    int x3_new, y3_new;
    int cx, cy; // Center of the triangle

    initgraph(&gd, &gm, "C:\\tc\\BGI");

    while (1) {
	cleardevice();
	printf("\t1. Translation\n\n\t2. Rotation\n\n\t3. Scaling\n\nEnter your choice (0 to exit): ");
	scanf("%d", &ch);

	if (ch == 0) {
	    break;
	}

	switch (ch) {
	    case 1: {
		cleardevice();
		printf("Enter translation values (tx ty): ");
		scanf("%d %d", &tx, &ty);

		translationMatrix[0][0] = 1; translationMatrix[0][1] = 0; translationMatrix[0][2] = 0;
		translationMatrix[1][0] = 0; translationMatrix[1][1] = 1; translationMatrix[1][2] = 0;
		translationMatrix[2][0] = tx; translationMatrix[2][1] = ty; translationMatrix[2][2] = 1;
		printMatrix(translationMatrix);

		drawTransformedTriangle(x1, y1, x2, y2, x3, y3, "Original Triangle:");
		printf("Triangle after translation:\n");
		cleardevice();
		drawTransformedTriangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty, "Translated Triangle: (white)");
		setcolor(4);
		drawTriangle(x1, y1, x2, y2, x3, y3);
		getch();
		break;
	    }
	    case 2: {
		cleardevice();
		drawTransformedTriangle(x1, y1, x2, y2, x3, y3, "Original Triangle:");

		printf("Enter angle of rotation: ");
		scanf("%lf", &angle);

		d1 = (angle * M_PI) / 180.0;

		rotationMatrix[0][0] = cos(d1); rotationMatrix[0][1] = -sin(d1); rotationMatrix[0][2] = 0;
		rotationMatrix[1][0] = sin(d1); rotationMatrix[1][1] = cos(d1); rotationMatrix[1][2] = 0;
		rotationMatrix[2][0] = 0; rotationMatrix[2][1] = 0; rotationMatrix[2][2] = 1;
                printMatrix(rotationMatrix);

                x1_old = x1; y1_old = y1;
                x2_old = x2; y2_old = y2;
                x3_old = x3; y3_old = y3;

                x2_new = (int)((x2_old - x1_old) * cos(d1) - (y2_old - y1_old) * sin(d1)) + x1_old;
                y2_new = (int)((x2_old - x1_old) * sin(d1) + (y2_old - y1_old) * cos(d1)) + y1_old;
                x3_new = (int)((x3_old - x1_old) * cos(d1) - (y3_old - y1_old) * sin(d1)) + x1_old;
                y3_new = (int)((x3_old - x1_old) * sin(d1) + (y3_old - y1_old) * cos(d1)) + y1_old;

                printf("Triangle after rotation:\n");
                drawTransformedTriangle(x1, y1, x2_new, y2_new, x3_new, y3_new, "Rotated Triangle:");
                break;
            }
            case 3: {
                cleardevice();
                drawTransformedTriangle(x1, y1, x2, y2, x3, y3, "Original Triangle:");

                printf("Enter scaling factors (sx sy): ");
                scanf("%lf %lf", &sx, &sy);

                scalingMatrix[0][0] = sx; scalingMatrix[0][1] = 0; scalingMatrix[0][2] = 0;
                scalingMatrix[1][0] = 0; scalingMatrix[1][1] = sy; scalingMatrix[1][2] = 0;
                scalingMatrix[2][0] = 0; scalingMatrix[2][1] = 0; scalingMatrix[2][2] = 1;
                printMatrix(scalingMatrix);

                // Calculate the centroid of the triangle
                cx = (x1 + x2 + x3) / 3;
                cy = (y1 + y2 + y3) / 3;

                x1_old = x1; y1_old = y1;
                x2_old = x2; y2_old = y2;
                x3_old = x3; y3_old = y3;

                // Apply scaling relative to the center (cx, cy)
                x1_new = (int)(cx + (x1_old - cx) * sx);
                y1_new = (int)(cy + (y1_old - cy) * sy);
                x2_new = (int)(cx + (x2_old - cx) * sx);
                y2_new = (int)(cy + (y2_old - cy) * sy);
                x3_new = (int)(cx + (x3_old - cx) * sx);
                y3_new = (int)(cy + (y3_old - cy) * sy);

                printf("Triangle after scaling:\n");
                drawTransformedTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, "Scaled Triangle:");
                break;
            }
            default:
                printf("Invalid choice!\n");
                getch();
                break;
        }
    }

    closegraph();
}
