/* graph-skel.c */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "mylib.h"
/*
#include "queue.h"
*/
typedef enum state {UNVISITED, VISITED_SELF, VISITED_DESCENDENTS} state_t;

struct graphrec {
    int num_vertices;
    int size;
    int *vertex;
    int **matrix;
};

graph graph_new(int num_vertices) {
    int i;
    graph result = emalloc(sizeof * result);
    result->size = 4;
    result->vertex = emalloc(sizeof(result->vertex[0]) * num_vertices);
    result->matrix = emalloc(sizeof(result->matrix[0]) * num_vertices);
    for (i = 0; i < num_vertices; i++){
        result->matrix[i] = 0;
        result->vertex[i] = 0;
    }
    return result;
}

graph graph_free(graph g) {
    int i;
    for(i = 0; i < g->num_vertices; i++;){
        free(g->matrix[i]);
    }
    free(g->vertex);
    free(g->matrix);
    free(g);
}

void graph_add_2edges(graph g, int u, int v) { }

void graph_add_edge(graph g, int u, int v) { }

void graph_print_list(graph g) { }

void graph_print_state(graph g) { }

/* either */
void graph_bfs(graph g, int source) { }
