#include "minspantree.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Prim 알고리즘 구현
void primMST(int** graph, int numNodes) {
    int* key = (int*)malloc(numNodes * sizeof(int));
    int* parent = (int*)malloc(numNodes * sizeof(int));
    bool* included = (bool*)calloc(numNodes, sizeof(bool));

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
        included[u] = true;

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
void kruskalMST(int** graph, int numNodes) {
    printf("Kruskal's MST (Using Adjacency Matrix):\n");

    int mstWeight = 0;
    int edgeCount = 0;

    while (edgeCount < numNodes - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < numNodes; i++) {
            for (int j = i + 1; j < numNodes; j++) {
                if (graph[i][j] && graph[i][j] < minWeight) {
                    minWeight = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1) break;

        int weight = graph[u][v];
        graph[u][v] = graph[v][u] = 0;

        if (isCyclicDFS(graph, numNodes)) {
            graph[u][v] = graph[v][u] = weight;
        } else {
            printf("Edge: %d - %d, Weight: %d\n", u, v, weight);
            mstWeight += weight;
            edgeCount++;
        }
    }

    printf("Total Weight: %d\n", mstWeight);
}
