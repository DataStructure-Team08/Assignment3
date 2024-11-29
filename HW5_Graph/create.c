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

int** copyAdjacencyMatrix(int** graph, int numNodes) {
    int** copy = createAdjacencyMatrix(numNodes);
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            copy[i][j] = graph[i][j];
        }
    }
    return copy;
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

void separateGraph(int** graph, int numNodes) {
    int groupBoundary = numNodes / 2;

    for (int i = 0; i < groupBoundary; i++) {
        for (int j = groupBoundary; j < numNodes; j++) {
            graph[i][j] = 0;
            graph[j][i] = 0;
        }
    }
}
