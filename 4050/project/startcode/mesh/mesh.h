#ifndef MESH_H
#define MESH_H

#include <vector>
#include "../basic/vectors.h"
#include "../utils/array.h"
#include "../utils/bag.h"
#include "boundingbox.h"
#include "../basic/argparser.h"

class Vertex;
class Edge;
class Triangle;
class VertexParent;

// Set the mask by Wolfgang
typedef enum {SMOOTH, DART, REG_CREASE, IRR_CREASE, CORNER} code;
// This table is used for sharp edges
static const int mask_table[5][5] =
{
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 2, 3, 3},
    {1, 1, 3, 2, 2},
    {1, 1, 3, 2, 2},
};
// ======================================================================
// ======================================================================

class Mesh {

public:

  // ========================
  // CONSTRUCTOR & DESTRUCTOR
  Mesh();
  Mesh(Mesh* mesh);
  virtual ~Mesh();
  void Load(const char *input_file);

  // ========
  // VERTICES
  int numVertices() const { return vertices->Count(); }
  Vertex* addVertex(int index, int level, const Vec3f &pos);
  // this creates a relationship between 3 vertices (2 parents, 1 child)
  void setParentsChild(Vertex *p1, Vertex *p2, Vertex *child);
  // this accessor will find a child vertex (if it exists) when given
  // two parent vertices
  Vertex* getChildVertex(Vertex *p1, Vertex *p2) const;
  // look up vertex by index
  Vertex* getVertex(int i) const {
    assert (i >= 0 && i < numVertices());
    Vertex *v = (*vertices)[i];
    assert (v != NULL);
    return v;
  }
  // Add getter & setter by Wolfgang
  Array<Vertex*>* getVertices() { return vertices; }
  void setVertices(Array<Vertex*>* vertices);

  // =====
  // EDGES
  int numEdges() const { return edges->Count(); }
  // this efficiently looks for an edge with the given vertices, using a hash table
  Edge* getEdge(Vertex *a, Vertex *b) const;
  // Add new getter & setter func by Wolfgang
  //  to get all edges of the mesh and set new edges for the mesh
  Bag<Edge*>* getEdges() { return edges; }
  void setEdges(Bag<Edge*> *edges);

  // =========
  // TRIANGLES
  int numTriangles() const { return triangles->Count(); }
  void addTriangle(Vertex *a, Vertex *b, Vertex *c);
  void removeTriangle(Triangle *t);
  // Add new getter & setter func by Wolfgang
  //  to get all triangles of the mesh and set new triangles for the mesh
  Bag<Triangle*> * getTriangles() { return triangles; }
  void setTriangles(Bag<Triangle*> *triangles);
  Vertex* setOddPosition( Vertex* a, Vertex* b, Vertex* c, Edge* ab_op, int level );
  void setEvenPosition( Vertex* a, Vertex* b, Vertex* c, Edge* ea, Edge* ec );

  // ===============
  // OTHER ACCESSORS
  BoundingBox* getBoundingBox() const { return bbox; }

  // ===============
  // OTHER FUNCTIONS
  void  Paint(ArgParser *args);
  void  LoopSubdivision(int level);
  //void Simplification(int target_tri_count);

private:

  // ==============
  // REPRESENTATION
  Array<Vertex*>*     vertices;
  Bag<Edge*>*         edges;
  Bag<Triangle*>*     triangles;
  BoundingBox*        bbox;
  Bag<VertexParent*>* vertex_parents;

};

// ======================================================================
// ======================================================================

#endif
