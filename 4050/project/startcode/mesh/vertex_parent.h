#ifndef VERTEX_PARENT_H
#define VERTEX_PARENT_H

#include <limits.h>
#include <stdio.h>
#include <assert.h>

#include "../basic/utils.h"
#include "vertex.h"

// ===================================================================
// VertexParent

// useful when you need to track the hierarchy of vertices.  this data
// structure can be placed in a Bag, and then accessed with the
// extract function to find the child vertex (if it exists) when given
// two parents.

// ===================================================================

class VertexParent {

public:

  // ========================
  // CONSTRUCTORS & DESTRUCTOR
  VertexParent(Vertex *_p1, Vertex *_p2, Vertex *_v) {
    assert (_p1 != NULL && _p2 != NULL && _v != NULL);
    assert (_p1 != _p2 && _p1 != _v && _p2 != _v);
    if( _p1->getIndex() < _p2->getIndex() ) {
      p1 = _p1;
      p2 = _p2;
    }
    else {
      p1 = _p2;
      p2 = _p1;
    }
    v = _v;
    visited = false;
  }
  ~VertexParent();

  // to be put in a bag...
  static void extract_func(VertexParent *e, int &a, int &b, int &c) {
    a = min2(e->p1->getIndex(),e->p2->getIndex());
    b = max2(e->p1->getIndex(),e->p2->getIndex());
    c = 0;
  }

  // =========
  // ACCESSORS
  Vertex* get() const { return v; }
  // Add debug by Wolfgang
  bool isVisited() { return visited; }
  void visit() { if( !visited ) visited = !visited; }
  void Print() {
    std::cout << "p1:" << p1->get() << "&"
              << "p2:" << p2->get() << "--"
              << "v :" << v->get()
              << std::endl; }


protected:

  VertexParent(const VertexParent&) { assert(0); }
  VertexParent& operator=(const VertexParent&) { assert(0); }

  // ==============
  // REPRESENTATION
  Vertex *p1;
  Vertex *p2;
  Vertex *v;

  // Add by Wolfgang
  // This flag used to indicate whether this vertex is visited
  bool visited;
};

// ===================================================================

#endif
