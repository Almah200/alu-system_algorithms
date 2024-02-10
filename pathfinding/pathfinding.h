#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct pathfinding_queue {
    int x;  // Modify the fields accordingly
    int y;
} pathfinding_queue_t;

queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);

#endif
