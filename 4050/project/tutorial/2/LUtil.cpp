#include "LUtil.h"

// The current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// The projection scale
GLfloat gProjectionScale = 1.f;

bool initGL() {
  // Initialize Projection Matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

  // Initialize Modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();

  // Initialize clear color
  glClearColor( 0.f, 0.f, 0.f, 1.f );

  // Check for error
  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    printf("Error initializing OpenGL %s\n", gluErrorString(error));
    return false;
  }

  return true;
}
