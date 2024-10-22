#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>

#define scale 2

#define oX 300 // Shifted Origin X
#define oY 300 // Shifted Origin Y

#define uMin 30 // Minimum separation
#define uMax 40 // Maximum separation

#define half 50 // Half Horizontal

void parseString(char *);
void starburst(int);
int transformY(int);

int main() {

    int gd = DETECT, gm = 0;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    setcolor(WHITE);
    parseString("100001110011110000001100");

    getch();
    closegraph();
    return 0;
}

// Function to transform the y-coordinate (flip y-axis)
int transformY(int originalY) {
    int windowHeight = getmaxy();
    return windowHeight - originalY; 
}

void parseString(char s[]) {
    int i;

    for (i = 0; i < strlen(s); i++) {
	char c = s[i];
	printf("%c", c);
	if (c == '1') {
	 starburst(i + 1);
	}
    }
}

void starburst(int index) {
    if (index == 1) {
	line(oX, transformY(oY - uMin), oX, transformY(oY - (uMax + uMin)));
    } else if (index == 2) {
	line(oX, transformY(oY), oX, transformY(oY - uMin));
    } else if (index == 3) {
	line(oX, transformY(oY), oX + half, transformY(oY));
    } else if (index == 4) {
	line(oX + half, transformY(oY), oX + half + half, transformY(oY));
    } else if (index == 5) {
	line(oX + half + half, transformY(oY), oX + half + half, transformY(oY - uMin));
    } else if (index == 6) {
	line(oX + half + half, transformY(oY - uMin), oX + half + half, transformY(oY - (uMin + uMax)));
    } else if (index == 7) {
	line(oX + half + half, transformY(oY - (uMin + uMax)), oX + half + half, transformY(oY - (uMin + uMax) - uMax));
    } else if (index == 8) {
	line(oX + half + half, transformY(oY - (uMin + uMax) - uMax), oX + half + half, transformY(oY - (uMin + uMax) - uMax - uMin));
    } else if (index == 9) {
	line(oX + half, transformY(oY - (uMin + uMax) - (uMin + uMax)), oX + half + half, transformY(oY - (uMin + uMax) - (uMin + uMax)));
    } else if (index == 10) {
	line(oX, transformY(oY - (uMin + uMax) - (uMin + uMax)), oX + half, transformY(oY - (uMin + uMax) - (uMin + uMax)));
    } else if (index == 11) {
	line(oX, transformY(oY - (uMin + uMax) - (uMin + uMax)), oX, transformY(oY - (uMin + uMax) - uMax));
    } else if (index == 12) {
	line(oX, transformY(oY - (uMin + uMax)), oX, transformY(oY - (uMin + uMax) - uMax));
    } else if (index == 13) {
	line(oX, transformY(oY - uMin), oX + half, transformY(oY));
    } else if (index == 14) {
	line(oX + half, transformY(oY), oX + half + half, transformY(oY - uMin));
    } else if (index == 15) {
	line(oX + half, transformY(oY - (uMin + uMax) - (uMin + uMax)), oX + half + half, transformY(oY - (uMin + uMax) - uMax));
    } else if (index == 16) {
	line(oX, transformY(oY - (uMin + uMax) - uMax), oX + half, transformY(oY - (uMin + uMax) - (uMin + uMax)));
    } else if (index == 17) { 
	// line crossing center of rect
	line(oX, transformY(oY), oX + half, transformY(oY - (uMin + uMax)));
    } else if (index == 18) {
	line(oX + half, transformY(oY - (uMin + uMax)), oX + half + half, transformY(oY));
    } else if (index == 19) {
	line(oX + half, transformY(oY - (uMin + uMax)), oX + half + half, transformY(oY - (uMin + uMax) - (uMin + uMax)));
    } else if (index == 20) {
	line(oX, transformY(oY - (uMin + uMax) - (uMin + uMax)), oX + half, transformY(oY - (uMin + uMax)));
    } else if (index == 21) {
	line(oX, transformY(oY - (uMin + uMax)), oX + half, transformY(oY - (uMin + uMax)));
    } else if (index == 22) {
	line(oX + half, transformY(oY - (uMin + uMax)), oX + half + half, transformY(oY - (uMin + uMax)));
    } else if (index == 23) {
	line(oX + half, transformY(oY), oX + half, transformY(oY - (uMin + uMax)));
    } else if (index == 24) {
	line(oX + half, transformY(oY - (uMin + uMax)), oX + half, transformY(oY - (uMin + uMax) - (uMin + uMax)));
    }
}
