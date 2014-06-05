#include <stdio.h>
#include <SDL2/SDL.h>
#include <emscripten.h>

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_CreateWindowAndRenderer(600, 400, 0, &window, &renderer);

  SDL_Surface *screen = SDL_CreateRGBSurface(0, 600, 400, 8, 0, 0, 0, 0);

  //initialize sdl palette
  //with red green and blue
  //colors
  SDL_Color pal[3];
  pal[0].r = 255;
  pal[0].g = 0;
  pal[0].b = 0;
  pal[0].a = 255;

  pal[1].r = 0;
  pal[1].g = 255;
  pal[1].b = 0;
  pal[1].a = 255;

  pal[2].r = 0;
  pal[2].g = 0;
  pal[2].b = 255;
  pal[2].a = 255;

  SDL_SetPaletteColors(screen->format->palette, pal, 0, 3);

  SDL_FillRect(screen, NULL, 0);

  {
    SDL_Rect rect = { 300, 0, 300, 200 };
    SDL_FillRect(screen, &rect, 1);
  }

  {
    SDL_Rect rect = { 0, 200, 600, 200 };
    SDL_FillRect(screen, &rect, 2);
  }

  //changing green color
  //to yellow
  pal[1].r = 255;
  SDL_SetPaletteColors(screen->format->palette, pal, 0, 3);

  {
    SDL_Rect rect = { 300, 200, 300, 200 };
    SDL_FillRect(screen, &rect, 1);
  }

  SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, screen);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
  SDL_RenderPresent(renderer);


  printf("you should see red, blue and yellow rectangles\n");


  SDL_Quit();

  return 0;
}

