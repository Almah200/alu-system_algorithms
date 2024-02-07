#ifndef _HEAP_H_
#define _HEAP_H_

#include <stddef.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
    void *data;
    struct binary_tree_node_s *left;
    struct binary_tree_node_s *right;
    struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Binary heap data structure
 *
 * @root: Pointer to the root node
 * @size: Size of the heap
 * @data_cmp: Pointer to the function to compare nodes' data
 */
typedef struct heap_s
{
    binary_tree_node_t *root;
    size_t size;
    int (*data_cmp)(void *, void *);
} heap_t;

#endif /* _HEAP_H_ */
