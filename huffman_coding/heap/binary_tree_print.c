#include <stdlib.h>

typedef struct binary_tree_node {
    struct binary_tree_node *parent;
    void *data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_node_t;

/**
 * @brief Creates a generic Binary Tree node.
 *
 * This function initializes a new binary tree node and returns a pointer to it.
 *
 * @param parent A pointer to the parent node.
 * @param data The data to be stored in the node.
 * @return A pointer to the created binary_tree_node_t structure, or NULL if it fails.
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data) {
    
    binary_tree_node_t *new_node = (binary_tree_node_t *)malloc(sizeof(binary_tree_node_t));

    if (new_node == NULL) {
        
        return NULL;
    }

    new_node->parent = parent;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}