#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;


typedef struct GraphRep {
    int nV;
    int nE;
    struct Node **edges; // array of linked list
} GraphRep;

typedef Node   *LinkedList;
typedef GraphRep *Graph;

/* Linked List */
LinkedList makeNode(int vertex) {
    LinkedList newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->next = NULL;
    newNode->vertex = vertex;
    return newNode;
}

LinkedList insertNode(LinkedList list, int vertex) {
    if (list == NULL) return makeNode(vertex);
    LinkedList newNode = makeNode(vertex);
    newNode->next = list;
    return newNode;
}

void showLL(LinkedList list) {
    LinkedList current_node = list;
    while (current_node != NULL) {
        printf("%d, ", current_node->vertex);
        current_node = current_node->next;
    }
}

bool inLL(LinkedList list, int vertex) {
    LinkedList current_node = list;
    while (current_node != NULL) {
        if  (current_node->vertex == vertex) return true;
        current_node = current_node->next;
    }
    return false;
}

/* Graph */

Graph makeGraph() {
    Graph newGraph = malloc(sizeof(GraphRep));
    assert(newGraph != NULL);
    newGraph->edges = NULL; 
    newGraph->nV = newGraph->nE = 0;
    return newGraph;
}

bool existV(Graph graph, int vertex) {
    if (graph->edges == NULL || (vertex > (graph->nV))) return false;
    else return true;
}

Graph newVertex(Graph graph, int vertex) {
    LinkedList *temp = realloc(graph->edges, (vertex+1) * sizeof(LinkedList)); 
    assert(temp != NULL);
    graph->edges = temp;
    graph->nV++;
    return graph;
}

Graph insertEdge(Graph graph, int vertex1, int vertex2) {
    if (existV(graph, vertex1) && validV(graph, vertex2)) {
        if (!inLL(graph->edges[vertex1], vertex2)) {
            graph->edges[vertex1] = insertNode(graph->edges[vertex1], vertex2);
            graph->edges[vertex2] = insertNode(graph->edges[vertex2], vertex1);
            graph->nE++;
        }

    }  else {

        // encountering new vertex
        if (!existV(graph, vertex1))
            printf("Vertex 1 not exists\n");
            if (vertex1 > graph->nV)
                graph = newVertex(graph, vertex1);  

        if (!existV(graph, vertex2))
            printf("Vertex 2 not exists\n");
            if (vertex2 > graph->nV)
                graph = newVertex(graph, vertex2);  

        if (vertex1 == vertex2) {
            graph->edges[vertex2] = insertNode(graph->edges[vertex2], vertex1);
            graph->nE++; 
        } else {
            graph->edges[vertex1] = insertNode(graph->edges[vertex1], vertex2);
            graph->edges[vertex2] = insertNode(graph->edges[vertex2], vertex1);
            graph->nE++;
        }
    }
    return graph;
}

void displayGraph(Graph graph) {
    printf("%d %d\n", graph->nV, graph->nE);
    printf("Next empty index is %d\n", graph->nV+1);
    for (int i = 1; i < (graph->nV + 1); i++) {
        printf("%d: ", i);
        showLL(graph->edges[i]);
        printf("\n");
    } 
    printf("\n");
}

void main() {
    char *aStr;
    int vertex1, vertex2;
    Graph aGraph = makeGraph();

    printf("Index 0 is not used for convenient\n");
    while (scanf("%s %d %d", aStr, &vertex1, &vertex2) != EOF) {
        if (strcmp(aStr, "insert") == 0) {
            aGraph = insertEdge(aGraph, vertex1, vertex2);            
            displayGraph(aGraph);
        }
    }
}
