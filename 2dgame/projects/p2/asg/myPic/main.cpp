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

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  if ( !painter.initSDL(renderer, window, NAME, WIDTH, HEIGHT)
      || window == nullptr || renderer == nullptr ) {
    std::cout << "Failed to initialize SDL2" << std::endl;
    return EXIT_FAILURE;
  }

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

  painter.destSDL(renderer, window);
  return EXIT_SUCCESS;
}
