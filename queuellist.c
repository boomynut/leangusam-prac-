#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queuellist.h"

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue q = emalloc(sizeof * q);
    q->first = NULL;
    q->last = NULL;
    q->length = 0;
    return q;
}

void enqueue(queue q, double item) {
    q_item i = emalloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else {
        q->last->next = i;
    }
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    double item;
    q_item tmp;
    if (q->first == NULL){
        return 0;
    }
    item = q->first->item;
    tmp = q->first;
    q->first = q->first->next;
    q->length--;
    free(tmp);
    return(item);
}

static void queue_print_print(q_item node){
    if(node != NULL){
        printf("%.2f\n", node->item);
        queue_print_print(node->next);

    }
}

void queue_print(queue q) {
    /* print queue contents one per line to 2 decimal places */
    queue_print_print(q->first);
}



void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
               q->last->item, q->length);
    }
}

int queue_size(queue q) {
    return q->length;
}

void queue_free_aux(q_item node) {
    if(node != NULL){
        queue_free_aux(node->next);
        free(node);
    }
}

queue queue_free(queue q) {
    if (q == NULL) {
        return NULL;
    }
    queue_free_aux(q->first);
    free(q);
    return NULL;
}
