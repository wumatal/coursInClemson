#include "LUtil.h"

int main ( int argc, char **argv ) {
  // init glut
  glutInit( &argc, argv );
  // single buffered window (GLUT_DOUBLE if double buffered window wanted)
  glutInitDisplayMode( GLUT_SINGLE );
  // Set the window position and dimentions
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "01" );
  // Set display funciton
  glutDisplayFunc( display );
  // Start main loop
  glutMainLoop();
}
