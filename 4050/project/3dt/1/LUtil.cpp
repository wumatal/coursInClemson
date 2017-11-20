#include "LUtil.h"

void display ( void ) {
  // Clear the background clr with white
  glClearColor( 1.f, 0.f, 0.f, 1.f );
  // Clear the color buffered
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();
  // Flush the buffers to window
  // With double buffered window, use glSwapBuffer
  glFlush();
}
