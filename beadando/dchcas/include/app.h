#ifndef APP_H
#define APP_H

#include "camera.h"
#include "scene.h"
#include "plane.h"
#include <SDL2/SDL.h>

#include <stdbool.h>

#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 50.0

typedef struct App
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    double uptime;
    Camera camera;
    Scene scene;
	Plane plane;
} App;

void init_app(App* app, int width, int height);

void init_opengl();

void reshape(GLsizei width, GLsizei height);

void keyboard(App* app);

void update_app(App* app);

void render_app(App* app);

void destroy_app(App* app);

#endif
