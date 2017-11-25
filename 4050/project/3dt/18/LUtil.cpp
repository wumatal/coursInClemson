#include "LUtil.h"

GLfloat angle1 = 0.0f;
GLfloat angle2 = 0.0f;

float color[3];

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

  glPushMatrix(); // Set where to start the current obj transforms
  color[0] = 1.f; color[1] = 0.f; color[2] = 0.f;
  cube( 1.f, 2.f, color, angle1 );
  glPopMatrix(); // End the current obj transformations
  
  glPushMatrix(); // Set where to start the current obj transforms
  color[0] = 0.f; color[1] = 1.f; color[2] = 0.f;
  cube( -1.f, 2.f, color, angle2 );
  glPopMatrix(); // End the current obj transformations

  glutSwapBuffers();

  angle1 += 0.05f;
  angle2 += 0.1f;
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void cube( float x, float side, float *color, float rotate ) {
  glTranslatef( x, 0.f, 0.f ); // Move obj1 to the right
  glRotatef( rotate, 1.f, 0.f, 0.f );
  glRotatef( rotate, 0.f, 1.f, 0.f );
  glRotatef( rotate, 0.f, 0.f, 1.f );

  glColor3f( color[0], color[1], color[2] );
  glutWireCube( side );
}
