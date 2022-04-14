#ifndef GAME_H
#define GAME_H

#include "pong.h"

#include <SDL2/SDL.h>

typedef struct Game
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    double last_update_time;
    int width;
    int height;
    Pong pong;
} Game;

void init_game(Game* game, int width, int height);

void destroy_game(Game* game);

void handle_game_events(Game* game);

void update_game(Game* game);

void render_game(Game* game);

bool init_sdl(Game* game);

void init_opengl(Game* game);

#endif