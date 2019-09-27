#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst_node { /* should live in bst.c */
    char *key;
    bst left;
    bst right;
};

int bst_search(bst b, char *str) {
    int compare;
    if (b == NULL){
        return 0;
    }

    compare = strcmp(b->key, str);
    if (compare == 0){
        return 1;
    }else if (compare > 0){
        return bst_search(b->left, str);
    }else {
        return bst_search(b->right, str);
    }
}

bst bst_insert(bst b, char *str){
    int compare;
    if (b == NULL){
        bst result = emalloc(sizeof *result);
        result->key = emalloc((strlen(str) + 1) * sizeof str[0]);
        result->left = NULL;
        result->right = NULL;
        strcpy(result->key, str);
        return result;
    } else {
        compare = strcmp(b->key, str);
        if (compare > 0){
            b->left = bst_insert(b->left, str);
        } else {
            b->right = bst_insert(b->right, str);
        }
    }
    return b;
}

bst bst_new(){
    return NULL;
}

void bst_inorder(bst b, void f(char *str)){
    if (b == NULL) return;
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *str)){
    if (b == NULL) return;
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

bst bst_free(bst b){
    if (b == NULL) return NULL;
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return NULL;
}
