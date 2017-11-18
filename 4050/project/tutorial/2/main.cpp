#include "LUtil.h";

void runMainLoop( int val );

int main( int argc, char* args[] ){
  // Initialize FreeGlut
  glutInit( &argc, args );

  // Create OpenGL 2.1 context
  glutInitContextVersion( 2, 1 );

  // Create Double Buffered window
  glutInitDisplayMode( GLUT_DOUBLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "02" );

  //Do post window/context creation initialization
  if( !initGL() ) {
    printf("Unable to initialize graphics library!\n" );
    return 1;
  }

  // Set keyboard handler
  glutKeyboardFunc( handleKeys );

  // Set rendering function
  glutDisplayFunc( render );

  // Set main loop
  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

  // Start GLUT main loop
  glutMainLoop();

  return 0;
}

void runMainLoop( int val ) {
  update();
  render();

  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
