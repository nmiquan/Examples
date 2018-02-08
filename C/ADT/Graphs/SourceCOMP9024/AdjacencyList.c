// Source: COMP9024
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

Node *makeNode(int vertex) {
    Node *newNode;
    newNode = malloc(sizeof(Node *));
    newNode->v = vertex;
    newNode->next = NULL;
}

Node *insertLL(Node *edges, int vertex) {
    Node *newNode = makeNode(vertex); 
    newNode->next = edges;
    return newNode;
}

Node *deleteHead(Node *edges) {
    assert(edges != NULL);
    Node *head = edges;
    edges = edges->next;
    free(head);
    return edges;
}

Node *deleteLL(Node *edges, int vertex) {
    if (edges == NULL) {
        return edges;
    } else if (edges->v == vertex) {
        return deleteHead(edges);
    } else {
        edges->next = deleteLL(edges->next, vertex);
        return edges;
    }
}

int inLL(Node *edges, int vertex) {
    Node *current_node;
    current_node = edges; 
    while (current_node != NULL) {
        if (current_node->v == vertex) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

void showLL(Node *edges) {
    Node *current_node;
    current_node = edges;
    while (current_node->next != NULL) {
        printf("%d->", current_node->v);
        current_node = current_node->next;
    }
    printf("%d", current_node->v);
}

void freeLL(Node *edges) {
    Node *current_node;
    
    current_node = edges->next;
    while (current_node != NULL) {
        free(edges);
        edges = current_node;
        current_node = edges->next; 
    }
}

Graph newGraph(int V) {
    assert(V >= 0);
    int i;
    
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for array of lists
    g->edges = malloc(V * sizeof(Node *));
    assert(g->edges != NULL);
    for (i = 0; i < V; i++)
        g->edges[i] = NULL;
    return g;
}

bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV); 
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (!inLL(g->edges[e.v], e.w)) { // edge e not in graph
        g->edges[e.v] = insertLL(g->edges[e.v], e.w);
        g->edges[e.w] = insertLL(g->edges[e.w], e.v);
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL & validV(g, e.v) && validV(g, e.w));

    if (inLL(g->edges[e.v], e.w)) { // edge e in graph
        g->edges[e.v] = deleteLL(g->edges[e.v], e.w);
        g->edges[e.w] = deleteLL(g->edges[e.w], e.v);
        g->nE--;
    }
}

bool adjacent(Graph g, Vertex x, Vertex y) {
    assert(g != NULL && validV(g, x));
    return inLL(g->edges[x], y);
}

void displayGraph(Graph g) {
    for (int i = 0; i < g->nV; i++) {
        printf("%d ", i);
        showLL(g->edges[i]);
        printf("\n");
    }
}

void freeGraph(Graph g) {
    for (int i = 0; i < g->nV; i++) {
        freeLL(g->edges[i]);        
    }
}
