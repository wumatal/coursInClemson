#ifndef _VERTEX_H
#define _VERTEX_H

#include <stdio.h>
#include <assert.h>

#include "../basic/vectors.h"

class Vertex;
class Edge;

// ==========================================================

class Vertex {

public:

  // ========================
  // CONSTRUCTOR & DESTRUCTOR
  // Alert this CONSTRUCTOR a new field 'level'
  Vertex(int i, const Vec3f &pos) : position(pos) { index = i; level = 0; visit=0;}
  Vertex(int i, int l, const Vec3f &pos) : position(pos) { index = i; level = l; visit=0;}
  virtual ~Vertex() { }

  // =========
  // ACCESSORS
  int getIndex() const { return index; }
  // Add getLevel & getEdge accordingly by Wolfgang
  int getLevel() const { return level; }
  Edge* getEdge() const { return edge; }
  int getVisit() const { return visit; }
  double x() const { return position.x(); }
  double y() const { return position.y(); }
  double z() const { return position.z(); }
  const Vec3f& get() const { return position; }

  // =========
  // MODIFIERS
  void set(Vec3f v) { position = v; }
  void set(double x, double y, double z) { position.Set(x,y,z); }
  // Add SetEdge func by Wolfgang
  void setEdge(Edge* e) { edge = e; }
  void setVisit( int v = -1 ) { visit += v; }
  void setType( int t ) { type = t; }

  // Add debug by Wolfgang
  void Print() { std::cout << level << "-" << index << ":" << position << std::endl; }

private:

  // don't use these constructors
  Vertex() { assert(0); }
  Vertex& operator=(const Vertex&) { assert(0); }
  Vertex(const Vertex&) { assert(0); }

  // ==============
  // REPRESENTATION
  Vec3f position;

  // this is the index from the original .obj file.
  // technically not part of the half-edge data structure
  int index;

  // Add new member by Wolfgang
  // record the iteration infomation
  int level;
  // record the half-edge it belong to
  Edge* edge;
  // record whether or not to compute
  int visit;
  // vertex code
  int type;


  // NOTE: the vertices don't know anything about adjacency.  In some
  // versions of this data structure they have a pointer to one of
  // their incoming edges.  However, this data is very complicated to
  // maintain during mesh manipulation.

};

// ==========================================================

#endif
