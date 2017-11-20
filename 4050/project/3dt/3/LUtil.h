#ifndef LUTIL
#define LUTIL_H

#include "LOpenGL.h"

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

void display( void );

/*****************************************
 * parameter:
 *  -width: width of the window
 *  -height: height of the window
 *****************************************/
void reshape( int width, int height );

void keyPressed ( unsigned char key, int x, int y );

/*****************************************
 * Used to set some value when the key is first pressed, and want to keep that
 * value until the key is released
 *****************************************/
void keyUp ( unsigned char key, int x, int y );
/*****************************************
 * used for some special keys like ->
 * because -> etc keys varies from different systems.
 *****************************************/
void keySpecial ( int key, int x, int y );

void keySpecialUp ( int key, int x, int y );

/*****************************************
 * To check for keys have been pressed.
 *****************************************/
void keyOperations ( void );

#endif
