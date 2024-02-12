#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

typedef struct node {
    void *data;

} node_t;

typedef struct heap {
    node_t *root;
    size_t size;
    int (*data_cmp)(void *, void *)

} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *));

#endif /* HEAP_H */
