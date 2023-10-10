#include <stdio.h>
#include  "graph.h"

#define MAX_NR_VERTICES 6

int main(void) {
    graph_t* g = graph_create(MAX_NR_VERTICES);
    graph_insert_edge(g, 1, 5, 2.1);
    graph_insert_edge(g, 1, 3, 2.2);
    graph_insert_edge(g, 2, 4, 1.5);
    graph_insert_edge(g, 3, 1, 3);
    graph_insert_edge(g, 4, 3, 5.2);
    graph_insert_edge(g, 3, 5, 3);
    graph_insert_edge(g, 6, 4, 2.2);
    graph_insert_edge(g, 4, 5, 1);
    graph_insert_edge(g, 5, 6, 1);
    graph_print(g);
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 1, 6, graph_get_weight(g, 1, 6));
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 3, 4, graph_get_weight(g, 3, 4));
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 5, 6, graph_get_weight(g, 5, 6));
    printf("\n");
    graph_remove_edge(g, 4, 5);
    graph_remove_edge(g, 2, 4);
    graph_remove_edge(g, 1, 3);
    printf("After removing edge:\n");
    graph_print(g);

    printf("Graph has edge: %d\n", graph_has_edge(g, 1, 5));
    printf("Graph has edge: %d\n", graph_has_edge(g, 4, 2));
    printf("Graph has edge: %d\n", graph_has_edge(g, 4, 5));
    printf("Graph has edge: %d\n", graph_has_edge(g, 5, 6));

    graph_free(g);
    return 0;
}
