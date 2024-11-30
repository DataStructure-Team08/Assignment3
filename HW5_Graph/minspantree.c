#include "create.h"
#include "search.h"
#include "minspantree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** primMST(int** graph, int numNodes) {
    int* key = (int*)malloc(numNodes * sizeof(int));
    int* parent = (int*)malloc(numNodes * sizeof(int));
    bool* included = (bool*)calloc(numNodes, sizeof(bool));
    int** mstGraph = createAdjacencyMatrix(numNodes); // MST를 저장할 그래프

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
        mstGraph[i][parent[i]] = graph[i][parent[i]];
        mstGraph[parent[i]][i] = graph[parent[i]][i];
        printf("Edge: %d - %d, Weight: %d\n", i, parent[i], graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight: %d\n", totalWeight);

    free(key);
    free(parent);
    free(included);
    return mstGraph; // 생성된 MST 반환
}

int** kruskalMST(int** graph, int numNodes) {
    typedef struct {
        int u, v, weight;
    } Edge;

    Edge* edges = (Edge*)malloc(numNodes * numNodes * sizeof(Edge));
    int edgeCount = 0;

    // 간선 리스트 생성
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (graph[i][j]) {
                edges[edgeCount++] = (Edge){i, j, graph[i][j]};
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

    int** mstGraph = createAdjacencyMatrix(numNodes);
    int mstWeight = 0;
    int selectedEdges = 0;

    printf("Kruskal's MST:\n");

    for (int i = 0; i < edgeCount && selectedEdges < numNodes - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        mstGraph[u][v] = weight;
        mstGraph[v][u] = weight;

        if (isCyclicDFS(mstGraph, numNodes)) {
            mstGraph[u][v] = 0;
            mstGraph[v][u] = 0;
        } else {
            printf("Edge: %d - %d, Weight: %d\n", u, v, weight);
            mstWeight += weight;
            selectedEdges++;
        }
    }

    printf("Total Weight: %d\n", mstWeight);

    free(edges);
    return mstGraph; // 생성된 MST 반환
}

bool isSpanningTree(int** graph, int numNodes) {
    // 연결 성분 확인
    int* components = findConnectedComponents(graph, numNodes);
    int firstComponent = components[0];
    for (int i = 1; i < numNodes; i++) {
        if (components[i] != firstComponent) {
            free(components);
            return false; // 연결되지 않은 노드 존재
        }
    }
    free(components);

    // 간선 수 확인
    int edgeCount = 0;
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (graph[i][j] > 0) {
                edgeCount++;
            }
        }
    }
    if (edgeCount != numNodes - 1) {
        return false; // 간선 수가 올바르지 않음
    }

    // 사이클 검사
    if (isCyclicDFS(graph, numNodes)) {
        return false; // 사이클 존재
    }

    return true; // 연결되고 간선 수가 정확하며 사이클 없음
}
