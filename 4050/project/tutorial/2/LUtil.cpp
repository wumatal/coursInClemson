#include "LUtil.h"

// The current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// The projection scale
GLfloat gProjectionScale = 1.f;

bool initGL() {
  // Initialize Projection Matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  // multiply current Matrix against an orthographic perspective matrix with
  // the l, r, b, t, n and f in the args.
  // by doing so, set (0,0) to top-left of the window
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

void update() {

}
void render() {
  // Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );

  // Reset modelview matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();

  // Move to center of the screen
  glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);
}
