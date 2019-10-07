#include <stdio.h>
#include <stdlib.h>

void repeated(int *my_array, int array_size){
    int i, j;
    int *tempArray = malloc(sizeof tempArray[0] * array_size);
    for (i = 0; i < array_size; i++){
        tempArray[i] = 0;
    }

    for (i = 0; i < array_size; i++){
        j = my_array[i];
        tempArray[j]++;
    }
   
    for (i = 0; i < array_size; i++){
        if (tempArray[i] > 1)
            printf("\n%d occurs %d times", i, tempArray[i]);
    }
    free(tempArray);
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
   
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
   
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
   
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    repeated(my_array, array_size);
    
    printf("\n");
    free(my_array);
    return EXIT_SUCCESS;
}
