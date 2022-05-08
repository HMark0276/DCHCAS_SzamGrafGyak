#ifndef SCENE_H
#define SCENE_H
#include "camera.h"
#include "texture.h"
#include "plane.h"

#include <obj/model.h>

typedef struct Scene
{
    Plane plane;
	Plane rotor;
	Model skybox;
	Model terrain;
    Material material;
    GLuint planetexture;
	GLuint rotortexture;
	GLuint skytexture;
	GLuint terraintexture;
	vec3 rotaterotor;
	double light_strength;
} Scene;

void init_scene(Scene* scene);

void set_lighting(double light_strength);

void set_material(const Material* material);

void update_scene(Scene* scene);

void render_scene(const Scene* scene);

void draw_origin();

#endif 
