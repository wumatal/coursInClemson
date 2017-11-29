#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MeshRec *Mesh;

typedef struct MeshBuffersRec
{
    GLuint verts;
    GLuint norms;
    GLuint indices;
    int triangleCount;
} MeshBuffers;

Mesh create_mesh(const char *filename);
Mesh generate_example(int tagged);
Mesh generate_icosahedron();
void free_mesh(Mesh);
void draw_facets(Mesh, int wireframe);
Mesh subdivide(Mesh);
void finalize(Mesh);

// TBD
MeshBuffers *create_vbos(Mesh);
void sort_mesh(Mesh, float *ray);

#ifdef __cplusplus
}
#endif
