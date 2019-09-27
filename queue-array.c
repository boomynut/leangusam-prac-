#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    int i;
    int default_size = 7;
    queue q = emalloc(sizeof *q);
    q->items = emalloc(sizeof q->items[0] * default_size);
    for (i = 0; i < default_size; i++) {
        q->items[i] = 0;
    }
    q->head = 0;
    q->capacity = default_size;
    q->num_items = 0;
    return q;
}

void enqueue(queue q, double item) {
    if (q->num_items < q->capacity) {
        q->items[(q->head + q->num_items++) % q->capacity] = item;
    }
}

double dequeue(queue q) {
    double result;
    if (q->num_items > 0){
        result = q->items[q->head];
        q->head = (q->head + 1) % q->capacity;
        q->num_items--;
        return result;
    } else {
        exit(EXIT_FAILURE);
    }
}

void queue_print(queue q) {
    int i = 0;
    for(i = 0; i < q->num_items; i++){
        printf("%.2f\n", q->items[(i+q->head) % q->capacity]);
    }
}



void queue_print_info(queue q) {
    int i = 0;
    printf("capacity %d, num_items %d, head %d\n[", q->capacity,
      q->num_items, q->head); 
    for (i = 0; i < q->capacity; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return NULL;
}
