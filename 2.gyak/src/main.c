#include <SDL2/SDL.h>

#include "line.h"
#include "point.h"
#include "color.h"

#include <stdbool.h>
#include <stdio.h>

#define MAX_LINE_COUNT 10

int main(int argc, char* argv[])
{
  int error_code;
  int mouse_x, mouse_y;
  int i = 0;
  int j;
  int border;
  int palette_colors[5][3];
  bool start_is_set = false;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_Renderer* renderer;
  Point start, end;
  Color color;
  Line line[MAX_LINE_COUNT];

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Gyakorlat2",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600, 0);

 
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  
  SDL_Rect palette[5];
  for (int a = 0; a < 5; a++) {
    palette[a].x = 0 + a*50;
    palette[a].y = 0;
    palette[a].w = 50;
    palette[a].h = 50;
    SDL_SetRenderDrawColor(renderer, 20+a*40, 20+a*32, 20+a*40, SDL_ALPHA_OPAQUE);
    palette_colors[a][0] = 20+a*40;
    palette_colors[a][1] = 20+a*32;
    palette_colors[a][2] = 20+a*40;
    SDL_RenderDrawRect(renderer, &palette[a]);
    SDL_RenderFillRect(renderer, &palette[a]);
  }

  init_Color(&color, 0, 255, 0, 255);
  SDL_RenderPresent(renderer);
  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        need_run = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        printf("x = %d y = %d\n", mouse_x, mouse_y);
        if (mouse_x <= palette[4].x && mouse_y <= palette[4].h){
          if (mouse_x > 0 && mouse_x <=50)
            init_Color(&color, palette_colors[0][0], palette_colors[0][1], palette_colors[0][2], SDL_ALPHA_OPAQUE);
          else
          if (mouse_x > 50 && mouse_x <=100)
            init_Color(&color, palette_colors[1][0], palette_colors[1][1], palette_colors[1][2], SDL_ALPHA_OPAQUE);
          else
          if (mouse_x > 100 && mouse_x <=150)
            init_Color(&color, palette_colors[2][0], palette_colors[2][1], palette_colors[2][2], SDL_ALPHA_OPAQUE);
          else
          if (mouse_x > 150 && mouse_x <=200)
            init_Color(&color, palette_colors[3][0], palette_colors[3][1], palette_colors[3][2], SDL_ALPHA_OPAQUE);
          else
          if (mouse_x > 200 && mouse_x <=250)
            init_Color(&color, palette_colors[4][0], palette_colors[4][1], palette_colors[4][2], SDL_ALPHA_OPAQUE);
        }
        else
        {
          if (!start_is_set) {
          init_Point(&start, mouse_x, mouse_y);
          start_is_set = true;
          }
          else {
            init_Point(&end, mouse_x, mouse_y);
            start_is_set = false;
            init_Line(&line[i], start, end, color);
            printf("line %d init!\n", i);
            if (i<MAX_LINE_COUNT-1)
              i++;
            else
              i = 0;
            for (j = 0; j<=border; j++) {
              SDL_SetRenderDrawColor(renderer, line[j].c.r, line[j].c.g, line[j].c.b, line[j].c.a);
              SDL_RenderDrawLine(renderer, line[j].start.x, line[j].start.y, line[j].end.x, line[j].end.y);
            }
            if (border != MAX_LINE_COUNT-1)
              border = i;
            for (int a = 0; a < 5; a++) {
              SDL_SetRenderDrawColor(renderer, 20+a*40, 20+a*32, 20+a*40, SDL_ALPHA_OPAQUE);
              SDL_RenderDrawRect(renderer, &palette[a]);
              SDL_RenderFillRect(renderer, &palette[a]);
            }
            SDL_RenderPresent(renderer);

            SDL_SetRenderDrawColor(renderer, 0,0,0,SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
          }
        }
        break;
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        break;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
