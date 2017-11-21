#include "LUtil.h"

GLfloat rotateAngle = 0.0f;

GLfloat blankMaterial[] = {0.0, 0.0, 0.0};
GLfloat mShininess[] = {128};

// diffuse light color variables
GLfloat dlr = 1.0;
GLfloat dlg = 1.0;
GLfloat dlb = 1.0;

// ambient light color variables
GLfloat alr = 1.0;
GLfloat alg = 1.0;
GLfloat alb = 1.0;

// light position variables
GLfloat lx = 0.0;
GLfloat ly = 0.0;
GLfloat lz = 1.0;
//  If a point light, set lw to 1.0, if a directional light, use 0.0.
GLfloat lw = 0.0;

GLfloat redDiffuseMaterial[] = { 1.f, 0.f, 0.f };
GLfloat whiteSpecularMaterial[] = { 1.f, 1.f, 1.f };
GLfloat greenEmissiveMaterial[] = { 0.f, 1.f, 0.f };

bool diffuse = false;
bool emissive = false;
bool specular = false;

bool initGL ( void ) {
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );
  glEnable( GL_LIGHT1 );
  glShadeModel (GL_SMOOTH); //set the shader to smooth shader
  // marerial can render color to cube, Otherwise the cube only appears with white and grey
  //glEnable(GL_COLOR_MATERIAL);

  GLenum error = glGetError();
  if( error != GL_NO_ERROR ) {
    return false;
  }
  return true;
}

void display( void ) {
  glClearColor( 1.f, 1.f, 1.f, 1.f );
  glClearDepth(1);

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();
  light();
  //camera position, x,y,z, looking at x,y,z, Up Positions of the camera
  gluLookAt( 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
  //glTranslatef( 0.f, 0.f, -5.f );

  renderPrimitive();

  glutSwapBuffers();

  rotateAngle += 0.005f;
}

void reshape( int width, int height ) {
  glViewport( 0.0, 0.0, (GLsizei)width, (GLsizei)height );

  glMatrixMode( GL_PROJECTION);void keyPress( unsigned char key, int x, int y );
  glLoadIdentity();
  gluPerspective( 100, (GLfloat)width / (GLfloat)height, 1.0, 100.0 );

  glMatrixMode( GL_MODELVIEW );
}

void keyPress( unsigned char key, int x, int y ) {
  switch ( key ) {
    case 'd':
      if( diffuse ) {
        diffuse = false;
        glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, blankMaterial );
      }
      else {
        diffuse = true;
        glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, redDiffuseMaterial );
      }
      break;
    case 'e':
      if( emissive ) {
        emissive = false;
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, blankMaterial );
      }
      else {
        emissive = true;
        glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, greenEmissiveMaterial );
      }
      break;
    case 's':
      if( specular ) {
        specular = false;
        glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, blankMaterial );
        glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, blankMaterial );
      }
      else {
        specular = true;
        glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularMaterial );
        glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, mShininess );
      }
      break;
    default :
      break;
  }
}

void renderPrimitive( void ) {
  glRotatef( rotateAngle, 1.f, 0.f, 0.f );
  glRotatef( rotateAngle, 0.f, 1.f, 0.f );
  glRotatef( rotateAngle, 0.f, 0.f, 1.f );
  glColor3f( 1.f, 0.f, 0.f );
  glutSolidCube( 2.f );
  // glColor3f( 1.f, 1.f, 1.f );
  // glutWireCube( 2.f );
}

void light( void ) {

  GLfloat DiffuseLight[] = { dlr, dlg, dlb };
  GLfloat LightPosition[] = { lx, ly, lz, lw };
  GLfloat AmbientLight[] = { alr, alg, alb };

  glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
  glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
}
