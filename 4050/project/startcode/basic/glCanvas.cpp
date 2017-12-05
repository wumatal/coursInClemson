#include "glCanvas.h"


// ========================================================
// static variables of GLCanvas class

// State of the mouse cursor
int GLCanvas::mouseButton;
int GLCanvas::mouseX;
int GLCanvas::mouseY;

int GLCanvas::display_list_index;
ArgParser* GLCanvas::args;
Camera* GLCanvas::camera;
Mesh* GLCanvas::mesh;

// ========================================================

void GLCanvas::InitLight() {
  // Set the last component of the position to 0 to indicate
  // a directional light source

  GLfloat position[4] = { 30,30,100, 1};
  GLfloat diffuse[4] = { 0.75,0.75,0.75,1};
  GLfloat specular[4] = { 0,0,0,1};
  GLfloat ambient[4] = { 0.2, 0.2, 0.2, 1.0 };

  GLfloat zero[4] = {0,0,0,0};
  glLightfv(GL_LIGHT1, GL_POSITION, position);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
  glLightfv(GL_LIGHT1, GL_AMBIENT, zero);
  glEnable(GL_LIGHT1);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glEnable(GL_COLOR_MATERIAL);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

  GLfloat spec_mat[4] = {1,1,1,1};
  float glexponent = 30;
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &glexponent);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec_mat);

  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  float back_color[] = { 0.0,0.0,1.0,1};
  glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_color);
  glEnable(GL_LIGHT1);
}


void GLCanvas::display(void)
{
  // Clear the display buffer, set it to the background color
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Set the camera parameters
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  InitLight(); // light will be a headlamp!
  camera->glPlaceCamera();

  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

  glCallList(display_list_index);
  HandleGLError();

  // Swap the back buffer with the front buffer to display
  // the scene
  glutSwapBuffers();
}

// ========================================================
// Callback function for window resize
// ========================================================

void GLCanvas::reshape(int w, int h) {
  // Set the OpenGL viewport to fill the entire window
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);

  // Set the camera parameters to reflect the changes
  camera->glInit(w, h);

  args->width = w;
  args->height = h;
}

// ========================================================
// Callback function for mouse click or release
// ========================================================

void GLCanvas::mouse(int button, int state, int x, int y) {
  // Save the current state of the mouse.  This will be
  // used by the 'motion' function
  mouseButton = button;
  mouseX = x;
  mouseY = y;
}

// ========================================================
// Callback function for mouse drag
// ========================================================

void GLCanvas::motion(int x, int y) {
  // Left button = rotation
  // (rotate camera around the up and horizontal vectors)
  if (mouseButton == GLUT_LEFT_BUTTON) {
    camera->rotateCamera(0.005*(mouseX-x), 0.005*(mouseY-y));
    mouseX = x;
    mouseY = y;
  }
  // Middle button = translation
  // (move camera perpendicular to the direction vector)
  else if (mouseButton == GLUT_MIDDLE_BUTTON) {
    camera->truckCamera((mouseX-x)*0.01, (y-mouseY)*0.01);
    mouseX = x;
    mouseY = y;
  }
  // Right button = zoom
  // (move camera along the direction vector)
  else if (mouseButton == GLUT_RIGHT_BUTTON) {
    camera->dollyCamera((x-mouseX)*0.05);
    mouseX = x;
    mouseY = y;
  }

  // Redraw the scene with the new camera parameters
  glutPostRedisplay();
}

// ========================================================
// Callback function for keyboard events
// ========================================================

void GLCanvas::keyboard(unsigned char key, int x, int y) {
  // Add a static variable level by Wolfgang
  // to indicate which interation the subdivison is in
  static int level = 0;

  switch (key) {
  case 'w':  case 'W':
    args->wireframe = !args->wireframe;
    Render();
    break;
  // case 'g': case 'G':
  //   args->gouraud = !args->gouraud;
  //   Render();
  //   break;
  case 's': case 'S':
    // Add level to 'LoopSubdivision' by Wolfgang
    // so that we can trace back the last generation of vertices
    mesh->LoopSubdivision(++level);
    Render();
    break;
  /*case 'd': case 'D':
    mesh->Simplification((int)floor(0.9*mesh->numTriangles()));
    Render();
    break;*/
  case 'q':  case 'Q':
    exit(0);
    break;
  default:
    printf("UNKNOWN KEYBOARD INPUT  '%c'\n", key);
  }
}

// ========================================================
// Initialize all appropriate OpenGL variables, set
// callback functions, and start the main event loop.
// This function will not return but can be terminated
// by calling 'exit(0)'
// ========================================================

void GLCanvas::initialize(ArgParser *_args, Mesh *_mesh) {

  args = _args;
  mesh = _mesh;
  camera = new PerspectiveCamera(Vec3f(0,0,5),Vec3f(0,0,-1),Vec3f(0,1,0),20 * M_PI/180.0);

  // Set global lighting parameters
  glEnable(GL_LIGHTING);
  glShadeModel(GL_SMOOTH);

  // Set window parameters
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
  glEnable(GL_DEPTH_TEST);
  glutInitWindowSize(args->width, args->height);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Subdivision for CPSC 6050");

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glEnable(GL_NORMALIZE);

  // Ambient light
  Vec3f ambColor = Vec3f(0.2,0.2,0.2);
  GLfloat ambArr[] = { ambColor.x(), ambColor.y(), ambColor.z(), 1.0 };
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambArr);

  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glCullFace(GL_BACK);
  glDisable(GL_CULL_FACE);

  display_list_index = glGenLists(1);

  // Initialize callback functions
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  Render();

  // Enter the main rendering loop
  glutMainLoop();
}


void GLCanvas::Render() {
  glNewList(display_list_index, GL_COMPILE_AND_EXECUTE);
  // =========================================================
  // put your GL drawing calls inside the display list for efficiency
  mesh->Paint(args);
  // =========================================================
  glEndList();
  glutPostRedisplay();
}

// ========================================================
// ========================================================

int HandleGLError() {
  GLenum error;
  int i = 0;
  while ((error = glGetError()) != GL_NO_ERROR) {
    printf ("GL ERROR(%d):  %s\n", i, gluErrorString(error));
    i++;
  }
  if (i == 0) return 1;
  return 0;
}
