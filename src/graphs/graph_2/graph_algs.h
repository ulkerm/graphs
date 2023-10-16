#pragma once
#include "graph.h"

graph_t* graph_invert(graph_t *g);

int graph_min_degree(graph_t *g);
int graph_max_degree(graph_t *g);
double graph_avg_degree(graph_t *g);

void graph_print_degree_histogram(graph_t *g);
