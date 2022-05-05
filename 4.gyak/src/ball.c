#include "ball.h"

#include <GL/gl.h>

#include <math.h>

void init_ball(Ball* ball, float x, float y, float speed_x, float speed_y, int radius)
{
    ball->x = x;
    ball->y = y;
    if (radius < 100 && radius > 5)
        ball->radius = radius;
    ball->speed_x = speed_x;
    ball->speed_y = speed_y;
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

void render_ball(Ball* ball)
{
    double angle;
    double x;
    double y;

    glPushMatrix();
    glRotatef(180, ball->x, ball->y, 0);
    glTranslatef(ball->x, ball->y, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0+ball->x+ball->y/1000, 0.0+ball->x/1000, 0.0+ball->y/1000);
    glVertex2f(0, 0);
    angle = 0;
    while (angle < 2.0 * M_PI + 1) {
        x = cos(angle) * ball->radius;
        y = sin(angle) * ball->radius;
        glVertex2f(x, y);
        angle += 0.8;
    }
    glEnd();
    glPopMatrix();
}