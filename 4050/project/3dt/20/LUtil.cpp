#include "LUtil.h"

GLuint cubelist; // We are gonna hold list in here
float angle1;

// Create the cube display list
void createcube( void ) {
  cubelist = glGenLists( 1 ); // Set the cubelist to Generate a list
  glNewList( cubelist, GL_COMPILE ); // Compile the new list
  glRotatef(angle1, 1.0, 1.0, 1.0 );
  glPushMatrix();
  glColor3f( 1.f, 0.f, 0.f );
  glutSolidCube( 2 );
  glPopMatrix();
  glEndList();
}

bool initGL( void ) {
  int i = 0;
  glEnable( GL_DEPTH_TEST );
  i++;
  glEnable( GL_LIGHTING );
  i++;
  glEnable( GL_LIGHT0 );
  i++;
  glShadeModel( GL_SMOOTH ); //Set the shader to smooth shader

  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    printf("%d\n", i);
    return false;
  }
  createcube();
  return true;

}

void display( void ) {
  glClearColor( 0.f, 0.f, 0.f, 1.f );
  //glClearDepth(1);

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef( 0.f, 0.f, -5.f );

  glCallList(cubelist);

  //renderPrimitive();

  glutSwapBuffers();
  angle1 += 0.05f;
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void keyboard (unsigned char key, int x, int y) {
    if (key==27) {
      glutLeaveGameMode(); //set the resolution how it was
      exit(0); //quit the program
    }
}
