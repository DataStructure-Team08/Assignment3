#include "minspantree.h"
#include "search.h"
#include <stdio.h>
#include <limits.h>

// Prim 알고리즘
void primMST(int graph[50][50], int numNodes) {
    int key[numNodes], parent[numNodes];
    bool included[numNodes];

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        included[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

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
}

// Kruskal 알고리즘
void kruskalMST(int graph[50][50], int numNodes, int numEdges, int edges[][3]) {
    printf("Kruskal's MST:\n");
    int mstWeight = 0, edgeCount = 0;
    bool included[numEdges];
    for (int i = 0; i < numEdges; i++) included[i] = false;

    while (edgeCount < numNodes - 1) {
        int minWeight = INT_MAX, minIndex = -1;

        for (int i = 0; i < numEdges; i++) {
            if (!included[i] && edges[i][2] < minWeight) {
                minWeight = edges[i][2];
                minIndex = i;
            }
        }

        if (minIndex == -1) break;

        included[minIndex] = true;
        int u = edges[minIndex][0];
        int v = edges[minIndex][1];
        int weight = edges[minIndex][2];

        graph[u][v] = weight;
        graph[v][u] = weight;

        if (isCyclicDFS(graph, numNodes)) {
            graph[u][v] = 0;
            graph[v][u] = 0;
        } else {
            printf("Edge: %d - %d, Weight: %d\n", u, v, weight);
            mstWeight += weight;
            edgeCount++;
        }
    }

    printf("Total Weight: %d\n", mstWeight);
}
