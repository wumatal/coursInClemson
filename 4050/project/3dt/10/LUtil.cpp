#include "LUtil.h"

bool movingUp = false; // Whether or not we are moving up or down
float yLocation = 0.0f; // Keep track of our position on the y axis.
float yRotationAngle = 0.0f; // The angle of rotation for our object

void display( void ) {
  // enalbe blend functionality
  glEnable( GL_BLEND );
  // blend rgb of current obj with ratio GL_SRC_ALPHA with the rgb in buffer with
  // latter ratio, which equals 1-GL_SRC_ALPHA
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  // Orde the shapes from farest to nearest.
  glClearColor( 1.f, 1.f, 1.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef( 0.f, 0.f, -5.f );
  glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Set the colour to green and fully opaque
  glutSolidCube(2.0f); // Render the primitive

  glTranslatef(0.0f, yLocation, 0.0f); // Translate our object along the y axis

  glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f); // Rotate our object around the y axis
  glScalef(0.5f, 1.0f, 2.0f);
  renderPrimitive();

  glutSwapBuffers(); // Swap our buffers

  if (movingUp) // If we are moving up
      yLocation -= 0.005f; // Move up along our yLocation
  else // Otherwise
      yLocation += 0.005f; // Move down along our yLocation

  if (yLocation < -3.0f) // If we have gone up too far
    movingUp = false; // Reverse our direction so we are moving down
  else if (yLocation > 3.0f) // Else if we have gone down too far
    movingUp = true; // Reverse our direction so we are moving up

  yRotationAngle += 0.05f; // Increment our rotation value

  if (yRotationAngle > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
      yRotationAngle -= 360.0f; // Subtract 360 degrees off of our rotation

}

void reshape( int width, int height ){
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void renderPrimitive( void ) {
  glColor4f(1.0f, 0.0f, 0.0f, 0.7f); // Set the colour to red and 50% transparent
  glutSolidCube(2.0f); // Render the primitive
}
