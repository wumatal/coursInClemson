#include "LUtil.h"

bool initGL(){
  // Initialize Projection Matrix
  glMatrixMode( GL_PROJECTION );
  // Set Projection Matrix to identity matrix
  glLoadIdentity();

  // Initialize Modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  // Set Modelview matrix to identity matrix
  glLoadIdentity();

  // Initialize clear color ( red, green, blue, alpha )
  glClearColor( 0.f, 0.f, 0.f, 1.f );

  // Check for error
  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    printf("Error Initializing OpenGL! %s\n", gluErrorString( error ));
    return false;
  }

  return true;
}

void update() {

}

void render() {
  // Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );
  // Render quad
  glBegin( GL_QUADS );
    // Vertex order matters;
    glVertex2f( -0.5f, -0.5f );
    glVertex2f( 0.5f, -0.5f );
    glVertex2f( 0.5f, 0.5f );
    glVertex2f( -0.5f, 0.5f );
    // We can draw another quad by 4 Vertex right here
  glEnd();

  // Update Screen
  glutSwapBuffers();
}
