#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"

typedef struct point {
    int x;
    int y;
} point_t;

// Forward declaration of queue_t with its complete structure to break the circular dependency
typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

// Function prototypes
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);

#endif /* PATHFINDING_H */
