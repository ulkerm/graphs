#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NR_VERTICES 6

struct graph {
    double value;
};

graph_t* graph_create(int n) {
    graph_t* g = malloc((n * n) * sizeof(double));
    if(g == NULL) {
        printf("Error out of memory");
        return NULL;
    };
    for (int i = 0; i < n * n; i++) {
		g[i].value = 0;
	};
    return g;
}

void graph_free(graph_t *g) {
    if(g == NULL) return;
    free(g);
    g = NULL;
}

void graph_insert_edge(graph_t *g, int source, int target, double weight) {
    source --;
    target--;
    if(g[source * MAX_NR_VERTICES + target].value == 0) {
        g[source * MAX_NR_VERTICES + target].value = weight;
    }
}

void graph_remove_edge(graph_t *g, int source, int target) {
    if(!graph_has_edge(g, source, target))     
        return;
    else {
        source --;
        target--;
        g[source * MAX_NR_VERTICES + target].value = 0;
    }
}

bool graph_has_edge(graph_t *g, int source, int target) {
    source --;
    target--;
    if(g[source * MAX_NR_VERTICES + target].value == 0)
        return false;
    return true;
}

double graph_get_weight(graph_t *g, int source, int target) {
    if(!graph_has_edge(g, source, target))     
        return 0;
    else {
        source --;
        target--;
        return g[source * MAX_NR_VERTICES + target].value;
    }        
}

void graph_print(graph_t *g) {
    printf("      ");
    for (int k = 0; k < MAX_NR_VERTICES; k++) 
        printf("%d    ", k + 1);
    printf("\n");
    printf("   -----------------------------\n");
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < MAX_NR_VERTICES; j++) {
		    printf("%.1lf  ", g[i * MAX_NR_VERTICES + j].value);
        };
        printf("\n");
	};
}

