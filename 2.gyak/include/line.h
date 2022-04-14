#ifndef LINE.H 
#define LINE.H 

#include "color.h"
#include "point.h"
typedef struct Line {
    Point start, end;
    Color c;
} Line;

void init_Line(Line * line, Point start, Point end, Color c);

#endif