#include "LUtil.h"

int main( int argc, char **argv ) {
  glutInit( &argc, argv );

  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "16" );

  if( !initGL() ) {
    return 1;
  }

  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutIdleFunc( display );
  glutKeyboardFunc( keyPress );

  glutMainLoop();

  return 0;
}
