#include "LUtil.h"

GLunit texture;

bool initGL( void ) {
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );
  glEnable( GL_TEXTURE_2D );

  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    return false;
  }
  return true;
}

void display( void ) {
  texture = LoadTexture( "Walls/wall-7-granite/wall-7-granite-TEX.jpg", 2048, 2048 );

  glClearColor( 0.f, 0.f, 0.f, 1.f );
  glClearDepth( 1.f );

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();

  gluLookAt( 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  renderPrimitive();

  glutSwapBuffers();
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 60, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void renderPrimitive( void ) {
  glRotatef( 45, 1.f, 1.f, 1.f );
  glColor3f( 1.f, 0.f, 0.f );
  glutSolidCube( 2.f );
}

GLunit LoadTexture( const char *filename, int width, int height ) {
  GLunit texture;
  unsigned char *data;
  FILE *file;
  file = fopen( filename, "rb");
  if( file == NULL ) {
    return 0;
  }

  data = (unsigned char *) malloc( width * height * 3);

  fread( data, width * height * 3, 1, file );
  fclose( file );

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

void keyPress( unsigned char key, int x, int y ) {

}
