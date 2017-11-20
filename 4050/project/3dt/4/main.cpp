#include "LUtil.h"

int main( int argc, char **argv ) {
  glutInit( &argc, argv );

  glutInitDisplayMode( GLUT_SINGLE );

  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "4" );

  glutDisplayFunc( display );
  glutReshapeFunc( reshape );

  glutMainLoop();
}
