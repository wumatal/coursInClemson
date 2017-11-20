#include "LUtil.h"

// true:movingUp false:movingDown
bool movingUp = false;
// record the position on the y axis
float yLocation = 0.0f;
// the angle of rotation for obj
float yRotationAngle = 0.0f;

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef( 0.0, 0.0, -5.0 );

  // Translate and rotate obj along y
  glTranslatef( 0.f, yLocation, 0.f );
  glRotatef( yRotationAngle, 0.f, 1.f, 0.f );

  renderPrimitive();

  glFlush();

  if( movingUp ) {
    yLocation -= 0.005f;
  }
  else {
    yLocation += 0.005f;
  }

  if( yLocation < -3.f ) {
    movingUp = false;
  }
  else if( yLocation > 3.f ) {
    movingUp =true;
  }

  yRotationAngle += 0.005f;
  if( yRotationAngle > 360.f ) {
    yRotationAngle -= 360.f;
  }
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void renderPrimitive( void ) {
  glutWireCube(2.0f);
}
