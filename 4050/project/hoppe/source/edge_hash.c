#include "edge_hash.h"
#include "os.h"

//
// The hash needs to be studied and reworked.
// Try to minimize mallocs and hash collisions.
//
// Perhaps we could pre-allocate six slots for each vertex,
// similar to what we do for "neighbors".
//
// HASH_SIZE could be dynamic according to the vertCount?
//
// Currently we have some duplication of information, so maybe
// we could somehow combine "neighbors" with the hash?
//
// Some interesting sites that might help:
//  http://www.cl.cam.ac.uk/~cwc22/hashtable/
//  http://www.cs.rpi.edu/~cutler/classes/advancedgraphics/F05/assignments/assignment2/
//
// Also, get_common_neighbors() could be improved.  Do some profiling to see what hurts.
//

#define HASH_SIZE 1024 // must be a power of two

typedef struct HashElementRec
{
    int key1;
    int key2;
    int value;
    struct HashElementRec *nextBucket;
    struct HashElementRec *nextElement;
} HashElement;

typedef struct NeighborsRec
{
    int neighbors[6];
    int count;
    int *additional;
} Neighbors;

struct EdgeHashRec
{
    HashElement table[HASH_SIZE];
    HashElement *first;
    HashElement **last;
    Neighbors *neighbors;
    int edgeCount;
    int vertCount;
};

struct HashIteratorRec
{
    EdgeHash hash;
    HashElement *ptr;
};

EdgeHash create_hash(int vertCount)
{
    EdgeHash hash = (EdgeHash) malloc(sizeof(struct EdgeHashRec));
    memset(hash, 0, sizeof(struct EdgeHashRec));
    hash->last = &hash->first;
    hash->vertCount = vertCount;
    hash->neighbors = (Neighbors *) malloc(sizeof(struct NeighborsRec) * vertCount);
    memset(hash->neighbors, 0, sizeof(struct NeighborsRec) * vertCount);
    return hash;
}

void free_hash(EdgeHash hash)
{
    int i;

    for (i = 0; i < HASH_SIZE; i++)
    {
        HashElement *ptr = hash->table[i].nextBucket;
        while (ptr)
        {
            HashElement *nextBucket = ptr->nextBucket;
            free(ptr);
            ptr = nextBucket;
        }
    }

    for (i = 0; i < hash->vertCount; i++)
    {
        int *additional = hash->neighbors[i].additional;
        if (additional)
            free(additional);
    }

    free(hash->neighbors);
    free(hash);
}

static unsigned int hash_function(int a, int b)
{
    unsigned int index = (a + b) & (HASH_SIZE - 1);
    return index;
}

static void add_neighbor(Neighbors *neighbor, int i)
{
    const int arraySize = sizeof(neighbor->neighbors) / sizeof(int);

    if (neighbor->count < arraySize)
    {
        neighbor->neighbors[neighbor->count] = i;
    }
    else if (neighbor->count > arraySize)
    {
        int *additional;
        int heapCount = neighbor->count - arraySize;
        additional = (int *) malloc(sizeof(int) * (heapCount + 1));
        memcpy(additional, neighbor->additional, sizeof(int) * heapCount);
        additional[heapCount] = i;
        free(neighbor->additional);
        neighbor->additional = additional;
    }
    else
    {
        neighbor->additional = (int *) malloc(sizeof(int));
        neighbor->additional[0] = i;
    }

    neighbor->count++;
}

int insert_edge(EdgeHash hash, int key1, int key2)
{
    int a = min(key1, key2);
    int b = max(key1, key2);
    unsigned int index = hash_function(a, b);
    HashElement *ptr = hash->table + index;

    if (ptr->key1 == a && ptr->key2 == b)
        return 0;

    if (ptr->value == 0)
    {
        ptr->key1 = a;
        ptr->key2 = b;
        ptr->value = ++hash->edgeCount;
        *(hash->last) = ptr;
        hash->last = &ptr->nextElement;
        add_neighbor(hash->neighbors + key1, key2);
        add_neighbor(hash->neighbors + key2, key1);
        return 1;
    }

    while (ptr->nextBucket)
    {
        ptr = ptr->nextBucket;
        if (ptr->key1 == a && ptr->key2 == b)
            return 0;
    }

    ptr->nextBucket = (HashElement *) malloc(sizeof(HashElement));
    ptr = ptr->nextBucket;
    ptr->nextBucket = 0;
    ptr->nextElement = 0;

    ptr->key1 = a;
    ptr->key2 = b;
    ptr->value = ++hash->edgeCount;
    *(hash->last) = ptr;
    hash->last = &ptr->nextElement;
    add_neighbor(hash->neighbors + key1, key2);
    add_neighbor(hash->neighbors + key2, key1);
    return 1;
}

int edge_count(EdgeHash hash)
{
    return hash->edgeCount;
}

int neighbor_count(EdgeHash hash, int vertIndex)
{
    return hash->neighbors[vertIndex].count;
}

int get_neighbor(EdgeHash hash, int vertIndex, int neighIndex)
{
    const int arraySize = sizeof(hash->neighbors->neighbors) / sizeof(int);
    if (neighIndex < arraySize)
        return hash->neighbors[vertIndex].neighbors[neighIndex];
    return hash->neighbors[vertIndex].additional[neighIndex - arraySize];
}

int get_edge(EdgeHash hash, int key1, int key2)
{
    int a = min(key1, key2);
    int b = max(key1, key2);
    unsigned int index = hash_function(a, b);
    HashElement *ptr = hash->table + index;

    if (ptr->key1 == a && ptr->key2 == b)
        return ptr->value - 1;

    if (ptr->value == 0)
        return -1;

    while (ptr->nextBucket)
    {
        ptr = ptr->nextBucket;
        if (ptr->key1 == a && ptr->key2 == b)
            return ptr->value - 1;
    }

    return -1;
}

HashIterator create_iterator(EdgeHash hash)
{
    HashIterator iterator = (HashIterator) malloc(sizeof(struct HashIteratorRec));
    iterator->hash = hash;
    iterator->ptr = hash->first;
    return iterator;
}

void get_keys(HashIterator iterator, int *a, int *b)
{
    assert(iterator->ptr);
    assert(a);
    assert(b);
    *a = iterator->ptr->key1;
    *b = iterator->ptr->key2;
}

int get_common_neighbors(HashIterator iterator, int *a, int *b)
{
    int endpoint1, endpoint2;
    int i, j;
    int count1, count2;
    int found = 0;
    EdgeHash hash = iterator->hash;

    assert(iterator->ptr);
    assert(a);
    assert(b);

    endpoint1 = iterator->ptr->key1;
    endpoint2 = iterator->ptr->key2;
    count1 = hash->neighbors[endpoint1].count;
    count2 = hash->neighbors[endpoint2].count;

    for (i = 0; i < count1; i++)
    {
        int neigh1 = get_neighbor(hash, endpoint1, i);
        if (neigh1 != endpoint2)
        {
            for (j = 0; j < count2; j++)
            {
                int neigh2 = get_neighbor(hash, endpoint2, j);
                if (neigh1 == neigh2)
                {
                    if (found == 0)
                    {
                        *a = neigh1;
                        found++;
                    }
                    else
                    {
                        *b = neigh1;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

void advance_iterator(HashIterator iterator)
{
    if (iterator->ptr)
        iterator->ptr = iterator->ptr->nextElement;
}

void free_iterator(HashIterator iterator)
{
    free(iterator);
}
