#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *erealloc(void *p, size_t s) {
    void *result = realloc(p, s);
    if (NULL == result) {
        fprintf(stderr, "memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof * result);
    result->capacity = 2;
    result-> itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity)  f->capacity += f->capacity;
    f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}
    
static void insertion_sort(int *a, int n) {
    int p, i, k, key;
    for (p = 1; p < n; p++){
        key = a[p];
        if (p*2 == n){
            for (k = 0; k < n; k++){
                fprintf(stderr, "%d\n", a[k]);
            }
        }
        for (i = p-1; i >= 0 && a[i] > key; i = i-1){
            a[i+1] = a[i];
        }
        a[i+1] = key;
    }
}
    
void flexarray_sort(flexarray f) {
    insertion_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}



