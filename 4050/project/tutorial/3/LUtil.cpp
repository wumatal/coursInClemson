#include "LUtil.h"

int gViewportMode = VIEWPORT_MODE_FULL;

bool initGL() {
  // Set the Viewport
  // defines what part of the screen we want to render to by defining
  // x, y, width and height of the rendering area.
  glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

  // Initialize Projection matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

  // Initialize Modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();

  // Initialize clear color
  glClearColor( 0.f, 0.f, 0.f, 1.f );

  // Check for error
  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    printf("Error initializing OpenGL! %s\n", gluErrorString( error ));
    return false;
  }

  return true;
}

void render() {
  // Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );

  // Reset modelview matrix
  glLoadIdentity();

  // Move to center of the screen
  glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);

  // Full View
  if( gViewportMode == VIEWPORT_MODE_FULL ) {
    // Fill the screen
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    // Red quad
    glBegin( GL_QUADS );
      glColor3f( 1.f, 0.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glEnd();
  }
  // View port at center of screen
  else if (gViewportMode == VIEWPORT_MODE_HALF_CENTER ) {
    glViewport( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );

    // Green quad
    glBegin( GL_QUADS );
      glColor3f( 0.f, 1.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_WIDTH / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, -SCREEN_WIDTH / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, SCREEN_WIDTH / 2.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, SCREEN_WIDTH / 2.f );
    glEnd();
  }
  // Viewport centered at the top
  else if ( gViewportMode == VIEWPORT_MODE_HALF_TOP ) {
    glViewport( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );

    glBegin( GL_QUADS );
      glColor3f( 0.f, 0.f, 1.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
      glVertex2f( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
      glVertex2f( -SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glEnd();
  }
  // 4 Viewport
  else if ( gViewportMode == VIEWPORT_MODE_QUAD ){
    // bottom left red quad
    glViewport( 0.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glBegin( GL_QUADS );
      glColor3f( 1.f, 0.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glEnd();
    // bottom right green quad
    glViewport( SCREEN_WIDTH / 2.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glBegin( GL_QUADS );
      glColor3f( 0.f, 1.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glEnd();
    // top left blue quad
    glViewport( 0.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glBegin( GL_QUADS );
      glColor3f( 0.f, 0.f, 1.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glEnd();
    // top right yello quad
    glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glBegin( GL_QUADS );
      glColor3f( 1.f, 1.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
      glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
      glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glEnd();
  }
  // radar subview port
  else if ( gViewportMode == VIEWPORT_MODE_RADAR ) {
    //Full size quad
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
    glBegin( GL_QUADS );
      glColor3f( 1.f, 1.f, 1.f );
      glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
      glVertex2f( SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
      glVertex2f( SCREEN_WIDTH / 8.f, SCREEN_HEIGHT / 8.f );
      glVertex2f( -SCREEN_WIDTH / 8.f, SCREEN_HEIGHT / 8.f );

      glColor3f( 0.f, 0.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
      glVertex2f( SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
      glVertex2f( SCREEN_WIDTH / 16.f, SCREEN_HEIGHT / 16.f );
      glVertex2f( -SCREEN_WIDTH / 16.f, SCREEN_HEIGHT / 16.f );
    glEnd();

    // Radar quad
    glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
    glBegin( GL_QUADS );
      glColor3f( 1.f, 1.f, 1.f );
      glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
      glVertex2f( SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
      glVertex2f( SCREEN_WIDTH / 8.f, SCREEN_HEIGHT / 8.f );
      glVertex2f( -SCREEN_WIDTH / 8.f, SCREEN_HEIGHT / 8.f );

      glColor3f( 0.f, 0.f, 0.f );
      glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
      glVertex2f( SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
      glVertex2f( SCREEN_WIDTH / 16.f, SCREEN_HEIGHT / 16.f );
      glVertex2f( -SCREEN_WIDTH / 16.f, SCREEN_HEIGHT / 16.f );
    glEnd();
  }

  // Update screen
  glutSwapBuffers();
}

void update() {

}

void handleKeys( unsigned char key, int x, int y ) {
  if( key == 'q' ) {
    gViewportMode++;
    if( gViewportMode > VIEWPORT_MODE_RADAR ) {
      gViewportMode = VIEWPORT_MODE_FULL;
    }
  }
}
