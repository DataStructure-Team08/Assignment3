#include "create.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 동적 메모리를 사용한 인접 행렬 생성
int** createAdjacencyMatrix(int numNodes) {
    int** graph = (int**)malloc(numNodes * sizeof(int*));
    for (int i = 0; i < numNodes; i++) {
        graph[i] = (int*)calloc(numNodes, sizeof(int)); // 0으로 초기화
    }
    return graph;
}

// 그래프 메모리 해제
void freeAdjacencyMatrix(int** graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        free(graph[i]);
    }
    free(graph);
}

// 랜덤 간선 추가
void addRandomEdges(int** graph, int numNodes, int numEdges) {
    srand(time(NULL));
    int edgeCount = 0;

    while (edgeCount < numEdges) {
        int u = rand() % numNodes;
        int v = rand() % numNodes;

        if (u != v && graph[u][v] == 0) { // 중복 간선 및 자기 자신 연결 방지
            int weight = rand() % 100 + 1; // 가중치: 1 ~ 100
            graph[u][v] = weight;
            graph[v][u] = weight; // 무방향 그래프
            edgeCount++;
        }
    }
}

// 그래프 출력
void printAdjacencyMatrix(int** graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}
