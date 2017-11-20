#include "LUtil.h"


void display( void ) {
  // set clear color
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  // set clear buffer
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();
  // render the buffer to SCREEN
  glFlush();
}

void reshape( int width, int height ){
  // set view port
  // note: in glut, (0, 0) is bottom left of window, (width, height) is top right
  glViewport( 0.f, 0.f, (GLsizei)width, (GLsizei)height );
  // Set projection matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  // field of view(fov) : 60 degrees, which gives
  //                      a viewing angle of 30 to the left and 30 to the right
  // aspect ratio of window
  // unit less than 1.0 and greater than 100.0 won't be drawn
  gluPerspective( 60, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );
  // switch back to viewmodel matrix
  glMatrixMode( GL_MODELVIEW );
}
