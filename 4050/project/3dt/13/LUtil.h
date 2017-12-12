#ifndef LUTIL
#define LUTIL_H

#include "LOpenGL.h"

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

/*****************************************
 *return true if setup DEPTH, LIGHT successfully
 *****************************************/
bool initGL( void );

void display( void );

/*****************************************
 * parameter:
 *  -width: width of the window
 *  -height: height of the window
 *****************************************/
void reshape( int width, int height );

void keyPress( unsigned char key, int x, int y );

/*****************************************
 * render shapes
 *****************************************/
void renderPrimitive( void );

void light( void );

#endif