// heap_create.c

#include "heap.h"
#include <stdlib.h>

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
    heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));
    if (new_heap == NULL)
    {
        return NULL;
    }

    new_heap->size = 0;
    new_heap->root = NULL;
    new_heap->data_cmp = data_cmp;

    return new_heap;
}
