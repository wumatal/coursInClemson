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

  // Initialize the SDL.
  if ( !painter.initSDL(NAME, WIDTH, HEIGHT) ) {
    std::cout << "Failed to initialize SDL2" << std::endl;
    return EXIT_FAILURE;
  }

  // Start painting.
  painter.drawStarryNight();

  // Generate the frame.
  FrameGenerator frameGen(painter.getRenderer(), painter.getWindow(), WIDTH, HEIGHT, NAME);
  frameGen.makeFrame();

  // Get keyboard inputs.
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

  return EXIT_SUCCESS;
}
