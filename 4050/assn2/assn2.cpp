//
//		          Programming Assignment #2
//
//			        Victor Zordan
//
//
//
/***************************************************************************/

/* Include needed files */
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header

#define WIDTH   500
#define HEIGHT  500
#define N       4
int x_last,y_last;

/***************************************************************************/

void init_window()
                 /* Clear the image area, and set up the coordinate system */
{

        					       /* Clear the window */
        glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
        glOrtho(0,WIDTH,0,HEIGHT,-1.0,1.0);
}

/***************************************************************************/

void write_pixel(int x, int y, double intensity)
                                         /* Turn on the pixel found at x,y */
{

        glColor3f (intensity, intensity, intensity);
        glBegin(GL_POINTS);
           glVertex3i( x, y, 0);
        glEnd();
}

//***************************************************************************/

void display ( void )   // Create The Display Function
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen

  write_pixel(x_last,y_last,1.0);//<-you can get rid of this call if you like
  // CALL YOUR CODE HERE

  glutSwapBuffers();                                      // Draw Frame Buffer
}

/***************************************************************************/
void mouse(int button, int state, int x, int y)
{
/* This function I finessed a bit, the value of the printed x,y should
   match the screen, also it remembers where the old value was to avoid multiple
   readings from the same mouse click.  This can cause problems when trying to
   start a line or curve where the last one ended */
        static int oldx = 0;
        static int oldy = 0;
	int mag;

	y *= -1;  //align y with mouse
	y += 500; //ignore
	mag = (oldx - x)*(oldx - x) + (oldy - y)*(oldy - y);
	if (mag > 20) {
		printf(" x,y is (%d,%d)\n", x,y);
	}
	oldx = x;
	oldy = y;
	x_last = x;
	y_last = y;
}

/***************************************************************************/
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			exit ( 0 );   // Exit The Program
			break;
	        case '1':             // stub for new screen
		        printf("New screen\n");
			break;
		default:
			break;
	}
}
/***************************************************************************/

/***************************************************************************/
int * matriceMul (int * transform[N]) // Do M(4*4) * N(4*1)
{

}

/***************************************************************************/

int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */

	glutInit            ( &argc, argv );
       	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize  ( 500,500 );
	glutCreateWindow    ( "Computer Graphics" );
	glutDisplayFunc     ( display );
	glutIdleFunc	    ( display );
	glutMouseFunc       ( mouse );
	glutKeyboardFunc    ( keyboard );

        init_window();				             //create_window

	glutMainLoop        ( );                 // Initialize The Main Loop
}
