#include "LUtil.h"

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();
  // push eveything 5 units back to the screen, otherwise we won't see the primitive
  glTranslatef( 0.f, 0.f, -5.f );
  renderPrimitive();
  glFlush();
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 60, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void keyPressed ( unsigned char key, int x, int y ){

}

/*****************************************
 * Used to set some value when the key is first pressed, and want to keep that
 * value until the key is released
 *****************************************/
void keyUp ( unsigned char key, int x, int y ){

}

/*****************************************
 * used for some special keys like ->
 * because -> etc keys varies from different systems.
 *****************************************/
void keySpecial ( int key, int x, int y ){

}

void keySpecialUp ( int key, int x, int y ){

}

/*****************************************
 * To check for keys have been pressed.
 *****************************************/
void keyOperations ( void ) {

}

/*****************************************
 * render shapes
 *****************************************/
void renderPrimitive( void ) {
  // Start drawing a quad primitive
  glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
    glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
    glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
    glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner
  glEnd();
}
