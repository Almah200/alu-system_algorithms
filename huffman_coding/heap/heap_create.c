#include "heap.h"
#include <stddef.h>

typedef struct HeapNode {
    void *data;
} HeapNode;

typedef struct Heap {
    HeapNode **root;
    size_t size;
    int (*data_cmp)(void *, void *);
} heap_t;

heap_t *heap_create() {
    heap_t *new_heap = malloc(sizeof(heap_t));
    if (new_heap == NULL) {
        
        return NULL;
    }

    
    new_heap->size = 0;
    

    return new_heap;
}

