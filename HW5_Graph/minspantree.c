#include "create.h"
#include "search.h"
#include "minspantree.h"
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

void kruskalMST(int** graph, int numNodes) {
    typedef struct {
        int u, v, weight;
    } Edge;

    Edge* edges = (Edge*)malloc(numNodes * numNodes * sizeof(Edge));
    int edgeCount = 0;

    // 간선 리스트 생성
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (graph[i][j]) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // 간선 정렬 (가중치 오름차순)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("Kruskal's MST:\n");

    int mstWeight = 0;
    int selectedEdges = 0;
    int** mstGraph = createAdjacencyMatrix(numNodes); // MST를 별도로 관리

    // MST 구성
    for (int i = 0; i < edgeCount && selectedEdges < numNodes - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // MST 그래프에 간선을 임시 추가
        mstGraph[u][v] = weight;
        mstGraph[v][u] = weight;

        // 사이클 탐지
        if (isCyclicDFS(mstGraph, numNodes)) {
            // 사이클이 발생하면 간선을 제거
            mstGraph[u][v] = 0;
            mstGraph[v][u] = 0;
        } else {
            // 사이클이 없으면 간선을 MST에 포함
            printf("Edge: %d - %d, Weight: %d\n", u, v, weight);
            mstWeight += weight;
            selectedEdges++;
        }
    }

    printf("Total Weight: %d\n", mstWeight);

    freeAdjacencyMatrix(mstGraph, numNodes); // MST 그래프 메모리 해제
    free(edges);
}
