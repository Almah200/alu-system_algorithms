#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stddef.h>

/**
 * enum edge_type_t - Enumerates the different types of connections between two vertices
 *
 * @EDGE_UNIDIRECTIONAL: The connection is made only in one way
 * @EDGE_BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_t
{
    EDGE_UNIDIRECTIONAL = 0,
    EDGE_BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges (connections)
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 * @weight: Weight of the edge (for weighted graphs)
 */
typedef struct edge_s
{
    vertex_t *dest;
    struct edge_s *next;
    int weight;
} edge_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @x: Vertex X coordinate
 * @y: Vertex Y coordinate
 * @nb_edges: Number of connections with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 * This pointer points to another vertex in the graph, but it
 * doesn't stand for an edge between the two vertices.
 */
struct vertex_s
{
    size_t index;
    char *content;
    int x;
    int y;
    size_t nb_edges;
    edge_t *edges;
    vertex_t *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
    size_t nb_vertices;
    vertex_t *vertices;
} graph_t;

/*
 * FUNCTIONS
 */

/**
 * graph_create - Initializes a graph structure
 *
 * Return: A pointer to the allocated structure, NULL on failure
 */
graph_t *graph_create(void);

/**
 * graph_add_vertex - Add a vertex in a graph
 *
 * @graph: Pointer to the graph data structure
 * @str: String representing the new vertex
 * @x: X coordinate of the vertex
 * @y: Y coordinate of the vertex
 *
 * Return: A pointer to the created vertex, NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, char const *str, int x, int y);

/**
 * graph_add_edge - Add an edge between two vertices
 *
 * @graph: Pointer to the graph data structure
 * @src: String representing the vertex to make the connection from
 * @dest: String representing the vertex to connect to
 * @weight: Weight of the edge
 * @type: Connection type (Unidirectional or bidirectional)
 *
 * Return: 1 on success, 0 on failure
 */
int graph_add_edge(graph_t *graph, char const *src, char const *dest, int weight, edge_type_t type);

/**
 * graph_delete - Deallocates a graph
 *
 * @graph: Pointer to the graph to be deleted
 */
void graph_delete(graph_t *graph);

/**
 * graph_display - Utility function to display the adjacency linked list
 *
 * @graph: Pointer to the graph structure to be displayed
 */
void graph_display(graph_t const *graph);

#endif /* !_GRAPHS_H_ */
