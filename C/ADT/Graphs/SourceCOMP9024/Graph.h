// Source: COMP9024

#include <stdbool.h>

// vertices denoted by integers 0..N-1
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge { Vertex v; Vertex w; } Edge;

typedef struct Node {
    Vertex v;
    struct Node *next;
} Node;

typedef struct GraphRep {
    Node **edges;
    int nV;
    int nE;
} GraphRep;

// graph representation is hidden
typedef struct GraphRep *Graph;

// operations on graphs
Node *makeNode(int);
Node *insertLL(Node *, int);
Node *deleteHead(Node *);
Node *deleteLL(Node *, int);
int inLL(Node *, int);
void showLL(Node *);
void freeLL(Node *);
Graph newGraph(int); // new graph with V Vertices
bool validV(Graph, Vertex);
void insertEdge(Graph, Edge);
void removeEdge(Graph, Edge);
bool adjacent(Graph, Vertex, Vertex); // is there an edge between two vertices
void displayGraph(Graph);
void freeGraph(Graph);


