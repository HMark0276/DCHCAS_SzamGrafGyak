#include <stdio.h>

typedef struct Brick{
    double x;
    double y;
    double z;
}Brick;

void set_size(Brick* brick, double x, double y, double z);
double calc_volume(const Brick* brick);
double calc_surface(const Brick* brick);
void has_square(const Brick* brick);

int main() {
    Brick brick;
    set_size(&brick,3,10,4);
    double volume;
    volume = calc_volume(&brick);
    double surface;
    surface = calc_surface(&brick);
    printf("Volume: %lf\n", volume);
    printf("Surface %lf\n", surface);
    has_square(&brick);
    return 0;
}
void set_size(Brick* brick, double x, double y, double z){
    if (x>0.0){
        brick->x=x;
    }
    if (y>0.0){
        brick->y=y;
    }
    if (z>0.0){
        brick->z=z;
    }
}

double calc_volume(const Brick* brick){
    double volume = brick->x * brick->y * brick->z;
    return volume;
}

double calc_surface(const Brick* brick){
    double surface = 2* (brick->x + brick->y + brick->z);
    return surface;
}

void has_square(const Brick* brick){
    if(brick->x == brick->y || brick->x == brick->z){
        printf("It has a square side.");
    }else if(brick->y == brick->x || brick->y == brick->z){
        printf("It has a square side.");
    }else if(brick->z == brick->x || brick->z == brick->y) {
        printf("It has a square side.");
    }else{
        printf("It does not have a square side.");
    }
}
