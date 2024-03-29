#include <stdio.h>
#include <stdlib.h>

int is_prime (int candidate) {
    int i;
    for(i = 2; i < candidate; i++)  {
        if (candidate % i == 0) return 0;
    }
    return 1;
}
    
int main(void) {
    int candidate = 2;
    int num_printed = 1; 
    while (num_printed < 201) {
        if (is_prime(candidate)) {
            if (num_printed % 10 != 0){
                printf("%5d", candidate);
                num_printed++;
            } else {
                printf("%5d\n", candidate);
                num_printed++;
            }
        }
        candidate++;
    }
    return 0;
}
