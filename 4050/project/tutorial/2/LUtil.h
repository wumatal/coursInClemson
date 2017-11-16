// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

// Color modes
const int COLOR_MODE_CYAN = 0;
const int COLOR_MODE_MULTI = 1;

/*********************************************************************
 * Pre Conditions:
 *  -A valid OpenGL context
 * Post Conditions:
 *  -Initializes matrices and clear Color
 *  -Reports to console if there was an OpenGL error
 *  -Returns false if there was an error in initializaiton
 * Side Effects:
 *  -Projection matrix is set to an orthographic matrix
 *  -Modelview matrix is set to identity matrix
 *  -Matrix mode is set to modelview
 *  -Clear color is set to black
 *********************************************************************/
bool initGL();

/*********************************************************************
 * Pre Conditions:
 *  -None
 * Post Conditions:
 *  -Does per frame logic
 * Side Effects:
 *  -None
 *********************************************************************/
void update();

 /********************************************************************
  * Pre Conditions:
  *  -A valid OpenGL context
  *  -Active modelview matrix
  * Post Conditions:
  *  -Renders the scene
  * Side Effects:
  *  -Clears the color buffer
  *  -Swaps the front/back buffer
  *  -Sets matrix mode to modelview
  *  -Translates modelview matrix to the center of the default screen
  *  -Changes the current rendering color
  ********************************************************************/
void render();

/*********************************************************************
 * Pre Conditions:
 *  -None
 * Post Conditions:
 *  -Toggles the color mode when the user presses q
 *  -Cycles through different projection scales when the user presses e
 * Side Effects:
 *  -If the user presses e, the matrix mode is set to projection
 **********************************************************************/
void handleKeys( unsigned char key, int x, int y );
