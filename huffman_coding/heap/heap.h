#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 * @print_data: Function to print the data stored in a node
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_node_t *tree, int offset, int depth,
                   char **s, int (*print_data)(char *, void *))
{
    // ... (rest of your code)
}

// ... (rest of your code)
