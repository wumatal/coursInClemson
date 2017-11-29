#include "os.h"
#include "mesh_p.h"

Mesh create_mesh(const char *filename)
{
    Mesh mesh;
    FILE *file;
    vec3 *verts;
    int *faces;
    int *creases;
    int maxId = 0;
    int *idTable;
    int currentIndex = 0;
    vec3 bounds[2], extent, center;
    float maxExtent, scale;
    char line[128];
    int id;
    char *params;

    // Open the file.
    if (!(file = fopen(filename, "r")))
        return 0;

    // Initialize the mesh object.
    mesh = (Mesh) malloc(sizeof(struct MeshRec));
    memset(mesh, 0, sizeof(struct MeshRec));

    // Count the number of vertices, creases, and faces.
    while (!feof(file))
    {
        if (!fgets(line, sizeof(line), file))
            break;

        switch (line[0])
        {
            case 'V':
            {
                char *params = strchr(line, ' ');
                maxId = max(maxId, atoi(params));
                mesh->vertCount++;
                break;
            }

            case 'F': mesh->faceCount++; break;
            case 'E': mesh->creaseCount++; break;
        }
    }

    // Allocate memory.
    verts = mesh->verts = (vec3 *) malloc(sizeof(vec3) * mesh->vertCount);
    faces = mesh->faces = (int *) malloc(3 * sizeof(int) * mesh->faceCount);
    creases = mesh->creases = (int *) malloc(2 * sizeof(int) * mesh->creaseCount);
    idTable = (int *) malloc(sizeof(int) * (maxId + 1));

    // Read in the file.
    fseek(file, 0, SEEK_SET);
    maxify_vec3(bounds + 0);
    minify_vec3(bounds + 1);
    while (!feof(file))
    {
        if (!fgets(line, sizeof(line), file))
            break;

        switch (line[0])
        {
            case 'V':
                params = strchr(line, ' ');
                sscanf(params, "%d %f %f %f", &id, &verts->x, &verts->y, &verts->z);
                min_vec3(bounds + 0, verts);
                max_vec3(bounds + 1, verts);
                verts++;
                idTable[id] = currentIndex++;
                break;

            case 'F':
                params = strchr(line, ' ');
                sscanf(params, "%d %d %d %d", &id, faces, faces + 1, faces + 2);
                faces[0] = idTable[faces[0]];
                faces[1] = idTable[faces[1]];
                faces[2] = idTable[faces[2]];
                faces += 3;
                break;

            case 'E':
                params = strchr(line, ' ');
                sscanf(params, "%d %d", creases, creases + 1);
                creases[0] = idTable[creases[0]];
                creases[1] = idTable[creases[1]];
                creases += 2;
                break;
        }
    }

    // Free memory and close the file.
    free(idTable);
    fclose(file);

    // Center and scale the mesh.
    center = add_vec3(bounds[0], bounds[1]);
    scale_vec3(&center, 0.5f);
    extent = sub_vec3(bounds[1], bounds[0]);
    maxExtent = max(max(extent.x, extent.y), extent.z);
    scale = 2 / maxExtent;
    verts = mesh->verts;
    for (currentIndex = 0; currentIndex < mesh->vertCount; currentIndex++)
    {
        dwin_vec3(verts, center);
        scale_vec3(verts, scale);
        verts++;
    }

    return mesh;
}

void free_mesh(Mesh mesh)
{
    free(mesh->verts);
    free(mesh->faces);
    free(mesh->creases);
    free(mesh->norms);
    free(mesh->adjacencies);
    free(mesh->adjacencyTable);
    free(mesh);
}

void draw_facets(Mesh mesh, int wireframe)
{
    vec3 *verts = mesh->verts;
    vec3 *facetNorms = mesh->facetNorms;
    int *faces = mesh->faces;
    int faceIndex;

    // Draw the faces.
    glPolygonOffset(4, 8);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glBegin(GL_TRIANGLES);
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        glNormal3fv((float *) (facetNorms++));
        glVertex3fv((float *) (verts + *faces++));
        glVertex3fv((float *) (verts + *faces++));
        glVertex3fv((float *) (verts + *faces++));
    }
    glEnd();
    glDisable(GL_POLYGON_OFFSET_FILL);

    // Turn off lighting and prepare a vertex array.
    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, mesh->verts);

    // Draw a wireframe.
    if (wireframe)
    {
        glDepthMask(GL_FALSE);
        glLineWidth(1);
        glColor3f(0, 0, 0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, 3 * mesh->faceCount, GL_UNSIGNED_INT, mesh->faces);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDepthMask(GL_TRUE);
    }

    // Highlight the creases.
    glLineWidth(2);
    glColor3f(1, 0, 0);
    glDrawElements(GL_LINES, 2 * mesh->creaseCount, GL_UNSIGNED_INT, mesh->creases);

    glEnable(GL_LIGHTING);
}

void compute_facet_normals(Mesh mesh)
{
    int faceIndex;
    vec3 *verts = mesh->verts;
    int *faces = mesh->faces;
    vec3 *facetNorms;

    free(mesh->facetNorms);
    mesh->facetNorms = (vec3 *) malloc(sizeof(vec3) * mesh->faceCount);
    facetNorms = mesh->facetNorms;

    // Compute each facet normal with a cross product.
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        vec3 a = verts[*faces++];
        vec3 b = verts[*faces++];
        vec3 c = verts[*faces++];
        vec3 u = sub_vec3(b, a);
        vec3 v = sub_vec3(c, a);
        *facetNorms = cross_vec3(u, v);
        normalize(facetNorms++);
    }
}

void compute_normals(Mesh mesh)
{
    int vertIndex;
    vec3 *norms;
    vec3 *verts = mesh->verts;

    compute_adjacencies(mesh);
    compute_facet_normals(mesh);

    free(mesh->norms);
    mesh->norms = (vec3 *) malloc(sizeof(vec3) * mesh->vertCount);
    norms = mesh->norms;

    // Average the adjacent facet normals at each vertex.
    for (vertIndex = 0; vertIndex < mesh->vertCount; vertIndex++)
    {
        int faceIndex;
        Adjacency *adjacency = mesh->adjacencies + vertIndex;

        zerify_vec3(norms);
        for (faceIndex = 0; faceIndex < adjacency->count; faceIndex++)
            acc_vec3(norms, mesh->facetNorms[adjacency->faces[faceIndex]]);
        scale_vec3(norms++, 1.0f / adjacency->count);
    }
}

void compute_adjacencies(Mesh mesh)
{
    int *faces;
    int faceIndex, vertIndex, cornerIndex;
    int count;

    // Initialize memory.
    free(mesh->adjacencies);
    free(mesh->adjacencyTable);
    mesh->adjacencies = (Adjacency *) malloc(sizeof(Adjacency) * mesh->vertCount);
    memset(mesh->adjacencies, 0, sizeof(Adjacency) * mesh->vertCount);
    mesh->adjacencyTable = (int *) malloc(sizeof(int) * mesh->faceCount * 3);

    // Count all the adjacencies.
    faces = mesh->faces;
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        mesh->adjacencies[*faces++].count++;
        mesh->adjacencies[*faces++].count++;
        mesh->adjacencies[*faces++].count++;
    }

    // Create pointers into the table.
    faces = mesh->adjacencyTable;
    for (vertIndex = 0; vertIndex < mesh->vertCount; vertIndex++)
    {
        mesh->adjacencies[vertIndex].faces = faces;
        faces += mesh->adjacencies[vertIndex].count;
    }

    // Reset the counts.
    for (vertIndex = 0; vertIndex < mesh->vertCount; vertIndex++)
        mesh->adjacencies[vertIndex].count = 0;

    // Collect the adjacencies.
    faces = mesh->faces;
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        for (cornerIndex = 0; cornerIndex < 3; cornerIndex++)
        {
            vertIndex = *faces++;
            count = mesh->adjacencies[vertIndex].count;
            mesh->adjacencies[vertIndex].faces[count] = faceIndex;
            mesh->adjacencies[vertIndex].count = count + 1;
        }
    }
}

// create a small stellated dodecahedron
Mesh generate_example(int tagged)
{
    int pentagonFace, vertex;
    Mesh mesh;
    int *faces;
    float *icosahedron;
    vec3 *verts;
    const float height = 1.3763819f;

    // We should've pre-declared the icosahedron instead of the dodecahedron.
    // Oh well.  They are duals of each other so it doesn't really matter.

    const float dodecahedron[20 * 3] =
    {
         0.000000f,  0.000000f,  1.000000f,
         0.666667f,  0.000000f,  0.745356f,
        -0.333333f,  0.577350f,  0.745356f,
        -0.333333f, -0.577350f,  0.745356f,
         0.745356f,  0.577350f,  0.333333f,
         0.745356f, -0.577350f,  0.333333f,
        -0.872678f,  0.356822f,  0.333333f,
         0.127322f,  0.934172f,  0.333333f,
         0.127322f, -0.934172f,  0.333333f,
        -0.872678f, -0.356822f,  0.333333f,
         0.872678f,  0.356822f, -0.333333f,
         0.872678f, -0.356822f, -0.333333f,
        -0.745356f,  0.577350f, -0.333333f,
        -0.127322f,  0.934172f, -0.333333f,
        -0.127322f, -0.934172f, -0.333333f,
        -0.745356f, -0.577350f, -0.333333f,
         0.333333f,  0.577350f, -0.745356f,
         0.333333f, -0.577350f, -0.745356f,
        -0.666667f,  0.000000f, -0.745356f,
         0.000000f,  0.000000f, -1.000000f,
    };

    const int pentagons[12 * 5] =
    {
        0,1,4,7,2,
        0,2,6,9,3,
        0,3,8,5,1,
        1,5,11,10,4,
        2,7,13,12,6,
        3,9,15,14,8,
        4,10,16,13,7,
        5,8,14,17,11,
        6,12,18,15,9,
        10,11,17,19,16,
        12,13,16,19,18,
        14,15,18,19,17,
    };

    // Initialize the mesh.
    mesh = (Mesh) malloc(sizeof(struct MeshRec));
    memset(mesh, 0, sizeof(struct MeshRec));
    mesh->vertCount = 20 + 12;
    mesh->faceCount = 12 * 5;
    mesh->creaseCount = 0;
    mesh->verts = (vec3 *) malloc(mesh->vertCount * sizeof(vec3));
    mesh->faces = (int *) malloc(mesh->faceCount * sizeof(int) * 3);
    memcpy(mesh->verts, dodecahedron, sizeof(dodecahedron));

    // Compute each icosahedron vertex as the center of the corresponding pentagon.
    icosahedron = (float *) (mesh->verts + 20);
    for (pentagonFace = 0; pentagonFace < 12; pentagonFace++)
    {
        int axis;
        for (axis = 0; axis < 3; axis++)
        {
            float x = 0;
            for (vertex = 0; vertex < 5; vertex++)
            {
                int index = pentagons[pentagonFace * 5 + vertex];
                x += dodecahedron[index * 3 + axis];
            }
            icosahedron[pentagonFace * 3 + axis] = x / 5;
            icosahedron[pentagonFace * 3 + axis] *= (1 + height);
        }
    }

    // Scale the entire model.
    verts = mesh->verts;
    for (vertex = 0; vertex < mesh->vertCount; vertex++)
        scale_vec3(verts++, 0.75f);

    // Create the triangles.
    faces = mesh->faces;
    for (pentagonFace = 0; pentagonFace < 12; pentagonFace++)
    {
        vertex = 0;
        while (vertex < 5)
        {
            *faces++ = pentagons[pentagonFace * 5 + (vertex++ % 5)];
            *faces++ = pentagons[pentagonFace * 5 + (vertex % 5)];
            *faces++ = 20 + pentagonFace;
        }
    }
    compute_facet_normals(mesh);

    // Add some random creases if desired.
    if (tagged)
    {
        int creases[] =
        {
            0,1,    1,4,    4,7,    7,2,    2,0,
            3,9,    9,15,   15,14,  14,8,   8,3,
            3,25,   9,25,   15,25,  14,25,  8,25,
            17,27,  27,11,
        };
        mesh->creaseCount = sizeof(creases) / (sizeof(int) * 2);
        mesh->creases = (int *) malloc(sizeof(creases));
        memcpy(mesh->creases, creases, sizeof(creases));
    }

    return mesh;
}

Mesh generate_icosahedron()
{
    Mesh mesh;

    #define X .525731112119133606f
    #define Z .850650808352039932f

    const vec3 verts[12] =
    {
        {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
        {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
        {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0},
    };

    #undef X
    #undef Z

    const int faces[20 * 3] =
    {
       0,4,1,     0,9,4,      9,5,4,      4,5,8,      4,8,1,
       8,10,1,    8,3,10,     5,3,8,      5,2,3,      2,7,3,
       7,10,3,    7,6,10,     7,11,6,     11,0,6,     0,1,6,
       6,1,10,    9,0,11,     9,11,2,     9,2,5,      7,2,11,
    };

    mesh = (Mesh) malloc(sizeof(struct MeshRec));
    memset(mesh, 0, sizeof(struct MeshRec));
    mesh->vertCount = sizeof(verts) / sizeof(vec3);
    mesh->faceCount = sizeof(faces) / (3 * sizeof(int));
    mesh->creaseCount = 0;
    mesh->verts = (vec3 *) malloc(mesh->vertCount * sizeof(vec3));
    mesh->faces = (int *) malloc(mesh->faceCount * sizeof(int) * 3);
    memcpy(mesh->verts, verts, sizeof(verts));
    memcpy(mesh->faces, faces, sizeof(faces));

    compute_facet_normals(mesh);

    return mesh;
}

MeshBuffers *create_vbos(Mesh mesh)
{
    // TBD
    // assert(mesh->finalized);
    return 0;
}

void finalize(Mesh mesh)
{
    compute_facet_normals(mesh);
    // TBD duplicate vertices along edges so that we can have one normal per vertex for the VBOs
}

void sort_mesh(Mesh mesh, float *ray)
{
    // TBD
}

int has_crease(Mesh mesh, int a, int b)
{
    int creaseIndex;
    int *creases;
    creases = mesh->creases;
    for (creaseIndex = 0; creaseIndex < mesh->creaseCount; creaseIndex++)
    {
        int u = *creases++;
        int v = *creases++;
        if ((a == u && b == v) || (a == v && b == u))
            return 1;
    }
    return 0;
}
