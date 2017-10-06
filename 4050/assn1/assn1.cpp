//
//		          Programming Assignment #1 
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
#include <cmath>
#include <iostream>

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header

#define WIDTH			500
#define HEIGHT			500

// These are used to indicate the states of a point.
#define CREATED			1
#define EMPTY			0
#define OVERLAP_1		0
#define OVERLAP_2		1
#define CLICK			1
#define UNCREATED		0
#define UNOVERLAP		-1
#define UNCLICK			0
#define CREATED_INDEX	2
#define OVERLAP_INDEX	3
#define CLICK_INDEX		4
#define MAX_POINTS		4
#define INVALID			-1
#define VALID			1
#define POINT_RADIUS	50
#define STEP			77

int x_last,y_last;
/**
 * Define a array to describe the points, 
 * of which each elem has five fields: x, y, created_flag, overlap_flag, reclick_flag
 * Define a counter to confine the number of points.
 * Define a index of point
 * Define an array to records those overlap,
 * of which each elem has five fields: position of each and number of overlapping points
 * @author Yupeng Wu
 */
int ctrl_points[MAX_POINTS][5] = {
	{0, 0, UNCREATED, UNOVERLAP, UNCLICK}, {0, 0, UNCREATED, UNOVERLAP, UNCLICK}, 
	{0, 0, UNCREATED, UNOVERLAP, UNCLICK}, {0, 0, UNCREATED, UNOVERLAP, UNCLICK}};
int count_points = 0;
int index = INVALID;
int overlap_points[2][5] = {
	{INVALID,INVALID,INVALID,INVALID, EMPTY},
	{INVALID,INVALID,INVALID,INVALID, EMPTY}};


/**
 * To verify if a point is already clicked, 
 * by knowing this, we will place the point to a new position
 * 
 * @return index of the clicked point
 * @author Yupeng Wu
 */
int exist_point_clicked();

/**
 * To verify if click on a existing point.
 * 
 * @param (x, y) of a click
 * @return Index of this existing point
 * @author Yupeng Wu
 */
int click_on_point(int x, int y);

/**
 * To verify if a point is overlapping with others.
 * 
 * @param two points
 * @return True if they are overlapped
 * @author Yupeng Wu
 */
bool is_overlap_point(int index_1, int index_2);

/**
 * To delete a point from its overlap set.
 * 
 * @param the point need to be kicked out from the set
 * @author Yupeng Wu
 */
void delete_point_from_overlapset(int index);

/**
 * To put two overlapping points to an overlap set.
 * 
 * @param the points need to be put in the set
 * @author Yupeng Wu
 */
void put_points_to_overlapset(int index_1, int index_2);

/**
 * To put a point into an overlap set by the elem of the set.
 * 
 * @param the point need to be put in the set
 * @author Yupeng Wu
 */
void put_point1_to_overlapset_by_point2(int index_1, int index_2);

/**
 * To put a point into an empty overlap set.
 * 
 * @param the point need to be put in the set
 * @author Yupeng Wu
 */
void put_point_to_empty_overlapset (int index);

/**
 * To put a point into an empty overlap set.
 * 
 * @param the point need to be put in the set
 * @author Yupeng Wu
 */
void dda_line ();

/**
 * To return a point from a overlap set.
 * 
 * @param the index of chosen set
 * @return the index of the chosen point
 * @author Yupeng Wu
 */
int choose_point_from_overlapset(int overlapset_index);
  
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

void write_pixel(int x, int y, float intensity)
/* Turn on the pixel found at x,y */
{
	glLineWidth(2.5);
	glColor3f (intensity * 0.5f, intensity * 0.0f, intensity * 1.0f);                 
	/**
	 * Display the points that user clicks.
	 * @author Yupeng Wu
	 */
	glPointSize(7);
	glBegin(GL_POINTS);
		glVertex3i(x, y, 0);
	glEnd();	
}

//***************************************************************************/

void display ( void )   // Create The Display Function
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen 
	
	// Create the four points
	for(int i=0; i<4; i++) {
		// If the point doesn't created, create it.
		if( ctrl_points[i][2] ){
			write_pixel(ctrl_points[i][0], ctrl_points[i][1], 1.0);
		}
	}
	
	if( count_points >= MAX_POINTS ) {				
		dda_line();
	}
	glutSwapBuffers();                                      // Draw Frame Buffer 
}

/***************************************************************************/
void mouse(int button, int state, int x, int y)
{
	y *= -1;  //align y with mouse
	y += 500; //ignore 
	
	// When a point is clicked, the curve shuold move with the mouse until another
	// click happened.
	index = exist_point_clicked();
	// Index != INVALID indicates that there is point movement yet.
	/*if ( index != INVALID ) {
		ctrl_points[index][0] = x;
		ctrl_points[index][1] = y;
		// Maintain the old point.
		write_pixel(ctrl_points[index][0], ctrl_points[index][1], 0.5);		
	}*/
	
	// Left button pressed
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// To see if it is a point moving action.
		index = exist_point_clicked();
		// Index = INVALID indicates that there is no point movement yet.
		if ( index == INVALID ) {
			// Create the 4 points.
			if ( count_points < MAX_POINTS ) {
				ctrl_points[count_points][0] = x;
				ctrl_points[count_points][1] = y;
				ctrl_points[count_points][CREATED_INDEX] = CREATED;
				count_points ++;
				// When all points created, check if they are overlapping.
				if(count_points == MAX_POINTS) {
					for ( unsigned int a=0; a < (MAX_POINTS-1); a++ ) {
						for ( unsigned int b= a+1; b<MAX_POINTS; b++ ) {
							if ( is_overlap_point(a, b) ) {
								put_points_to_overlapset(a, b);		
							}
						}
					}
				}
			}
			// 4 points already created, we need click on one point to move it.
			else {
				index = click_on_point(x, y);
				// If no points in this position, just ignore.
				if ( index == INVALID ) {
					std::cout << "Only 4 points are permitted" << std::endl;
					return;
				}
				// If this chosen point is on a existing point then
				else {
					// If this existing point already overlaps, then choose one of them
					if ( ctrl_points[index][OVERLAP_INDEX] != UNOVERLAP ) {
						// choose one func
						index = choose_point_from_overlapset(ctrl_points[index][OVERLAP_INDEX]);
					}
					ctrl_points[index][CLICK_INDEX] = CLICK;
					
					// curve generate by mouse move
				}
			}
		}
		// If a point is chosen, then we must pick a position to place it.
		// Index just indicate which point is being chosen.
		else {
			// This point itself overlaps with others originally, then modify the old set
			if ( ctrl_points[index][OVERLAP_INDEX] != UNOVERLAP ) {
				// Delete it from the old set and modify the old set
				delete_point_from_overlapset(index);
			}

			// Store which points is clicked.
			int index_clicked = click_on_point(x, y);
			// Put new coordinate to the point
			ctrl_points[index][0] = x;
			ctrl_points[index][1] = y;
			ctrl_points[index][CLICK_INDEX] = UNCLICK;

			// Not click on a point, set its overlap field to UNOVERLAP
			if ( index_clicked == INVALID ) {
				if ( ctrl_points[index][OVERLAP_INDEX] != UNOVERLAP )
					ctrl_points[index][OVERLAP_INDEX] = UNOVERLAP;
			}
			// Click on a point, set all these clicked points into overlap_points.
			else {
				// The clicked point is belong to a overlapping set
				if ( ctrl_points[index_clicked][OVERLAP_INDEX] != UNOVERLAP ) {
					// Add the point to this set
					put_point1_to_overlapset_by_point2(index, index_clicked);
				}
				// The clicked point is single
				else {
					// Put all of them to a empty overlapping set
					put_points_to_overlapset(index, index_clicked);
				}
			}
		}
	}
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
		// When Backspace or Delete is pressed.
		// Return the most recent point to its former position;
		// If it is an new created point, delete it directly
		default:       
			break;
	}
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

int exist_point_clicked() {
	for( unsigned int a = 0; a < sizeof(ctrl_points)/sizeof(ctrl_points[0]); a++ )
		if ( ctrl_points[a][CLICK_INDEX] == CLICK ) 
			return a;
	
	return INVALID;
}

int click_on_point(int x, int y) {
	for( unsigned int a = 0, mag; a < sizeof(ctrl_points)/sizeof(ctrl_points[0]); a++ ) {
		mag = (ctrl_points[a][0] - x)*(ctrl_points[a][0] - x) + 
			  (ctrl_points[a][1] - y)*(ctrl_points[a][1] - y);
		if (mag < POINT_RADIUS) {
			return a;
		}
	} 
	return INVALID;
}

bool is_overlap_point(int index_1, int index_2) {
	int mag;
	mag = (ctrl_points[index_1][0] - ctrl_points[index_2][0])*
			(ctrl_points[index_1][0] - ctrl_points[index_2][0]) + 
		  (ctrl_points[index_1][1] - ctrl_points[index_2][1])*
			(ctrl_points[index_1][1] - ctrl_points[index_2][1]);
	if (mag < POINT_RADIUS) {
		return true;
	}
	return false;
}

void delete_point_from_overlapset(int index) {

	int a = ctrl_points[index][OVERLAP_INDEX];
	// Kick it out from the original set
	if ( overlap_points[a][index] == VALID ) {
		overlap_points[a][index] = INVALID;
		// The size decrease after kick the point out
		overlap_points[a][4]--;
		ctrl_points[index][OVERLAP_INDEX] = UNOVERLAP;
		// If original set has only one elem after delete index, 
		// then set the other elem as well
		if ( overlap_points[a][4] == 1 ) {
			for ( unsigned int b=0; b<4; b++ ){
				if ( overlap_points[a][b] == VALID ) {
					overlap_points[a][b] = INVALID;
					ctrl_points[b][OVERLAP_INDEX] = UNOVERLAP;
					overlap_points[a][4] = 0;
					break;
				}
			}
		}
	}
}

void put_points_to_overlapset(int index_1, int index_2) {
	if (index_1 == index_2)  return;
	if ( ctrl_points[index_1][OVERLAP_INDEX] != UNOVERLAP && 
		ctrl_points[index_2][OVERLAP_INDEX] == UNOVERLAP ) {
		put_point1_to_overlapset_by_point2(index_2, index_1);
	}
	else if ( ctrl_points[index_2][OVERLAP_INDEX] != UNOVERLAP && 
		ctrl_points[index_1][OVERLAP_INDEX] == UNOVERLAP ) {
		put_point1_to_overlapset_by_point2(index_1, index_2);
	}
	else if ( ctrl_points[index_1][OVERLAP_INDEX] == UNOVERLAP && 
		ctrl_points[index_2][OVERLAP_INDEX] == UNOVERLAP) {
		put_point_to_empty_overlapset(index_2);
		
		put_point1_to_overlapset_by_point2(index_1, index_2);
	}
	else if ( overlap_points[0][index_1] == overlap_points[1][index_2] ){
		for( unsigned int a=0; a<4; a++ ){
			overlap_points[0][a] = INVALID;
			overlap_points[1][a] = VALID;
			ctrl_points[a][OVERLAP_INDEX] = OVERLAP_2;
		}
		overlap_points[0][4] = 0;
		overlap_points[1][4] = 4;
	}
}

void put_point1_to_overlapset_by_point2(int index_1, int index_2) {
	int a = ctrl_points[index_2][OVERLAP_INDEX];
	// Set it position valid and increase the number of points
	overlap_points[a][index_1] = VALID;
	overlap_points[a][4]++;
	ctrl_points[index_1][OVERLAP_INDEX] = a;
	
}

void put_point_to_empty_overlapset(int index){
	for ( unsigned int a=0; a<2; a++ ) {
		if ( overlap_points[a][4] == 0 ) {
			ctrl_points[index][OVERLAP_INDEX] = a;
			if ( overlap_points[a][index] == INVALID ){
				overlap_points[a][index] = VALID;
				overlap_points[a][4] ++;
			}
			break;
		}
	}
}

void dda_line (){
	float bx, by;
	float t = 0;
	float u = t / float(STEP);
	// p = u^3 * P0 + 3 * u^2 * (1-u) * P1 + 3 * u * (1-u)^2 * P2 + (1-u)^3 * P3 
	x_last = std::pow(u, 3) * ctrl_points[0][0] +
		3 * std::pow(u, 2) * (1-u) * ctrl_points[1][0] +
		3 * u * std::pow((1-u), 2) * ctrl_points[2][0] +
		std::pow((1-u), 3) * ctrl_points[3][0];
	y_last = std::pow(u, 3) * ctrl_points[0][1] +
		3 * std::pow(u, 2) * (1-u) * ctrl_points[1][1] +
		3 * u * std::pow((1-u), 2) * ctrl_points[2][1] +
		std::pow((1-u), 3) * ctrl_points[3][1];
	
	for ( int t = 1; t < STEP; t++ ) {
		// Get the begin points.
		bx = x_last;
		by = y_last;
		
		u = t / float(STEP);

		// Get the end points
		x_last = std::pow(u, 3) * ctrl_points[0][0] +
			3 * std::pow(u, 2) * (1-u) * ctrl_points[1][0] +
			3 * u * std::pow((1-u), 2) * ctrl_points[2][0] +
			std::pow((1-u), 3) * ctrl_points[3][0];
		y_last = std::pow(u, 3) * ctrl_points[0][1] +
			3 * std::pow(u, 2) * (1-u) * ctrl_points[1][1] +
			3 * u * std::pow((1-u), 2) * ctrl_points[2][1] +
			std::pow((1-u), 3) * ctrl_points[3][1];
			
		// Draw a line between (bx, by) and (x_last, y_last)		
	
		
		float dx = std::abs(x_last-bx);
		float dy = std::abs(y_last-by);
		int steps,k;
		float xIncrement,yIncrement;

		if(dx>dy)
			steps = dx;
		else
			steps = dy;

		xIncrement = float(dx) / float(steps);
		yIncrement = float(dy) / float(steps);
		
		glColor3f (0.5f, 0.5f, 1.0f);                 
		glPointSize(2);
		glBegin(GL_LINE_STRIP);
			glVertex2f(bx,by);
		glEnd();
		glFlush();

		for(k=1;k<steps;k++)
		{
			bx+= xIncrement;
			by+= yIncrement;
			glBegin(GL_POINTS);
				glVertex2f(bx,by);
			glEnd();
			glFlush();
		}
	
	}
}

int choose_point_from_overlapset(int overlapset_index) {
	int index;
	// Prompt how many points overlaps, and what are they
	std::cout << "=======================    OOPS!   ======================= " << std::endl; 
	std::cout << overlap_points[overlapset_index][4] << " points overlap here! "
				<< " They are : " << std::endl; 
	for( unsigned int a=0; a<MAX_POINTS; a++ ) {
		if (overlap_points[overlapset_index][a] == VALID ) {
			switch (a) {
				case 0 : 
					std::cout << "start point[0]" << std::endl;
					break;
				case 1 : 
					std::cout << "1st adjust point[1]" << std::endl;
					break;
				case 2 : 
					std::cout << "2st adjust point[2]" << std::endl;
					break;
				default : 
					std::cout << "end point[3]" << std::endl;
					break;
			}
		}
	}
	std::cout << "Which point do you want to adjust? input the number in []" << std::endl;
	std::cin >> index;
	
	if ( index >= 0 && index <=3 )
		if ( overlap_points[overlapset_index][index] == VALID ) {
			std::cout << "Now click the location you want to place this point." << std::endl;
			std::cout << "-----------------------    GOOD!   ----------------------- " << std::endl; 
			return index;
		}
		else {
			std::cout << "There is no point[" << index << "] here. Please reclick them!" 
				<< std::endl;
		}
	else
		std::cout << "Wrong input! You can only input 0~3 here. Please reclick them!" 
			<< std::endl;
	std::cout << "-----------------------    RETRY   ----------------------- " << std::endl; 
	return -1;
}
