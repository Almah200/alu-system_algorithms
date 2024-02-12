#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int int_cmp(void *a, void *b) {
  
    return (*(int *)a - *(int *)b);
}

heap_t *heap_create(int (*compar)(void *, void *));

int main(void)
{
    heap_t *heap;

   
    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);
    return (EXIT_SUCCESS);
}
