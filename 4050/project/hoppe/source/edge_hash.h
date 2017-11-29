#pragma once

typedef struct EdgeHashRec *EdgeHash;
typedef struct HashIteratorRec *HashIterator;

// Construction and destruction
EdgeHash create_hash(int vertCount);
void free_hash(EdgeHash);

// Hash functions
int insert_edge(EdgeHash, int, int);
int get_edge(EdgeHash, int, int);
int edge_count(EdgeHash);
int neighbor_count(EdgeHash, int vertIndex);
int get_neighbor(EdgeHash, int vertIndex, int neighIndex);

// Iteration functions
HashIterator create_iterator(EdgeHash);
void free_iterator(HashIterator);
void get_keys(HashIterator, int *, int *);
int get_common_neighbors(HashIterator, int *, int *);
void advance_iterator(HashIterator);
