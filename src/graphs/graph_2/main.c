#include "graph.h"
#include "graph_algs.h"
#include <stdio.h>

#define MAX_NR_VERTICES 6

int main(void) {
    graph_t* g = graph_create(MAX_NR_VERTICES);
    graph_insert_edge(g, 1, 2, 2.5);
    graph_insert_edge(g, 1, 6, 3.0);
    graph_insert_edge(g, 2, 3, 1.5);
    graph_insert_edge(g, 2, 6, 2.0);
    graph_insert_edge(g, 3, 4, 4.0);
    graph_insert_edge(g, 3, 5, 1.0);
    graph_insert_edge(g, 4, 5, 5.0);
    graph_insert_edge(g, 5, 6, 0.5);
    graph_insert_edge(g, 5, 1, 5.5);
    graph_insert_edge(g, 6, 3, 6.5);
    /*graph_insert_edge(g, 1, 5, 2.1);
    graph_insert_edge(g, 1, 3, 2.2);
    graph_insert_edge(g, 2, 4, 1.5);
    graph_insert_edge(g, 3, 1, 3);
    graph_insert_edge(g, 4, 3, 5.2);
    graph_insert_edge(g, 3, 5, 3);
    graph_insert_edge(g, 6, 4, 2.2);
    graph_insert_edge(g, 4, 5, 1);
    graph_insert_edge(g, 5, 6, 1);*/
    graph_print(g);
    graph_print_degree_histogram(g);
    printf("After invert:\n");
    g = graph_invert(g);
    graph_print(g);

    printf("There is minimum %d vertices.\n", graph_min_degree(g));
    printf("There is maximum %d vertices.\n", graph_max_degree(g));
    printf("%.2lf is the average vertices.\n", graph_avg_degree(g));

    graph_print_degree_histogram(g);
    
    graph_free(g);
    return 0;
}
