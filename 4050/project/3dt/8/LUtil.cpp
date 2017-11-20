#include "LUtil.h"

bool movingUp = false;
float yLocation = 0.0f;
float yRotationAngle = 0.f;

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef( 0.f, 0.f, -5.f );

  glTranslatef( 0.f, yLocation, 0.f );
  // parameter
  // - rotate angle
  // - x, y, z axis
  glRotatef( yRotationAngle, 1.f, 1.f, 1.f);
  renderPrimitive();

  glutSwapBuffers();

  if (movingUp) // If we are moving up
    yLocation -= 0.005f; // Move up along our yLocation
  else  // Otherwise
    yLocation += 0.005f; // Move down along our yLocation

  if (yLocation < -3.0f) // If we have gone up too far
    movingUp = false; // Reverse our direction so we are moving down
  else if (yLocation > 3.0f) // Else if we have gone down too far
    movingUp = true; // Reverse our direction so we are moving up

  yRotationAngle += 0.005f; // Increment our rotation value

  if (yRotationAngle > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
    yRotationAngle -= 360.0f; // Subtract 360 degrees off of our rotation

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
