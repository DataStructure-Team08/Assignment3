#include "create.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createAdjacencyMatrix(int numNodes) {
    int** matrix = (int**)malloc(numNodes * sizeof(int*));
    for (int i = 0; i < numNodes; i++) {
        matrix[i] = (int*)calloc(numNodes, sizeof(int));
    }
    return matrix;
}

void addRandomEdges(int** graph, int numNodes, int numEdges) {
    srand(time(NULL));
    int edgeCount = 0;

    while (edgeCount < numEdges) {
        int u = rand() % numNodes;
        int v = rand() % numNodes;

        if (u != v && graph[u][v] == 0) { // Avoid self-loops and duplicate edges
            int weight = rand() % 100 + 1; // Weights between 1 and 100
            graph[u][v] = weight;
            graph[v][u] = weight; // Undirected graph
            edgeCount++;
        }
    }
}

void copyGraph(int** source, int** destination, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

void printAdjacencyMatrix(int** graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}

void freeAdjacencyMatrix(int** graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        free(graph[i]);
    }
    free(graph);
}
