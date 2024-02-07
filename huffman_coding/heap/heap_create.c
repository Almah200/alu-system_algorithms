#include "heap.h"
#include <stdlib.h>

heap_t *heap_create() {
    heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));
    if (new_heap == NULL) {
        return NULL;
    }

    new_heap->size = 0;

    return new_heap;
}
