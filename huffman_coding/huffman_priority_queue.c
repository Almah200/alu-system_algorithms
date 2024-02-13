#include "heap/heap.h"
#include <stdlib.h>

/**
 * huffman_priority_queue - Creates a priority queue.
 * @data: Array of characters.
 * @freq: Array containing associated frequencies.
 * @size: Size of the arrays.
 *
 * Return: Pointer to the created min heap (priority queue).
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
heap_t *priority_queue = NULL;
binary_tree_node_t *node = NULL;
heap_t *symbol = NULL;
size_t i;

if (!data || !freq || size == 0)
return (NULL);

priority_queue = heap_create(*data);
if (!priority_queue)
return (NULL);

for (i = 0; i < size; i++)
{
node = binary_tree_node(NULL, NULL);
if (!node)
{
heap_delete(priority_queue, NULL);
return (NULL);
}

symbol = symbol_create(data[i], freq[i]);
if (!symbol)
{
free(node);
heap_delete(priority_queue, NULL);
return (NULL);
}

node->data = symbol;
if (heap_insert(priority_queue, node) == NULL)
{
free(node);
symbol_delete(symbol);
heap_delete(priority_queue, NULL);
return (NULL);
}
}

return (priority_queue);
}
