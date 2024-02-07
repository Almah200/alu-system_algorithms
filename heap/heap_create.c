#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


// Structure to represent a node in the heap
typedef struct HeapNode {
    void *data;
} HeapNode;

// Structure to represent the heap
typedef struct Heap {
    HeapNode **root;
    size_t size;
    int (*data_cmp)(void *, void *);
} heap_t;

// Comparison function for integers (replace with your own comparison logic)
int example_data_cmp(void *data1, void *data2) {
    return (*(int *)data1) - (*(int *)data2);
}

// Function to create a Heap data structure
heap_t *heap_create(int (*data_cmp)(void *, void *)) {
    // Allocate memory for the heap structure
    heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));
    if (new_heap == NULL) {
        // Allocation failure
        return NULL;
    }

    // Initialize the heap properties
    new_heap->root = NULL;
    new_heap->size = 0;
    new_heap->data_cmp = data_cmp;

    return new_heap;
}
