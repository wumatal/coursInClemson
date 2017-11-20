#include "LUtil.h"

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef( 0.0, 0.0, -5.0 );
  renderPrimitive();

  glFlush();
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void renderPrimitive( void ) {
  glutWireCube( 2.0 );
}
