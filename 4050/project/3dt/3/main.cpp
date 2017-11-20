#include "LUtil.h"

int main( int argc, char **argv ) {
  glutInit( &argc, argv );

  glutInitDisplayMode( GLUT_SINGLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "3" );

  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyPressed );
  glutKeyboardUpFunc( keyUp );
  glutSpecialFunc( keySpecial );
  glutSpecialUpFunc( keySpecialUp );

  glutMainLoop();
}
