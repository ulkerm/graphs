#pragma once

#include <stdbool.h>

struct graph;
typedef struct graph graph_t;

graph_t* graph_create(int n);
void graph_free(graph_t *g);

void graph_insert_edge(graph_t *g, int source, int target, double weight);
void graph_remove_edge(graph_t *g, int source, int target);

bool graph_has_edge(graph_t *g, int source, int target);
double graph_get_weight(graph_t *g, int source, int target);

void graph_print(graph_t *g);
