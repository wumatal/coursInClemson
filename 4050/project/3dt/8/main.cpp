#include "LUtil.h"

int main( int argc, char **argv ) {
  glutInit( &argc, argv );

  glutInitDisplayMode( GLUT_DOUBLE );

  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "8" );

  glutDisplayFunc( display );
  // GLUT likes us to place all of variables to be updated into an "idle" method,
  // which handles nothing but calculations, but this isn't as efficient as it is
  // led out to be.
  glutIdleFunc( display );
  glutReshapeFunc( reshape );

  glutMainLoop();

  return 0;
}
