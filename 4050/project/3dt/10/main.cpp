#include "LUtil.h"

int main( int argc, char **argv ) {
  glutInit( &argc, argv );
  // GLUT_RGBA support the fourth color, say, alpha channel
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "9" );

  glutDisplayFunc( display );
  glutIdleFunc( display );
  glutReshapeFunc( reshape );

  glutMainLoop();
  return 0;
}
