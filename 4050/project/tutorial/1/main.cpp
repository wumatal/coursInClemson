#include "LUtil.h"

/**************************************************
 * Pre Condition:
 *  -Initialized freeglut
 * Post Condition:
 *  -Calls the main loop funcitons and sets itself
 *   to be called back in 1000/SCREEN_FPS milliseconds
 * Side Effects:
 *  -Sets glutTimerFunc
 **************************************************/
void runMainLoop( int val );

int main( int argc, char* args[] ){
  // Initialize freeglut
  glutInit( &argc, args );
  // Create OpenGL 2.1 context
  // If this lin causes an error, just comment it out.
  glutInitContextVersion( 2.1, 2.1 );

  // Create Double Buffered Window
  glutInitDisplayMode( GLUT_DOUBLE );
  glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
  glutCreateWindow( "OpenGL" );

  // Do post window/context creation initialization
  if( !initGL() ) {
    printf("Unable to initialize graphics libray!\n" );
    return 1;
  }
  // Set rendering function
  glutDisplayFunc( render );
  // Set main loop
  glutTimerFunc( 1000/ SCREEN_FPS, runMainLoop, 0 );
  // Start GLUT main loop
  glutMainLoop();

  return 0;
}

void runMainLoop( int val ) {
  // Frame logic
  update();
  render();

  // Run frame one more time
  glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
