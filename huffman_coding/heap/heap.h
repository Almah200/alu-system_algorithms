// heap/heap.h
#ifndef _HEAP_H_
#define _HEAP_H_

#include <stddef.h>

typedef struct {
    // Your heap structure members here
    size_t size;
    // Assume a member named 'root' is part of your heap structure
    // You might need to adjust this based on your actual structure
    void *root;
} heap_t;

// Function declarations
heap_t *heap_create();
// ...

#endif /* _HEAP_H_ */