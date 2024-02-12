#include <stdlib.h>

typedef struct node {
    void *data;
} node_t;

typedef struct heap {
    node_t *root;
    size_t size;
    int (*data_cmp)(void *, void *);
} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *)) {
    heap_t *new_heap = malloc(sizeof(heap_t));

    if (new_heap == NULL) {
       
        return NULL;
    }

    new_heap->root = NULL;
    new_heap->size = 0;
    new_heap->data_cmp = data_cmp;

    return new_heap;
}

int int_cmp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    heap_t *my_heap = heap_create(int_cmp);

    if (my_heap == NULL) {
        return EXIT_FAILURE;
    }

    free(my_heap);

    return EXIT_SUCCESS;
}
