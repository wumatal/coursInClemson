#include "LUtil.h"

// Camera position
GLfloat gCameraX = 0.f;
GLfloat gCameraY = 0.f;

bool initGL() {
  // Set the Viewport
  glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

  // Set projection matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

  // Set modelview Matrix
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();

  // Save the default modelview matrix
  // push a copy of init modelview matrix scrolled to the camera position onto
  // the stack to save it for when we need to apply transformations to it
  // It's also a bad habit to apply camera transformations to the projection Matrix
  // as it interferes with fog and lighting calculations.
  glPushMatrix();

  // Init clear COLOR
  glClearColor( 0.f, 0.f, 0.f, 1.f);

  // Check for errors
  GLenum error = glGetError();
  if( error != GL_NO_ERROR ){
    printf("Error init OpenGL! %s\n", gluErrorString(error));
    return false;
  }

  return true;
}

void update() {

}

void render() {
  // Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );

  // Pop default matrix onto current Matrix
  glMatrixMode( GL_MODELVIEW );
  glPopMatrix();
  // Save default matrix again
  glPushMatrix();

  // Move to center of the screen
  glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );
  //Red quad
  glBegin( GL_QUADS );
    glColor3f( 1.f, 0.f, 0.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
  glEnd();
  //Move to the right of the screen
  glTranslatef( SCREEN_WIDTH, 0.f, 0.f );
  //Green quad
  glBegin( GL_QUADS );
    glColor3f( 0.f, 1.f, 0.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
  glEnd();
  //Move to the lower right of the screen
  glTranslatef( 0.f, SCREEN_HEIGHT, 0.f );
  //Blue quad
  glBegin( GL_QUADS );
    glColor3f( 0.f, 0.f, 1.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
  glEnd();
  //Move below the screen
  glTranslatef( -SCREEN_WIDTH, 0.f, 0.f );
  //Yellow quad
  glBegin( GL_QUADS );
    glColor3f( 1.f, 1.f, 0.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
    glVertex2f( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
    glVertex2f( -SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f );
  glEnd();
  // Update screen
  glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y ) {
  // use w/a/s/d to change camera position
  if( key == 'w' ){
    gCameraY += 16.f;
  }
  else if( key == 'a' ){
    gCameraX -= 16.f;
  }
  else if( key == 's' ){
    gCameraY -= 16.f;
  }
  else if( key == 'd' ){
    gCameraX += 16.f;
  }

  // Take saved matrix off the stack and reset it
  glMatrixMode( GL_MODELVIEW );
  glPopMatrix();
  glLoadIdentity();

  // Move camera to position
  glTranslatef( -gCameraX, -gCameraY, 0.f );

  // Save default matrix again with camera transformations
  glPushMatrix();
}
