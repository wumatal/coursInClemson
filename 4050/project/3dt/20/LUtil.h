#ifndef LUTIL
#define LUTIL_H

#include "LOpenGL.h"

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

bool initGL( void );

void display( void );

/*****************************************
 * parameter:
 *  -width: width of the window
 *  -height: height of the window
 *****************************************/
void reshape( int width, int height );

/*****************************************
 * render shapes
 *****************************************/
void keyboard( unsigned char key, int x, int y );

void createcube( void );

#endif
