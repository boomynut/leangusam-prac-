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
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
    }
    f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}
    
void selection_sort(int *a, int n) {
    int i, j, k;
    int smallestIndex;
    int smallestValue;
    int temp;
    /*This for loop goes through the array to sort */
    for (i = 0; i < n-1; i++){
        smallestIndex = i;
        smallestValue = a[i];
        
        if (i*2 == n){
            for (k = 0; k < n; k++){
                fprintf(stderr, "%d\n", a[k]);
            }
        }
        /*This for loop goes throuh the array and finds the smallest value
          and swaps it with the value in the first for loop*/
        for (j = i+1; j < n; j++){
            if (a[j] < smallestValue){
                smallestValue = a[j];
                smallestIndex = j;
            }
        }
        /*The swap code to switch the two values in the array*/
        temp = a[i];
        a[i] = a[smallestIndex];
        a[smallestIndex] = temp;
    }
}
    
void flexarray_sort(flexarray f) {
    selection_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}



