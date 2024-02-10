#ifndef QUEUES_H
#define QUEUES_H

#include <stddef.h>

typedef struct queue_t {
    void *ptr;
    struct queue_t *next;
} queue_node_t;


typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;


void *dequeue(queue_t *queue);

#endif
