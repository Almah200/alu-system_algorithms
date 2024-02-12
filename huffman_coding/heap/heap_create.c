#include "heap.h"

/**
 * @brief Creates a new heap.
 *
 * This function initializes a new heap structure and returns a pointer to it.
 *
 * @param data_cmp A pointer to a comparison function.
 * @return A pointer to the created heap_t structure, or NULL if it fails.
 */
heap_t *heap_create(int (*data_cmp)(void *, void *)) {
    // Allocate memory for the heap structure
    heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));

    if (new_heap == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Initialize heap members
    new_heap->root = NULL;
    new_heap->size = 0;
    new_heap->data_cmp = data_cmp;

    return new_heap;
}
