#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

typedef struct node {
    void *data;
    // Add other members if needed
} node_t;

typedef struct heap {
    node_t *root;
    size_t size;
    int (*data_cmp)(void *, void *);
    // Add other members if needed
} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *));
// Add other function prototypes if needed

#endif /* HEAP_H */
