#include "minspantree.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Prim 알고리즘 구현
void primMST(int** graph, int numNodes) {
    int* key = (int*)malloc(numNodes * sizeof(int));
    int* parent = (int*)malloc(numNodes * sizeof(int));
    int* included = (int*)calloc(numNodes, sizeof(int));

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = -1, minKey = INT_MAX;
        for (int i = 0; i < numNodes; i++) {
            if (!included[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        included[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Prim's MST:\n");
    int totalWeight = 0;
    for (int i = 1; i < numNodes; i++) {
        printf("Edge: %d - %d, Weight: %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight: %d\n", totalWeight);

    free(key);
    free(parent);
    free(included);
}

// Kruskal 알고리즘 구현
void kruskalMST(int** graph, int numNodes, int numEdges, int edges[][3]) {
    printf("Kruskal's MST:\n");
    int* included = (int*)calloc(numEdges, sizeof(int));
    int mstWeight = 0, edgeCount = 0;

    while (edgeCount < numNodes - 1) {
        int minWeight = INT_MAX, minIndex = -1;
        for (int i = 0; i < numEdges; i++) {
            if (!included[i] && edges[i][2] < minWeight) {
                minWeight = edges[i][2];
                minIndex = i;
            }
        }
        if (minIndex == -1) break;

        included[minIndex] = 1;
        int u = edges[minIndex][0];
        int v = edges[minIndex][1];

        graph[u][v] = edges[minIndex][2];
        graph[v][u] = edges[minIndex][2];

        if (isCyclicDFS(graph, numNodes)) {
            graph[u][v] = 0;
            graph[v][u] = 0;
        } else {
            printf("Edge: %d - %d, Weight: %d\n", u, v, edges[minIndex][2]);
            mstWeight += edges[minIndex][2];
            edgeCount++;
        }
    }

    printf("Total Weight: %d\n", mstWeight);
    free(included);
}
