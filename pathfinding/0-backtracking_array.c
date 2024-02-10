#include "pathfinding.h"
#include <stdlib.h>  

#include "pathfinding.h"
#include "queues.h"
#include <stdlib.h>


queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target) {
    queue_t *path = (queue_t *)malloc(sizeof(queue_t));
    path->front = path->rear = NULL;

    int **visited = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    if (backtrack(map, rows, cols, start->x, start->y, target, path, visited)) {
        return path;
    } else {
        free(path);
        return NULL;
    }
}

int backtrack(char **map, int rows, int cols, int row, int col, point_t const *target, queue_t *path, int **visited) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || map[row][col] == '1' || visited[row][col] == 1) {
        return 0;
    }

    visited[row][col] = 1;

    point_t current_point = {row, col};
    enqueue(path, current_point);

    if (row == target->x && col == target->y) {
        return 1;
    }

    if (backtrack(map, rows, cols, row, col + 1, target, path, visited) ||
        backtrack(map, rows, cols, row + 1, col, target, path, visited) ||
        backtrack(map, rows, cols, row, col - 1, target, path, visited) ||
        backtrack(map, rows, cols, row - 1, col, target, path, visited)) {
        return 1;
    }

    dequeue(path);
    return 0;
}
