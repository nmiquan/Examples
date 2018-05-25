#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


typedef struct Matrix {
    int nV;
    int nE;
    bool **edges;
} Matrix;

typedef Matrix *Graph;

Graph makeGraph() {
    Graph newGraph = malloc(sizeof(Matrix));
    newGraph->nV = newGraph->nE = 0;
    newGraph->edges = NULL;
    return newGraph;
}

bool existV(Graph graph, int vertex) {
    if ((graph->edges == NULL) || (vertex > graph->nV)) return false;
    else return true;
}


Graph insertEdge(Graph graph, int vertex1, int vertex2) {
    // check to see if each vertex is in the graph
    if (existV(graph, vertex1) && existV(graph, vertex2)) {
        graph->edges[vertex1][vertex2] = 1;
        graph->edges[vertex2][vertex1] = 1;
        graph->nE++;
    } else {
        if (!existV(graph, vertex1)) {
            graph->nV++;
            bool **temp1 = realloc(graph->edges, (vertex1+1)*(sizeof(bool *)));
            assert(temp1 != NULL);
            graph->edges = temp1; 
            for (int i = 0; i < graph->nV+1; i++) {
                bool *temp2 = realloc(graph->edges[i], (graph->nV+1) * sizeof(bool)); 
                assert(temp2 != NULL);
                graph->edges[i] = temp2;
                graph->edges[i][graph->nV] = false;
            }

            //graph->edges[graph->nV][0] = graph->nV;
            //graph->edges[0][graph->nV] = graph->nV;
        }

        if (!existV(graph, vertex2)) {
            graph->nV++;
            bool **temp1 = realloc(graph->edges, (vertex2+1)*(sizeof(bool *)));
            assert(temp1 != NULL);
            graph->edges = temp1; 
            for (int i = 0; i < graph->nV+1; i++) {
                bool *temp2 = realloc(graph->edges[i], (graph->nV+1) * sizeof(bool)); 
                assert(temp2 != NULL);
                graph->edges[i] = temp2;
                graph->edges[i][graph->nV] = false;
            }
            //graph->edges[graph->nV][0] = graph->nV;
            //graph->edges[0][graph->nV] = graph->nV;
        }
        (graph->edges[vertex1])[vertex2] = 1;
        (graph->edges[vertex2])[vertex1] = 1;
        graph->nE++;
    }
    return graph;
}

void displayGraph(Graph graph) {
    printf("%d %d\n", graph->nV, graph->nE);
    printf("Next available index is %d\n", graph->nV+1);

    for (int i = 1; i < graph->nV+1; i++) {
        for (int j = 1; j < graph->nV+1; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void main() {
    char *aStr;
    int vertex1, vertex2;
    Graph aGraph = makeGraph();
    while (scanf("%s %d %d", aStr, &vertex1, &vertex2) != EOF) {
        if (strcmp(aStr, "insert") == 0) {
            aGraph = insertEdge(aGraph, vertex1, vertex2);
            displayGraph(aGraph);
        }
    } 
}
