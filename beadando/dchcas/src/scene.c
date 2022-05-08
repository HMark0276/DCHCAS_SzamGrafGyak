#include "scene.h"
#include "plane.h"
#include <obj/load.h>
#include <obj/draw.h>
#include <obj/model.h>

void init_scene(Scene* scene)
{
	scene->light_strength = 1.0;
	load_model(&(scene->plane.plane), "assets/models/body.obj");
	scene->planetexture = load_texture("assets/textures/body.jpg");
	load_model(&(scene->terrain), "assets/models/terrain.obj");
	scene->terraintexture = load_texture("assets/textures/terrain.jpg");
	load_model(&(scene->plane.rotor), "assets/models/rotor.obj");
	scene->rotortexture = load_texture("assets/textures/rotor.jpg");
	load_model(&(scene->skybox), "assets/models/skybox.obj");
	scene->skytexture = load_texture("assets/textures/skybox.jpg");
	
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;
    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;
    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;
    scene->material.shininess = 1.0;
	
}

void set_lighting(double light_strength)
{
	int i;
    float ambient_light[] = { 1.0f, 0.5f, 0.5f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 1.0f, 100.0f, 100.0f, 1.0f };
	for(i = 0; i < 3; i++){
       ambient_light[i]*=light_strength;
       diffuse_light[i]*=light_strength;
       specular_light[i]*=light_strength;
    }

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)//ok
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
	scene->rotaterotor.y +=100; //rotor speed
}

void render_scene(const Scene* scene)
{
	//sets scene lighting
    set_material(&(scene->material));
    set_lighting(scene->light_strength);
	//sets skybox
	glBindTexture(GL_TEXTURE_2D, scene->skytexture);
	draw_model(&(scene->skybox));
	glPushMatrix();
	//sets rotor
	glRotated(scene->rotaterotor.y,0,1,0);
	glBindTexture(GL_TEXTURE_2D, scene->rotortexture);
    draw_model(&(scene->plane.rotor));
	glPopMatrix();
	//sets plane
	glBindTexture(GL_TEXTURE_2D, scene->planetexture);
	draw_model(&(scene->plane.plane));
	//sets terrain
	glBindTexture(GL_TEXTURE_2D, scene->terraintexture);
	draw_model(&(scene->terrain));
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
