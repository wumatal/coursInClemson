#include "LUtil.h"

// set an array to hold the states of keys
bool* keyStates = new bool[256];

void display( void ) {
  keyOperations();
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClear( GL_COLOR_BUFFER_BIT );
  glLoadIdentity();
  glFlush();
}

void reshape( int width, int height ) {
  //set view port
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );
  // set projection matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 60, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );
  // switch to modelview
  glMatrixMode( GL_MODELVIEW );
}

void keyPressed( unsigned char key, int x, int y ) {
  // set the state of the current key to press
  keyStates[key] = true;
}

void keyUp( unsigned char key, int x, int y ) {
  // set the state of the current key to release
  keyStates[key] = false;
}
void keySpecial( int key, int x, int y ) {

}

void keySpecialUp( int key, int x, int y ) {
}

void keyOperations( void ) {

}
