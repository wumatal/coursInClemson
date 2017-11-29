#include "os.h"
#include "mesh_p.h"
#include "edge_hash.h"
#include <math.h>

typedef enum {SMOOTH, DART, REG_CREASE, IRR_CREASE, CORNER} code;

// Transient data associated with the mesh.
typedef struct AnnotationsRec
{
    Mesh mesh;
    unsigned int *creaseFlags;
    float *alpha;
    int alphaCount;
} *Annotations;

static void flag_creases(Annotations);
static void grow_alpha(Annotations);
static inline int is_sharp(Annotations, int);
static inline code get_code(Annotations, EdgeHash, int);

const float twopi = 6.28318530717958647692f;

static const int mask_table[5][5] =
{
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 2, 3, 3},
    {1, 1, 3, 2, 2},
    {1, 1, 3, 2, 2},
};

Mesh subdivide(Mesh mesh)
{
    Mesh newMesh;
    EdgeHash edgeHash;
    HashIterator hashIterator;
    Annotations annotations;
    int edgeCount;
    int faceIndex, edgeIndex, creaseIndex, vertIndex, neighIndex;
    int *srcFaces, *dstFaces;
    vec3 *srcVerts, *dstVerts;
    int *srcCreases, *dstCreases;

    // Initialize the annotation structure.
    annotations = (Annotations) malloc(sizeof(struct AnnotationsRec));
    memset(annotations, 0, sizeof(struct AnnotationsRec));
    annotations->mesh = mesh;
    flag_creases(annotations);

    // Create a list of edges.
    edgeHash = create_hash(mesh->vertCount);
    srcFaces = mesh->faces;
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        insert_edge(edgeHash, srcFaces[0], srcFaces[1]);
        insert_edge(edgeHash, srcFaces[1], srcFaces[2]);
        insert_edge(edgeHash, srcFaces[2], srcFaces[0]);
        srcFaces += 3;
    }
    edgeCount = edge_count(edgeHash);

    // Allocate the new mesh.
    newMesh = (Mesh) malloc(sizeof(struct MeshRec));
    memset(newMesh, 0, sizeof(struct MeshRec));
    newMesh->faceCount = mesh->faceCount * 4;
    newMesh->vertCount = mesh->vertCount + edgeCount;
    newMesh->faces = (int *) malloc(sizeof(int) * 3 * newMesh->faceCount);
    newMesh->verts = (vec3 *) malloc(sizeof(vec3) * newMesh->vertCount);

    // Create a new vertex at each edge.
    hashIterator = create_iterator(edgeHash);
    dstVerts = newMesh->verts + mesh->vertCount;
    for (edgeIndex = 0; edgeIndex < edgeCount; edgeIndex++)
    {
        int a, b, c, d, mask;
        code ca, cb;

        get_keys(hashIterator, &a, &b);
        ca = get_code(annotations, edgeHash, a);

        if (ca == SMOOTH)
        {
            mask = 1;
        }
        else
        {
            cb = get_code(annotations, edgeHash, b);
            mask = mask_table[ca][cb];
        }

        switch (mask)
        {
            case 1:
                if (get_common_neighbors(hashIterator, &c, &d))
                {
                    vec3 *vert = dstVerts++;
                    *vert = add_vec3(mesh->verts[a], mesh->verts[b]);
                    macc_vec3(vert, 3, mesh->verts[c]);
                    acc_vec3(vert, mesh->verts[d]);
                    scale_vec3(vert, .125f);
                    break;
                }
                // else fall through

            case 2:
                *dstVerts++ = midpoint(mesh->verts, a, b);
                break;

            case 3:
            {
                float weight = (ca == REG_CREASE) ? 0.625f : 0.375f;
                assert(ca == REG_CREASE || cb == REG_CREASE);
                assert(!(ca == REG_CREASE && cb == REG_CREASE));
                *dstVerts++ = lerp(mesh->verts, weight, a, b);
                break;
            }
        }

        advance_iterator(hashIterator);
    }
    free_iterator(hashIterator);

    // Move the old vertices.
    dstVerts = newMesh->verts;
    srcVerts = mesh->verts;
    for (vertIndex = 0; vertIndex < mesh->vertCount; vertIndex++)
    {
        vec3 *dstVert = dstVerts++;

        int valence = neighbor_count(edgeHash, vertIndex);
        if (valence >= annotations->alphaCount)
            grow_alpha(annotations);

        *dstVert = *srcVerts++;

        switch(get_code(annotations, edgeHash, vertIndex))
        {
            case SMOOTH:
            case DART:
                scale_vec3(dstVert, annotations->alpha[valence]);
                for (neighIndex = 0; neighIndex < valence; neighIndex++)
                {
                    int neigh = get_neighbor(edgeHash, vertIndex, neighIndex);
                    acc_vec3(dstVert, mesh->verts[neigh]);
                }
                scale_vec3(dstVert, 1.f / (valence + annotations->alpha[valence]));
                break;

            case REG_CREASE:
            case IRR_CREASE:
                scale_vec3(dstVert, 6);
                for (neighIndex = 0; neighIndex < valence; neighIndex++)
                {
                    int neigh = get_neighbor(edgeHash, vertIndex, neighIndex);
                    if (is_sharp(annotations, neigh) && has_crease(mesh, vertIndex, neigh))
                        acc_vec3(dstVert, mesh->verts[neigh]);
                }
                scale_vec3(dstVert, .125f);
                break;

            case CORNER:
                break;
        }
    }

    // Create the new faces.
    dstFaces = newMesh->faces;
    srcFaces = mesh->faces;
    for (faceIndex = 0; faceIndex < mesh->faceCount; faceIndex++)
    {
        int A = *srcFaces++;
        int B = *srcFaces++;
        int C = *srcFaces++;

        int a = mesh->vertCount + get_edge(edgeHash, A, B);
        int b = mesh->vertCount + get_edge(edgeHash, B, C);
        int c = mesh->vertCount + get_edge(edgeHash, C, A);

        *dstFaces++ = A;
        *dstFaces++ = a;
        *dstFaces++ = c;

        *dstFaces++ = B;
        *dstFaces++ = b;
        *dstFaces++ = a;

        *dstFaces++ = C;
        *dstFaces++ = c;
        *dstFaces++ = b;

        *dstFaces++ = c;
        *dstFaces++ = a;
        *dstFaces++ = b;
    }

    // Subdivide the creases.
    newMesh->creaseCount = mesh->creaseCount * 2;
    newMesh->creases = (int *) malloc(newMesh->creaseCount * sizeof(int) * 2);
    dstCreases = newMesh->creases;
    srcCreases = mesh->creases;
    for (creaseIndex = 0; creaseIndex < mesh->creaseCount; creaseIndex++)
    {
        int a = *srcCreases++;
        int b = *srcCreases++;
        int midpoint = mesh->vertCount + get_edge(edgeHash, a, b);
        *dstCreases++ = a;
        *dstCreases++ = midpoint;
        *dstCreases++ = midpoint;
        *dstCreases++ = b;
    }

    // Free all the transient data.
    free_hash(edgeHash);
    free(annotations->alpha);
    free(annotations);

    return newMesh;
}

static inline void flag_crease(unsigned int *flags, int index)
{
    flags[index / 32] |= 1 << (index % 32);
}

static void flag_creases(Annotations obj)
{
    int creaseIndex;
    int *creases;
    int byteCount;

    free(obj->creaseFlags);
    byteCount = (obj->mesh->vertCount + 3) & ~0x3;
    obj->creaseFlags = (unsigned int *) malloc(byteCount);
    memset(obj->creaseFlags, 0, byteCount);
    creases = obj->mesh->creases;
    for (creaseIndex = 0; creaseIndex < obj->mesh->creaseCount; creaseIndex++)
    {
        flag_crease(obj->creaseFlags, *creases++);
        flag_crease(obj->creaseFlags, *creases++);
    }
}

static float compute_alpha(int valence)
{
    float a, n, alpha;
    n = (float) valence;
    a = 3 + 2 * cosf(twopi / n);
    a = .625f - (a * a) / 64.f;
    alpha = (n * (1 - a)) / a;
    return alpha;
}

static void grow_alpha(Annotations obj)
{
    float *table;
    int count = obj->alphaCount ? (obj->alphaCount * 2) : 16;
    int valence;

    table = (float *) malloc(sizeof(float) * count);
    for (valence = 1; valence < count; valence++)
        table[valence] = compute_alpha(valence);

    free(obj->alpha);
    obj->alpha = table;
    obj->alphaCount = count;
}

static inline int is_sharp(Annotations annotations, int index)
{
    unsigned int *flags = annotations->creaseFlags;
    return flags[index / 32] & (1 << (index % 32));
}

static inline code get_code(Annotations obj, EdgeHash hash, int vertIndex)
{
    int neighCount, sharpCount;
    int neighIndex;
    int sharpNeighbors[2];

    if (!is_sharp(obj, vertIndex))
        return SMOOTH;

    neighCount = neighbor_count(hash, vertIndex);
    sharpCount = 0;
    for (neighIndex = 0; neighIndex < neighCount; neighIndex++)
    {
        int neighbor = get_neighbor(hash, vertIndex, neighIndex);
        if (is_sharp(obj, neighbor) && has_crease(obj->mesh, vertIndex, neighbor))
        {
            if (sharpCount == 2)
                return CORNER;

            sharpNeighbors[sharpCount++] = neighIndex;
        }
    }

    assert(sharpCount != 0);

    if (sharpCount == 1)
        return DART;

    if (neighCount == 6)
    {
        if ((sharpNeighbors[1] + 3) % 6 == sharpNeighbors[0])
            return REG_CREASE;
    }

    return IRR_CREASE;
}
