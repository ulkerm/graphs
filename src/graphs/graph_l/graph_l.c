#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_NR_VERTICES 6

struct graph {
    int v;
    double w;
    struct graph* next;
};

graph_t* graph_create(int n) {
    graph_t* g = malloc(n * sizeof(graph_t));
    if(g == NULL) {
        printf("Error out of memory");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        g[i].v = 0;
        g[i].w = 0;
        g[i].next = NULL;
	}
    return g;
}

void graph_free(graph_t *g){
    if(g == NULL) return;
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        free(g->next);
        free(g[i].next);
    }    
        free(g);
    g = NULL;
}

void graph_insert_edge(graph_t *g, int source, int target, double weight) {    
    if(g[source-1].v == 0) {
        g[source-1].v = target;
        g[source-1].w = weight; 
    } else {
        graph_t* new_node = malloc(sizeof(graph_t));
        new_node->v = target;
        new_node->w = weight;
        new_node->next = g[source-1].next;
        g[source-1].next = new_node;        
    }    
}

void graph_remove_edge(graph_t *g, int source, int target) {
    if(!graph_has_edge(g, source, target)) {
        return;
    } else {
        if(g[source - 1].v == target) {
            g[source - 1].v = 0;
            g[source - 1].w = 0.0;
            g[source - 1].next = NULL;
        } else {
            graph_t* current = &g[source-1];
            graph_t* new_node = g[source-1].next;
            while(new_node->v != target) {
                current = new_node;
                assert(new_node != NULL);
                new_node = new_node->next;
            }
            current->next = new_node->next;
            free(new_node);
        }
    }
}

bool graph_has_edge(graph_t *g, int source, int target) {
    if(g[source - 1].v == 0)     
        return false;
    else {
        if(g[source - 1].v == target) {
            return true;
        } else {
            graph_t* new_node = g[source - 1].next;
            while (new_node != NULL) {
                if(new_node->v == target) {
                    return true;
                    break;
                }
                new_node = new_node->next;
            }
        }
    }
    return false;
} 

double graph_get_weight(graph_t *g, int source, int target) {
    if(!graph_has_edge(g, source, target))     
        return 0;
    else {
        if(g[source - 1].v == target) 
            return g[source - 1].w;
        else {
            graph_t* new_node = g[source - 1].next;
            while (new_node != NULL) {
                if(new_node->v == target) {
                    return new_node->w;
                    break;
                }
                new_node = new_node->next;
            }
            return 0;
        }
    }
} 

void graph_print(graph_t *g){
    for (int i = 0; i < MAX_NR_VERTICES; i++) {
        printf("%d -> %d -> %.1lf", i + 1, g[i].v, g[i].w);
        graph_t* new_node = g[i].next;
        while (new_node != NULL) {
            printf("-> %d -> %.1lf",new_node->v, new_node->w);
            new_node = new_node->next;
        }
        printf("\n");  
    }    
}
