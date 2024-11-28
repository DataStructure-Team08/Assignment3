#include "search.h"
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

// BFS 구현
void bfs(int** graph, int numNodes, int start) {
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    int* queue = (int*)malloc(numNodes * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < numNodes; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");

    free(queue);
    free(visited);
}

// DFS 구현
void dfs(int** graph, int numNodes, int start, bool* visited) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < numNodes; i++) {
        if (graph[start][i] != 0 && !visited[i]) {
            dfs(graph, numNodes, i, visited);
        }
    }
}

// 연결 성분 탐색
void findConnectedComponents(int** graph, int numNodes) {
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    int componentCount = 0;

    printf("Connected Components:\n");
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            printf("Component %d: ", ++componentCount);
            dfs(graph, numNodes, i, visited);
            printf("\n");
        }
    }

    free(visited);
}

// DFS 유틸리티 함수 (사이클 판별)
bool isCyclicDFSUtil(int** graph, bool* visited, int current, int parent, int numNodes) {
    visited[current] = true;

    for (int i = 0; i < numNodes; i++) {
        if (graph[current][i] != 0) {
            if (!visited[i]) {
                if (isCyclicDFSUtil(graph, visited, i, current, numNodes)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

// DFS 기반 사이클 판별
bool isCyclicDFS(int** graph, int numNodes) {
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicDFSUtil(graph, visited, i, -1, numNodes)) {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}
