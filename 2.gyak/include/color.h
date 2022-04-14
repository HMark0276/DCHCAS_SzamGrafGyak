#ifndef COLOR.H
#define COLOR.H

typedef struct Color {
    int r;
	int g;
	int b;
	int a;
} Color;

void init_Color(Color * c, int r, int g, int b, int a);

#endif