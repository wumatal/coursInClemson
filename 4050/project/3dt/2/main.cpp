#include "LUtil.h"

int main( int argc, char **argv ){
  // init glut
  glutInit( &argc, argv );
  // set single buffered window
  glutInitDisplayMode( GLUT_SINGLE );
  // Set window pos and dimen and title
  glutInitWindowPosition( 100, 100 );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "2" );
  // set display function
  glutDisplayFunc( display );
  // Set reshap function
  glutReshapeFunc( reshape );
  // start main loop
  glutMainLoop();
}
