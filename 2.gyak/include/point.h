#ifndef POINT.H
#define POINT.H

typedef struct Point {
    int x,y;
} Point;

void init_Point(Point * point, int x, int y);

#endif