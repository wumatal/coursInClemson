#include <iostream>
#include <SDL2/SDL.h>
#include "frameGenerator.h"
#include "painter.h"

const std::string NAME = "yupengw";
const int WIDTH  = 600;
const int HEIGHT = 480;

int main(void) {
  // Get the painter
  Painter painter = Painter::getInstance();

  SDL_Window* window;
  SDL_Renderer* renderer;

  if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    std::cout << "Failed to initialize SDL2" << std::endl;
    return EXIT_FAILURE;
  }
  window = SDL_CreateWindow(
      NAME.c_str(), SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      WIDTH, HEIGHT, SDL_WINDOW_SHOWN
  );
  renderer = SDL_CreateRenderer( 
    window, -1, SDL_RENDERER_ACCELERATED
  );

  SDL_SetRenderDrawColor( renderer, skyMain.r, skyMain.g, skyMain.b, 255 );
  SDL_RenderClear(renderer);
  // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  // Start painting.
  painter.drawStarryNight(renderer);

  SDL_RenderPresent(renderer);
  FrameGenerator frameGen(renderer, window, WIDTH, HEIGHT, NAME);
  frameGen.makeFrame();

  SDL_Event event;
  const Uint8* keystate;
  while ( true ) {
    keystate = SDL_GetKeyboardState(0);
    if (keystate[SDL_SCANCODE_ESCAPE]) { break; }
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
    }
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
