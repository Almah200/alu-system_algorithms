
#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdlib.h>
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
 * struct symbol - Data structure representing frequency.
 * @data: The data to be stored in the structure.
 * @freq: The frequency associated with the data.
 */
typedef struct symbol
{
char data;
size_t freq;
} symbol_t;

/**
 * heap_data_cmp - Compare two nodes based on their frequencies.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 *
 * Return: Positive value if frequency of node1 is greater,
 *         negative value if frequency of node2 is greater,
 *         or 0 if frequencies are equal.
 */
int heap_data_cmp(void *node1, void *node2);

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

/*Proto types*/
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));
/*symbol_t *symbol_create(char data, size_t freq); */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);

#endif
