#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

/**
 * @struct node
 * Represents a node in the heap.
 */
typedef struct node
{
    void *data;
} node_t;

/**
 * @struct heap
 * Represents a heap data structure.
 */
typedef struct heap
{
    node_t *root;
    size_t size;
    int (*data_cmp)(void *, void *);

} heap_t;

/**
 * @brief Creates a new heap.
 *
 * This function initializes a new heap structure and returns a pointer to it.
 *
 * @param data_cmp A pointer to a comparison function.
 * @return A pointer to the created heap_t structure, or NULL if it fails.
 */
heap_t *heap_create(int (*data_cmp)(void *, void *));

#endif /* HEAP_H */
