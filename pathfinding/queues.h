#ifndef QUEUES_H
#define QUEUES_H

// Forward declaration of point_t to break the circular dependency
typedef struct point point_t;

typedef struct queue_node {
    point_t *point;
    struct queue_node *next;
} queue_node_t;

typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

// Function prototypes
queue_t *create_queue();
void enqueue(queue_t *queue, point_t *point);
point_t *dequeue(queue_t *queue);
int is_empty(queue_t *queue);

#endif /* QUEUES_H */
