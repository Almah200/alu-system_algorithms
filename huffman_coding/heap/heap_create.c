#include "heap.h"

typedef struct HeapNode {
    void *data;
} HeapNode;

typedef struct Heap {
    HeapNode **root;
    size_t size;
    int (*data_cmp)(void *, void *);
} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *)) {
    

    return NULL; 
}
