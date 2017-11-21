#include "LUtil.h"

float rotateAngle = 0.0f;

bool initGL ( void ) {
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );
  // marerial can render color to cube, Otherwise the cube only appears with white and grey
  glEnable(GL_COLOR_MATERIAL);

  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    return false;
  }
  return true;
}

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClearDepth(1);

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();
  gluLookAt( 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );

  renderPrimitive();

  glutSwapBuffers();

  rotateAngle += 0.05f;
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void renderPrimitive( void ) {
  glRotatef( rotateAngle, 1.f, 0.f, 0.f );
  glRotatef( rotateAngle, 0.f, 1.f, 0.f );
  glRotatef( rotateAngle, 0.f, 0.f, 1.f );
  glColor3f( 1.f, 0.f, 0.f );
  glutSolidCube( 2.f );
  glColor3f( 1.f, 1.f, 1.f );
  glutWireCube( 2.f );
}
