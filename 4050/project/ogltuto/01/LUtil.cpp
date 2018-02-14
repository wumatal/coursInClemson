#include "LUtil.h"

GLFWwindow* window;

bool initGL( void ) {
  if( !glfwInit() ){
    fprintf(stderr, "Failed to initialize GLFW .\n" );
    getchar();
    return false;
  }

  // 4x antialiasing
  glfwWindowHint( GLFW_SAMPLES, 4 );
  // Set the context to be 2
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );

  // Open a window and create its OpenGL context
  window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, NULL, NULL );
  if( window == NULL ) {
    fprintf(stderr, "Failed to open GLFW window.\n" );
    getchar();
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent( window );

  // Init glew
  if( glewInit() != GLEW_OK ) {
    fprintf(stderr, "Failed to init GLEW\n" );
    getchar();
    glfwTerminate();
    return false;
  }
  return true;
}
