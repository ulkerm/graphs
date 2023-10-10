#include <stdio.h>
#include  "graph.h"

#define MAX_NR_VERTICES 6

int main(void) {
    graph_t* g = graph_create(MAX_NR_VERTICES);
    graph_insert_edge(g, 2, 1, 3.3);
    graph_insert_edge(g, 1, 3, 2.2);
    graph_insert_edge(g, 2, 2, 1);
    graph_insert_edge(g, 3, 1, 3);
    graph_insert_edge(g, 4, 6, 5.2);
    graph_insert_edge(g, 1, 6, 3);
    graph_insert_edge(g, 6, 6, 2.2);
    graph_insert_edge(g, 4, 3, 3.1);  
    graph_insert_edge(g, 5, 1, 1);
    graph_print(g);
    
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 2, 1, graph_get_weight(g, 2, 1));
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 2, 2, graph_get_weight(g, 2, 2));
    printf("The weight of graph between %d edge and %d edge is %.1lf.\n", 5, 1, graph_get_weight(g, 5, 1));
    
    printf("\n");
    graph_remove_edge(g, 5, 1);
    graph_remove_edge(g, 3, 1);
    graph_remove_edge(g, 2, 2);
    printf("After removing edge:\n");
    graph_print(g);

    printf("Graph has edge: %d\n", graph_has_edge(g, 2, 2));
    printf("Graph has edge: %d\n", graph_has_edge(g, 5, 1));
    printf("Graph has edge: %d\n", graph_has_edge(g, 4, 6));
    printf("Graph has edge: %d\n", graph_has_edge(g, 4, 3));
    
    graph_free(g);
    return 0;
}
