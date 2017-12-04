#include <stdio.h>
#include <assert.h>
#include <GL/gl.h>

#include "mesh.h"
#include "edge.h"
#include "vertex.h"
#include "triangle.h"
#include "vertex_parent.h"
#include "../basic/glCanvas.h"

#define INITIAL_VERTEX 10000
#define INITIAL_EDGE 10000
#define INITIAL_TRIANGLE 10000



// =======================================================================
// CONSTRUCTORS & DESTRUCTORS
// =======================================================================

Mesh::Mesh() {
  vertices = new Array<Vertex*>(INITIAL_VERTEX);
  edges = new Bag<Edge*>(INITIAL_EDGE,Edge::extract_func);
  triangles = new Bag<Triangle*>(INITIAL_TRIANGLE,Triangle::extract_func);
  vertex_parents = new Bag<VertexParent*>(INITIAL_VERTEX, VertexParent::extract_func);
  bbox = NULL;
}

Mesh::Mesh(Mesh* mesh) {
  vertices = new Array<Vertex*>(INITIAL_VERTEX);
  Mesh::setVertices( mesh->getVertices() );
  edges = new Bag<Edge*>(INITIAL_EDGE,Edge::extract_func);
  triangles = new Bag<Triangle*>(INITIAL_TRIANGLE,Triangle::extract_func);
  vertex_parents = new Bag<VertexParent*>(INITIAL_VERTEX, VertexParent::extract_func);
  bbox = NULL;
}

Mesh::~Mesh() {
  delete vertices;
  vertices = NULL;
  delete edges;
  edges = NULL;
  delete triangles;
  triangles = NULL;
  delete bbox;
  bbox = NULL;
}

// =======================================================================
// MODIFIERS:   ADD & REMOVE
// =======================================================================
// Add new parameter by Wolfgang
// new 'level' field to indicate which iteration the vertices belong to
Vertex* Mesh::addVertex(int index, int level, const Vec3f &position) {
  if( index == -1 )
    index = numVertices();
  Vertex *v = new Vertex(index, level, position);
  vertices->Add(v, index);
  // vertices->Add(v);
  if (bbox == NULL)
    bbox = new BoundingBox(position,position);
  else
    bbox->Extend(position);
  return v;
}

void Mesh::setVertices(Array<Vertex*>* vs){
  // Just copy the position
  for( int i = 0; i < vs->Count(); i ++ ) {
    (*vertices)[i]->set((*vs)[i]->get());
  }

}

void Mesh::addTriangle(Vertex *a, Vertex *b, Vertex *c) {
  // create the triangle
  Triangle *t = new Triangle();

  // create the edges
  Edge *ea = new Edge(a,t);
  Edge *eb = new Edge(b,t);
  Edge *ec = new Edge(c,t);

  // Add new info for vertices by Wolfgang
  if( a->getEdge() == NULL ){
    a->setEdge(ea);
  }
  if( b->getEdge() == NULL ){
    b->setEdge(eb);
  }
  if( c->getEdge() == NULL ){
    c->setEdge(ec);
  }

  // point the triangle to one of its edges
  t->setEdge(ea);

  // connect the edges to each other
  ea->setNext(ec);
  eb->setNext(ea);
  ec->setNext(eb);

  // add them to the master list
  edges->Add(ea);
  edges->Add(eb);
  edges->Add(ec);

  Edge *ea_op = getEdge((*ea)[1],(*ea)[0]);
  Edge *eb_op = getEdge((*eb)[1],(*eb)[0]);
  Edge *ec_op = getEdge((*ec)[1],(*ec)[0]);

  if (ea_op != NULL) {
    ea_op->setOpposite(ea);
    // printf("(%d, %d, %d) : (%d, %d) opp %d\n",
    // (*ea)[1]->getIndex(), ea->getNext()->getVertex()->getIndex(), ea->getVertex()->getIndex(),
    // (*ea)[1]->getIndex(), (*ea)[0]->getIndex(), ea_op->getVertex()->getIndex());
  }
  if (eb_op != NULL) {
    eb_op->setOpposite(eb);
    // printf("(%d, %d, %d) : (%d, %d) opp %d\n",
    // (*eb)[1]->getIndex(), eb ->getNext()->getVertex()->getIndex(), eb->getVertex()->getIndex(),
    // (*eb)[1]->getIndex(), (*eb)[0]->getIndex(), eb_op->getVertex()->getIndex());
  }
  if (ec_op != NULL) {
    ec_op->setOpposite(ec);
    // printf("(%d, %d, %d) : (%d, %d) opp %d\n",
    // (*ec)[1]->getIndex(), ec->getNext()->getVertex()->getIndex(), ec->getVertex()->getIndex(),
    // (*ec)[1]->getIndex(), (*ec)[0]->getIndex(), ec_op->getVertex()->getIndex());
  }

  // add the triangle to the master list
  triangles->Add(t);
}

void Mesh::removeTriangle(Triangle *t) {

  Edge *ea = t->getEdge();
  Edge *eb = ea->getNext();
  Edge *ec = eb->getNext();
  assert (ec->getNext() == ea);

  // remove elements from master lists
  edges->Remove(ea);
  edges->Remove(eb);
  edges->Remove(ec);
  triangles->Remove(t);

  // clean up memory
  delete ea;
  delete eb;
  delete ec;
  delete t;
}

void Mesh::setTriangles(Bag<Triangle*> *ts) {
  // First, clear the old edges
  // Bag<Triangle*> *this_triangles = getTriangles();
  triangles->DeleteAllElements();
  triangles->Clear();
  // Iterator<Triangle*> *iter1 = triangles->StartIteration();
  // while (Triangle *t = iter1->GetNext()) {
  //   removeTriangle(t)
  // }
  // triangles->EndIteration(iter1);
  // Then add new edges in
  Iterator<Triangle*> *iter = ts->StartIteration();
  while (Triangle *t = iter->GetNext()) {
    //this_triangles->Add(t);
  triangles->Add(t);
  }
  ts->EndIteration(iter);
}

Edge* Mesh::getEdge(Vertex *a, Vertex *b) const {
  assert (edges != NULL);
  // std::cout << "        (" << a->getIndex() <<", "<<b->getIndex()<<");" << std::endl;
  return edges->Get(a->getIndex(),b->getIndex());
}

void Mesh::setEdges(Bag<Edge*> *edges) {
  // First, clear the old edges
  // Bag<Edge*> *this_edges = getEdges();
  // this_edges->DeleteAllElements();
  // this_edges->Clear();
  this->edges->DeleteAllElements();
  this->edges->Clear();
  // Then add new edges in
  Iterator<Edge*> *iter = edges->StartIteration();
  while (Edge *e = iter->GetNext()) {
    this->edges->Add(e);
  }
  edges->EndIteration(iter);
}

Vertex* Mesh::getChildVertex(Vertex *p1, Vertex *p2) const {
  // std::cout << "Parent(" << p1->getIndex() << "," << p2->getIndex()<< ")" << std::endl;
  VertexParent *vp = vertex_parents->GetReorder(p1->getIndex(), p2->getIndex());
  if (vp == NULL) return NULL;
  return vp->get();
}

// Alter this func by Wolfgang
void Mesh::setParentsChild(Vertex *p1, Vertex *p2, Vertex *child) {
  vertex_parents->Add(new VertexParent(p1,p2,child));
}

// =======================================================================
// the load function parses very simple .obj files
// the basic format has been extended to allow the specification
// of crease weights on the edges.
// =======================================================================

void Mesh::Load(const char *input_file) {
  // Read .obj file
  FILE *objfile = fopen(input_file,"r");
  if (objfile == NULL) {
    printf ("ERROR! CANNOT OPEN '%s'\n",input_file);
    return;
  }

  char line[200];
  char token[100];
  char atoken[100];
  char btoken[100];
  char ctoken[100];
  char dtoken[100];
  char etoken[100];
  float x,y,z;
  int a,b,c,d,e;

  int index = 0;
  int vert_count = 0;
  int vert_index = 1;

  // Read obj file, 200 chars each iteration.
  while (fgets(line, 200, objfile)) {

    if (line[strlen(line)-2] == '\\') {
      fgets(token, 100, objfile);
      int tmp = strlen(line)-2;
      strncpy(&line[tmp],token,100);
    }
    int token_count = sscanf (line, "%s\n",token);
    if (token_count == -1) continue;
    a = b = c = d = e = -1;
    if (!strcmp(token,"usemtl") || !strcmp(token,"g")) {
      vert_index = 1; //vert_count + 1;
      index++;
    } else if (!strcmp(token,"v")) {
      vert_count++;
      sscanf (line, "%s %f %f %f\n",token,&x,&y,&z);
      // 0 stands for the first generation of vertices
      addVertex( -1, 0, Vec3f(x,y,z) );
    } else if (!strcmp(token,"f")) {
      int num = sscanf (line, "%s %s %s %s %s %s\n",token,
			atoken,btoken,ctoken,dtoken,etoken);
      sscanf (atoken,"%d",&a);
      sscanf (btoken,"%d",&b);
      sscanf (ctoken,"%d",&c);
      if (num > 4) sscanf (dtoken,"%d",&d);
      if (num > 5) sscanf (etoken,"%d",&e);
      a -= vert_index;
      b -= vert_index;
      c -= vert_index;
      if (d >= 0) d -= vert_index;
      if (e >= 0) e -= vert_index;
      assert (a >= 0 && a < numVertices());
      assert (b >= 0 && b < numVertices());
      assert (c >= 0 && c < numVertices());

      addTriangle(getVertex(a),getVertex(b),getVertex(c));
      if (d > -1) { assert (d < numVertices()); addTriangle(getVertex(a),getVertex(c),getVertex(d)); }
      if (e > -1) { assert (e < numVertices()); addTriangle(getVertex(a),getVertex(d),getVertex(e)); }
    } else if (!strcmp(token,"e")) {
      // Set crease
      int num = sscanf (line, "%s %s %s %s\n",token,atoken,btoken,ctoken);
      assert (num == 4);
      sscanf (atoken,"%d",&a);
      sscanf (btoken,"%d",&b);
      if (!strcmp(ctoken,"inf")) x = 1000000; // this is close to infinity...
      else sscanf (ctoken,"%f",&x);
      Vertex *va = getVertex(a);
      Vertex *vb = getVertex(b);
      Edge *ab = getEdge(va,vb);
      Edge *ba = getEdge(vb,va);
      assert (ab != NULL);
      assert (ba != NULL);
      ab->setCrease(x);
      ba->setCrease(x);
    } else if (!strcmp(token,"vt")) {
    } else if (!strcmp(token,"vn")) {
    } else if (token[0] == '#') {  // Iterate all edges
  // Insert vertex in half-edge
    } else {
      printf ("LINE: '%s'",line);
    }
  }
}

// =======================================================================
// PAINT
// =======================================================================

Vec3f ComputeNormal(const Vec3f &p1, const Vec3f &p2, const Vec3f &p3) {
  Vec3f v12 = p2;
  v12 -= p1;
  Vec3f v23 = p3;
  v23 -= p2;
  Vec3f normal;
  Vec3f::Cross3(normal,v12,v23);
  normal.Normalize();
  return normal;
}

void InsertNormal(const Vec3f &p1, const Vec3f &p2, const Vec3f &p3) {
  Vec3f normal = ComputeNormal(p1,p2,p3);
  glNormal3f(normal.x(), normal.y(), normal.z());
}

void Mesh::Paint(ArgParser *args) {

  // scale it so it fits in the window
  Vec3f center; bbox->getCenter(center);
  float s = 1/bbox->maxDim();
  glScalef(s,s,s);
  glTranslatef(-center.x(),-center.y(),-center.z());

  // this offset prevents "z-fighting" bewteen the edges and faces
  // the edges will always win.
  glEnable(GL_POLYGON_OFFSET_FILL);
  glPolygonOffset(1.1,4.0);

  // draw the triangles
  glColor3f(1,1,1);
  Iterator<Triangle*> *iter = triangles->StartIteration();
  glBegin (GL_TRIANGLES);
  while (Triangle *t = iter->GetNext()) {
    Vec3f a = (*t)[0]->get();
    Vec3f b = (*t)[1]->get();
    Vec3f c = (*t)[2]->get();
    InsertNormal(a,b,c);
    glVertex3f(a.x(),a.y(),a.z());
    glVertex3f(b.x(),b.y(),b.z());
    glVertex3f(c.x(),c.y(),c.z());
  }
  triangles->EndIteration(iter);
  glEnd();

  glDisable(GL_POLYGON_OFFSET_FILL);

  if (args->wireframe) {
    glDisable(GL_LIGHTING);

    // draw all the interior, non-crease edges
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin (GL_LINES);
    Iterator<Edge*> *iter = edges->StartIteration();
    while (Edge *e = iter->GetNext()) {
      if (e->getOpposite() == NULL || e->getCrease() > 0) continue;
      Vec3f a = (*e)[0]->get();
      Vec3f b = (*e)[1]->get();
      glVertex3f(a.x(),a.y(),a.z());
      glVertex3f(b.x(),b.y(),b.z());
    }
    edges->EndIteration(iter);
    glEnd();

    // draw all the interior, crease edges
    glLineWidth(3);
    glColor3f(1,1,0);
    glBegin (GL_LINES);
    iter = edges->StartIteration();
    while (Edge *e = iter->GetNext()) {
      if (e->getOpposite() == NULL || e->getCrease() == 0) continue;
      Vec3f a = (*e)[0]->get();
      Vec3f b = (*e)[1]->get();
      glVertex3f(a.x(),a.y(),a.z());
      glVertex3f(b.x(),b.y(),b.z());
    }
    edges->EndIteration(iter);
    glEnd();

    // draw all the boundary edges
    glLineWidth(3);
    glColor3f(1,0,0);
    glBegin (GL_LINES);
    iter = edges->StartIteration();
    while (Edge *e = iter->GetNext()) {
      if (e->getOpposite() != NULL) continue;
      assert (e->getCrease() == 0);
      Vec3f a = (*e)[0]->get();
      Vec3f b = (*e)[1]->get();
      glVertex3f(a.x(),a.y(),a.z());
      glVertex3f(b.x(),b.y(),b.z());
    }
    edges->EndIteration(iter);
    glEnd();

    glEnable(GL_LIGHTING);
  }
  printf("edges: %d, triangles: %d, vertices: %d\n", edges->Count(), triangles->Count(), vertices->Count());
  HandleGLError();
}

// =================================================================
// SUBDIVISION by Wolfgang
// 2 pass to do subdivison
// Pass 1 : Add new vertices, triangles and edges
//
// Pass 2 : Change the position of all vertices
//  Odd :
//    -interior 3/8 * vertex_parents + 1/8 * opposite->next->vertex + 1/8 * next->vertex
//    -border   1/2 * vertex_parents
//  Even:
//    -interior
//    -border   6/8 * this + 1/8
// =================================================================

void Mesh::LoopSubdivision(int level) {
  printf ("The %dth Subdivide the mesh!\n", level);
  Mesh* mesh = new Mesh();

  // Add mid point to each edge
  Iterator<Edge*> *eiter = edges->StartIteration();
  while (Edge *e = eiter->GetNext()) {
    Vertex* p1 = (*e)[0]; // the compute vertex
    Vertex* p2 = (*e)[1]; // the 1st neighbor
    // Create new vertex
    Vertex* v = getChildVertex(p1, p2);
    if( v == NULL ){
      v = addVertex(-1, level, 0.5*(p1->get() + p2->get()));
    }
    setParentsChild(p1, p2, v);
  }
  edges->EndIteration(eiter);
  // triangles->Print();
  // Iterate all triangles to create new triangles and edges
  Iterator<Triangle*> *titer = triangles->StartIteration();
  while (Triangle *t = titer->GetNext()) {
    // All interior vertices we need to get are like :
    //      ao------a------co
    //       \     / \    /
    //        \  vab vca /
    //         \ /    \ /
    //          b-vbc--c
    //          \     /
    //           \   /
    //            bo
    // Get even vertices of the triangle.
    Vertex* va = (*t)[0];
    Vertex* vb = (*t)[1];
    Vertex* vc = (*t)[2];
    // Get odd vertices
    Vertex* ab = getChildVertex(va, vb);
    Vertex* bc = getChildVertex(vb, vc);
    Vertex* ca = getChildVertex(vc, va);

    Vec3f a = va->get();
    Vec3f b = vb->get();
    Vec3f c = vc->get();
    // Get 3 opppsite even vertices
    Edge* ea = t->getEdge();
    Edge* ec = ea->getNext();
    Edge* eb = ec->getNext();

    Edge* ea_op = ea->getOpposite();
    Edge* eb_op = eb->getOpposite();
    Edge* ec_op = ec->getOpposite();

    Vec3f vab;
    Vec3f vbc;
    Vec3f vca;

    if( ab == NULL || bc == NULL || ca == NULL ){
      continue;
    }

    // Recompute positions of all vertices
    // ================== EVEN ==================
    // Calc each even of a triangle only if visit = 0
    if( va->getVisit() == 0 ){
      mesh->setEvenPosition(va, vb, vc, ea, ec);
    }
    if( vb->getVisit() == 0 ){
      mesh->setEvenPosition(vb, vc, va, eb, ea);
    }
    if( vc->getVisit() == 0 ){
      mesh->setEvenPosition(vc, va, vb, ec, eb);
    }
    va->setVisit();
    vb->setVisit();
    vc->setVisit();
    // ================ EVEN END ================
    // ================== ODD ===================
    // interior odd: the oppo's next exists
    if( ea_op != NULL ) {
      Vec3f ao = ea_op->getNext()->getVertex()->get();
      vab = IN_ODD_ADJ * ( a + b ) + IN_ODD_OPP * ( ao + c );
    }
    // boundary odd: the oppo's next does not exist
    else {
      vab = BD_ODD_ADJ * ( a + b );
    }
    // b
    if( eb_op != NULL ) {
      Vec3f bo = eb_op->getNext()->getVertex()->get();
      vbc = IN_ODD_ADJ * ( b + c ) + IN_ODD_OPP * ( bo + a );
    }
    else {
      vbc = BD_ODD_ADJ * ( b + c );
    }
    // c
    if( ec_op != NULL ) {
      Vec3f co = ec_op->getNext()->getVertex()->get();
      vca = IN_ODD_ADJ * ( c + a ) + IN_ODD_OPP * ( co + b );
    }
    else {
      vca = BD_ODD_ADJ * ( c + a  );
    }
    // Change the positions
    ab->set(vab);  bc->set(vbc);  ca->set(vca);
    // ================ ODD END =================
    // interior even
    // boundary even

    // create 4 triangles
    mesh->addTriangle(bc, ca, ab);
    mesh->addTriangle(vb, bc, ab);
    mesh->addTriangle(ab, ca, va);
    mesh->addTriangle(bc, vc, ca);
  }
  triangles->EndIteration(titer);
  setTriangles(mesh->getTriangles());
  setEdges(mesh->getEdges());

  setVertices(mesh->getVertices());

  delete mesh;
}
// =================================================================
// Even vertex calc by Wolfgang
// =================================================================
void Mesh::setEvenPosition( Vertex* a, Vertex* b, Vertex* c, Edge* ea, Edge* ec) {
  int tri_n = 1;  // record the number of triangles adjacent to a
  int n = 2;      // record the number of vertices adjacet to a
  Vec3f newPosition = b->get() + c->get();
  Edge* ea_op;
  Edge* ec_op;
  Edge* le = ea;       // record current left edge
  Edge* re = ec;       // record current right edge
  Vertex* lv = b;     // record current left vertex
  Vertex* rv = c;     // record current right vertex
  std::cout << "1" << std::endl;
  // get all vertices left to b
  while( (ea_op = ea->getOpposite()) != NULL
        && (ec_op = ec->getOpposite()) != NULL ){
    // When ec doesnot meet eb, keep going.
    std::cout << "2" << std::endl;
    if( ea_op != ec ) {
      std::cout << "31" << std::endl;
      // std::cout << "ea_op" << std::endl;
      le = ea_op->getNext();
      lv = le->getVertex();

      tri_n++;// Get into a new triangle, increase tri_n;
      n++;    // Add a new Vertex
      newPosition += lv->get();
      ea = le->getNext();
    }
    // When eb doesnot meet ec, keep going.
    if( ec_op != ea ) {
      std::cout << "32" << std::endl;
      re = ec_op->getNext();
      rv = re->getVertex();

      tri_n++;// Get into a new triangle, increase tri_n;
      n++;    // Add a new Vertex
      newPosition += rv->get();
      ec = re;
    }
    // When the two edges meet, Calc the result and put it in mesh.
    else {
      std::cout << "33" << std::endl;
      if( n == 3 ) {
        newPosition = ((IN_EVEN_E3 * a->get()) + (IN_EVEN_E3_NEIBOR * newPosition));
      }
      else {
        newPosition = ((IN_EVEN_G3 * a->get()) + (IN_EVEN_E3_NEIBOR / (float)n) * newPosition);
      }
      break;
    }
  }
  // if ea_op is not null, then get till the left border
  if( ec_op == NULL) {
    while( (ea_op = ea->getOpposite()) != NULL ){
      std::cout << "41" << std::endl;
      le = ea_op->getNext();
      lv = le->getVertex();

      tri_n++;// Get into a new triangle, increase tri_n;
      n++;    // Add a new Vertex
      // newPosition += lv->get();
      ea = le->getNext();
    }
    //if( rv == NULL ) rv = c;
    newPosition = BD_EVEN_MID * a->get() + BD_EVEN_END * (lv->get()+rv->get());

  }
  if( ea_op == NULL ) {
    // if ec_op is not null, then get till the right border
    while( (ec_op = ec->getOpposite()) != NULL ){
      std::cout << "42" << std::endl;
      re = ec_op->getNext();
      std::cout << "421" << std::endl;
      rv = re->getVertex();
      std::cout << "422" << std::endl;

      tri_n++;// Get into a new triangle, increase tri_n;
      n++;    // Add a new Vertex
      // newPosition += rv->get();
      std::cout << "423" << std::endl;
      ec = re;
      std::cout << "424" << std::endl;
    }
    std::cout << "425" << std::endl;
    //if( lv == NULL ) lv = b;
    newPosition = BD_EVEN_MID * a->get() + BD_EVEN_END * (lv->get()+rv->get());
    std::cout << "426" << std::endl;

  }

  std::cout << "5" << std::endl;
  addVertex(a->getIndex(), a->getLevel(), newPosition);
  std::cout << "6" << std::endl;
  a->setVisit(tri_n);
  std::cout << "7" << std::endl;
}

// =================================================================
// SIMPLIFICATION
// =================================================================

// void Mesh::Simplification(int target_tri_count) {
//   printf ("Simplify the mesh! %d -> %d\n", numTriangles(), target_tri_count);
// }

// =================================================================
