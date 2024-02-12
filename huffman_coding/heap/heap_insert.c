#include "heap.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value in a Min Binary Heap
 * @heap: Pointer to the heap in which the node has to be inserted
 * @data: Pointer containing the data to store in the new node
 *
 * Return: Pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
    binary_tree_node_t *new_node, *parent;
    size_t index;

    if (!heap || !data)
        return NULL;

    new_node = binary_tree_node(NULL, data);
    if (!new_node)
        return NULL;

    if (!heap->root)
    {
        heap->root = new_node;
        heap->size++;
        return new_node;
    }

    index = (heap->size + 1) / 2;
    parent = heap->root;

    while (index > 1)
    {
        if (index & 1)
            parent = parent->left;
        else
            parent = parent->right;

        index /= 2;
    }

    if (!(heap->size % 2))
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    heap->size++;

    /* Perform heapify-up */
    while (new_node->parent && heap->data_cmp(new_node->parent->data, new_node->data) > 0)
    {
        swap_nodes(new_node->parent, new_node);
        new_node = new_node->parent;
    }

    return new_node;
}
