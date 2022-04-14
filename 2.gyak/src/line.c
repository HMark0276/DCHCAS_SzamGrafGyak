#include "line.h"

void init_Line(Line * line, Point start, Point end, Color c) {
    line->start = start;
    line->end = end;
    line->c = c;
}