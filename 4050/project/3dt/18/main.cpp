#include "LUtil.h"

int main ( int argc, char **argv ) {
  glutInit( &argc, argv );

  // GLUT_DEPTH like z buffer
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "18" );

  if( !initGL() ) {
    printf("Unable to set LIGHT ! \n");
    return 1;
  }

  glutDisplayFunc( display );
  glutIdleFunc( display );
  glutReshapeFunc( reshape );

  glutMainLoop();

  return 0;
}
