#include "LUtil.h"

// The current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// The projection scale
GLfloat gProjectionScale = 1.f;

bool initGL() {
  // Initialize Projection Matrix, which controls how the geometry is viewd
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  // multiply current Matrix against an orthographic perspective matrix with
  // the l, r, b, t, n and f in the args.
  // by doing so, set (0,0) to top-left of the window
  glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

  // Initialize Modelview Matrix, which controls how geometry is placed
  // in the rendering  world
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();

  // Initialize clear color
  glClearColor( 0.f, 0.f, 0.f, 1.f );

  // Check for error
  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    printf("Error initializing OpenGL %s\n", gluErrorString(error));
    return false;
  }

  return true;
}

void update() {

}
void render() {
  // Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );

  // Reset modelview matrix
  glMatrixMode( GL_MODELVIEW );
  // Try comment out this line later to see what will happen.
  glLoadIdentity();

  // Move to center of the screen
  glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);

  // Render quad
  if( gColorMode == COLOR_MODE_CYAN ) {
    // Solid COLOR_MODE_CYAN
    glBegin( GL_QUADS );
      glColor3f( 0.f, 1.f, 1.f );
      glVertex2f( -50.f, -50.f );
      glVertex2f( 50.f, -50.f );
      glVertex2f( 50.f, 50.f );
      glVertex2f( -50.f, 50.f );
    glEnd();
  }
  else {
    // RYGB Mix
    glBegin( GL_QUADS );
      // It is important to give the color before give the vertex
      // because OpenGL looks at the most recent color value
      // when rendering that particular vertex
      glColor3f( 1.f, 0.f, 0.f ); glVertex2f( -50.f, -50.f );
      glColor3f( 1.f, 1.f, 0.f ); glVertex2f( 50.f, -50.f );
      glColor3f( 0.f, 1.f, 0.f ); glVertex2f( 50.f, 50.f );
      glColor3f( 0.f, 0.f, 1.f ); glVertex2f( -50.f, 50.f );
    glEnd();
  }

  // Update screen
  glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y ) {
  if ( key == 'q' ) {
    // Toggle color mode
    if( gColorMode == COLOR_MODE_CYAN ){
      gColorMode = COLOR_MODE_MULTI;
    }
    else {
      gColorMode = COLOR_MODE_CYAN;
    }
  }
  else if ( key == 'e' ) {
    if(gProjectionScale == 1.f) {
      gProjectionScale = 2.f;
    }
    else if( gProjectionScale == 2.f ){
      gProjectionScale = 0.5f;
    }
    else if( gProjectionScale == 0.5f ) {
      gProjectionScale = 1.f;
    }

    // Update projection matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH * gProjectionScale, SCREEN_HEIGHT * gProjectionScale, 0.0, 1.0, -1.0 );
  }
}
