#include <stdio.h>

#include "argparser.h"
#include "glCanvas.h"

// =========================================
// =========================================

int main(int argc, char *argv[]) {
  srand48(0);
  ArgParser *args = new ArgParser(argc, argv);

  Mesh *mesh = new Mesh();
  mesh->Load(args->input_file);

  GLCanvas glcanvas;
  glutInit(&argc, argv);
  glcanvas.initialize(args,mesh);

  // well it never returns from the GLCanvas loop...
  delete args;
  return 0;

}

// =========================================
// =========================================
