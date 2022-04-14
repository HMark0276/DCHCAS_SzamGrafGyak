#ifndef BALL_H
#define BALL_H


typedef struct Ball 
{
    float x;
    float y;
    float radius;
    float speed_x;
    float speed_y;
} Ball;


void init_ball(Ball* ball, float x, float y, float speed_x, float speed_y, int radius);

void update_ball(Ball* ball, double time);

void render_ball(Ball* ball);

#endif