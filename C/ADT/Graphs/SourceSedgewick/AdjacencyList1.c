// Source: Sedgewick/Algorithms in C/Program 17.6

#include <stdlib.h>
#include "GRAPH.h"

typdef struct node* link;
struct node { int v; link next; };
struct graph { int V; int E; link *adj; };
link NEW (int v, link next) {
    link x = malloc(sizeof *x);
    x->v = v; 
    x->next = next;
    return x;
}

Graph GRAPHinit(int V) {
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0; G->adj = malloc(V * sizeof(link));
    for (v = 0; v<V; v++) G->adj[v] = NULL;
    return G;
}

void GRAPHinsertE (Graph G, Edge e) {
    int v = e.v, w = e.w;
    G->adj[v] = NEW(w, G->adj[v]);
    G->adj[w] = NEW(v, G->adj[w]);
    G->E++;
}

int GRAPHedges (Edge a[], Graph G) {
    int v, E = 0;
    link t;
    for (v = 0; v < G->V; v++)
        for (t = G->adj[v]; t != NULL; t = t->next)
            if (v < t->v) a[E++] = EDGE(v, t->v);
    return E;
}

void main(void) {
    printf("Hello\n");
}
