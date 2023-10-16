#include "graph.h"
#include "graph_algs.h"
#include <stdio.h>

#define MAX_NR_VERTICES 6
#define MAX_DEGREE 11

struct graph {
    double value;
};

graph_t* graph_invert(graph_t *g) {
    graph_t* new_graph = graph_create(MAX_NR_VERTICES);
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        for (int j = 0; j < MAX_NR_VERTICES; j++) {
            if(g[i * MAX_NR_VERTICES + j].value != 0) {
                new_graph[j * MAX_NR_VERTICES + i].value = g[i * MAX_NR_VERTICES + j].value;
            }
        };
    };
    graph_free(g);
    return new_graph;
}

int graph_get_degree(graph_t *g, int input){
    int min = MAX_DEGREE; 
    int max = 0; 
    int return_value;
    int count;
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        for (int j = 0; j < MAX_NR_VERTICES; j++) {
            if((g[i * MAX_NR_VERTICES + j].value != 0) || (g[j * MAX_NR_VERTICES + i].value != 0)){
                count++;
            }
        }
        if(max <= count) {
            max = count;
        }
        if(min > count) {
            min = count;
        }
        count = 0;
    }
    if (input == 1) {
        return_value = min;
    } else 
        return_value = max;
    
    return return_value;
}

int graph_min_degree(graph_t *g){
    return graph_get_degree(g, 1);
}

int graph_max_degree(graph_t *g) {
    return graph_get_degree(g, 0);
}

double graph_avg_degree(graph_t *g) {
    double sum;
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        for (int j = 0; j < MAX_NR_VERTICES; j++) {
            if(g[i * MAX_NR_VERTICES + j].value != 0) {
                sum += g[i * MAX_NR_VERTICES + j].value;
            }
        }
    }
    return sum / MAX_NR_VERTICES;
}

void graph_print_degree_histogram(graph_t *g) {
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < MAX_NR_VERTICES; j++) {
            if((g[i * MAX_NR_VERTICES + j].value != 0) || (g[j * MAX_NR_VERTICES + i].value != 0))
		    printf("*");
        };
        printf("\n");
	}
}
