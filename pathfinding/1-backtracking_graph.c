#include "pathfinding.h"
#include <stdio.h>

/**
 * create_queue_node - Creates a new queue node.
 * @vertex: The vertex to store in the node.
 * @next: Pointer to the next node.
 *
 * Return: A pointer to the new node.
 */
queue_t *create_queue_node(char *vertex, queue_t *next)
{
queue_t *new_node = malloc(sizeof(queue_t));

if (new_node)
{
new_node->vertex = vertex;
new_node->next = next;
}

return (new_node);
}

/**
 * enqueue - Adds a new node at the end of the queue.
 * @queue: Pointer to the queue.
 * @vertex: The vertex to enqueue.
 */
void enqueue(queue_t **queue, char *vertex)
{
queue_t *new_node = create_queue_node(vertex, NULL);

if (new_node)
{
if (*queue == NULL)
*queue = new_node;
else
{
queue_t *temp = *queue;

while (temp->next)
temp = temp->next;

temp->next = new_node;
}
}
}

/**
 * dequeue - Removes the front node from the queue.
 * @queue: Pointer to the queue.
 *
 * Return: The dequeued vertex.
 */
char *dequeue(queue_t **queue)
{
if (*queue == NULL)
return (NULL);

char *vertex = (*queue)->vertex;
queue_t *temp = *queue;

*queue = (*queue)->next;
free(temp);

return (vertex);
}

/**
 * backtracking_dfs - Performs recursive backtracking DFS to find a path.
 * @graph: Pointer to the graph.
 * @start: Starting vertex.
 * @target: Target vertex.
 * @visited: Array to keep track of visited vertices.
 * @path: Current path being explored.
 * @result: Resulting path.
 */
void backtracking_dfs(graph_t *graph, vertex_t const *start,
vertex_t const *target, int *visited,
queue_t **path, queue_t **result)
{
if (start == NULL || target == NULL)
return;

printf("Checking %s\n", start->content);
visited[start->index] = 1;
enqueue(path, start->content);

if (start == target)
{
*result = *path;  // Store the result path
return;
}

for (edge_t *edge = start->edges; edge != NULL; edge = edge->next)
{
if (!visited[edge->dest->index])
{
backtracking_dfs(graph, edge->dest, target, visited, path, result);


if (*result != NULL)
return;
}
}


dequeue(path);
}

/**
 * backtracking_graph - Finds the first path from start to target in a graph.
 * @graph: Pointer to the graph.
 * @start: Starting vertex.
 * @target: Target vertex.
 *
 * Return: A queue containing the path from start
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target)
{
if (graph == NULL || start == NULL || target == NULL)
return (NULL);

int *visited = calloc(graph->nb_vertices, sizeof(int));
queue_t *path = NULL;
queue_t *result = NULL;

if (visited == NULL)
return (NULL);

backtracking_dfs(graph, start, target, visited, &path, &result);

free(visited);

return (result);
}
