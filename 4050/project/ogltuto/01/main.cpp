#include "LUtil.h"
#include <glm/glm.hpp>

int main(int argc, char const *argv[]) {
  if( !initGL() ) {
    printf("Failed to init Program!\n" );
    return -1;
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode( window, GLFW_STICKY_KEYS, GL_TRUE );

  // Dark blue background
  glClearColor( 0.f, 0.f, 4.f, 0.f );

  do{
    // Clear the screen.
    glClear( GL_COLOR_BUFFER_BIT );

    // Swap buffers
    glfwSwapBuffers( window );
    glfwPollEvents();
  }// Check if the ESC key was pressed or the window was closed
  while( glfwGetKey( window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
            glfwWindowShouldClose( window ) == 0 );

  // Close OpenGL
  glfwTerminate();

  return 0;
}
