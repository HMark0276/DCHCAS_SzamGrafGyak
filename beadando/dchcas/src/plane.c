#include "plane.h"
#include "scene.h"
#include <GL/glut.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void draw_plane(Plane* plane){
	
	
	glPushMatrix(); 
		glRotatef(90,1,0,0);
		glScalef(plane->model_scale,plane->model_scale,plane->model_scale);
		glTranslatef(plane->position.x,plane->position.y,plane->position.z);
		draw_model(&(plane->plane));
	glPopMatrix();
	
}

void init_plane(Plane* plane){
	
	
	plane->position.x = 0.0;
	plane->position.y = 0.0;
	plane->position.z = 0.0;
	
	plane->speed.x = 0.0;
	plane->speed.y = 0.0;
	plane->speed.z = 0.0;
	
	plane->rotation.x = 0.0;
	plane->rotation.y = 0.0;
	plane->rotation.z = 0.0;
	
	plane->rot_speed.x = 0.0;
	plane->rot_speed.y = 1.0;
	plane->rot_speed.z = 0.0;
	
	plane->model_scale = 0.050;
	
	plane->material.ambient.red = 1.0;
    plane->material.ambient.green = 1.0;
    plane->material.ambient.blue = 0.0;

    plane->material.diffuse.red = 1.0;
    plane->material.diffuse.green = 1.0;
    plane->material.diffuse.blue = 0.0;

    plane->material.specular.red = 1.0;
    plane->material.specular.green = 1.0;
    plane->material.specular.blue = 0.0;

    plane->material.shininess = 1.0;

	}


void update_plane(Plane* plane,double time){
	
	double angle;
    double side_angle;
	
	plane->rotation.z += plane->rot_speed.z * time;
	
    angle = degree_to_radian(plane->rotation.z);
    side_angle = degree_to_radian(plane->rotation.z + 90.0);

	plane->position.x += cos(angle) * plane->speed.y * time;
    plane->position.y += sin(side_angle) * plane->speed.x * time;
	plane->position.z += sin(angle) * plane->speed.z * time;
	plane->position.z += sin(side_angle) * plane->speed.z * time;
}

void set_plane_vertical_speed(Plane* plane,double speed){
	
	plane->speed.x = speed;
	
}
void set_plane_speed(Plane* plane,double speed){
	
		plane->speed.y = speed;

}
void set_plane_side_speed(Plane* plane,double speed){
	
	plane->speed.z = speed;
}

void set_plane_rotation_speed(Plane* plane,double speed){
	
	plane->rot_speed.z = speed;
}


