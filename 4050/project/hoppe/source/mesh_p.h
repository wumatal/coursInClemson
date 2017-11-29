#pragma once
#include "mesh.h"
#include "vector.h"

void compute_facet_normals(Mesh);
void compute_normals(Mesh);
void compute_adjacencies(Mesh);
int has_crease(Mesh, int, int);

typedef struct AdjacencyRec
{
    int *faces;
    int count;
} Adjacency;

struct MeshRec
{
    int vertCount;
    int normCount;
    int faceCount;
    int creaseCount;
    vec3 *verts;
    vec3 *norms;
    int *faces;
    int *creases;
    vec3 *facetNorms;
    Adjacency *adjacencies;
    int *adjacencyTable;
};
