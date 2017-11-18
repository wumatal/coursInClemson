#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

// Viewport mode
enum ViewPortMode {
  VIEWPORT_MODE_FULL, // rendering whole screen
  VIEWPORT_MODE_HALF_CENTER,
  VIEWPORT_MODE_HALF_TOP,
  VIEWPORT_MODE_QUAD,
  VIEWPORT_MODE_RADAR
};

bool initGL();

void render();

void update();

void handleKeys( unsigned char key, int x, int y );

#endif
