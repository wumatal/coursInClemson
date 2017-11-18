#include "LUtil.h"

void runMainLoop( int val );

int main( int argc, char* args[] ){
  // init freeglut
  glutInit( &argc, args );
  // creation context
  glutInitContextVersion( 2, 1 );

  // set double buffer
  glutInitDisplayMode( GLUT_DOUBLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "04" );

  if( !initGL() ) {
    printf("Unable to init opengl!\n" );
    return 1;
  }

  // set keyboard
  glutKeyboardFunc( handleKeys );
  // set render func
  glutDisplayFunc( render );
  // set mainloop
  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

  // start main loop
  glutMainLoop();

  return 0;
}

void runMainLoop( int val ) {
  update();
  render();

  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
