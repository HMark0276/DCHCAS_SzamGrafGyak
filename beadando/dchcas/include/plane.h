#ifndef PLANE_H
#define PLANE_H
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <obj/model.h>

typedef struct Plane
{
    Model plane;
	Model rotor;
	Material material;
	float model_scale;
	vec3 position;
    vec3 speed;
	vec3 rotation;
	vec3 rot_speed; 
} Plane;

/*draws plane.*/
void draw_plane(Plane* plane);

/*setup*/
void init_plane(Plane* plane);

/*moving  plane on z axis*/
void set_plane_side_speed(Plane* plane,double speed);

/*moving  plane on y axis*/
void set_plane_speed(Plane* plane, double speed);

/*moving  plane on x axis*/
void set_plane_vertical_speed(Plane* plane,double speed);

/*update  planes position/rotation*/
void update_plane(Plane* plane,double time);

#endif
