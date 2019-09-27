#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char **key;
};

htable htable_new(int capacity){
    int i;
    htable result = emalloc(sizeof * result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->key = emalloc(sizeof(result->key[0]) * capacity);
    for (i = 0; i < capacity; i++){
        result -> key[i] = NULL;
    }
    return result;
}

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

int htable_insert(htable h, char *str){
    unsigned int index;
    int count;

    index = htable_word_to_int(str) % h->capacity;

    count = 0;
    while(count < h->capacity){
        if (h->key[index] == NULL){
            h->key[index] = emalloc((strlen(str) + 1) * sizeof h->key[0][0]);
            strcpy(h->key[index], str);
            h->num_keys++;
            return 1;
        } else if (strcmp(h->key[index], str) == 0){
            count++;
        } else {
            index = index + 1;
            if((int)index == h->capacity){
                index = 0;
            }
            count++;
        }
    }
    return 0;
}


void htable_print(htable h, FILE *stream){
    int i;
    for(i = 0; i < h->capacity; i++ ){
        fprintf(stream, "%2d %s\n", i, h->key[i] == NULL ? "" : h->key[i]);
        }
    }

void htable_free(htable h){
    int i;
    for(i = 0; i < h->capacity; i++){
        free(h->key[i]);
    }
    free(h->key);
    free(h);
}
