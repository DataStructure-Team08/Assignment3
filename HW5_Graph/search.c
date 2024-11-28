#include "search.h"
#include <stdio.h>
#include <stdlib.h>

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

// DFS 기반 사이클 판별
bool isCyclicDFS(int** graph, int numNodes) {
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));

    bool hasCycle = false;
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicDFSUtil(graph, visited, i, -1, numNodes)) {
                hasCycle = true;
                break;
            }
        }
    }

    free(visited);
    return hasCycle;
}

bool isCyclicDFSUtil(int** graph, bool* visited, int current, int parent, int numNodes) {
    visited[current] = true;

    for (int i = 0; i < numNodes; i++) {
        if (graph[current][i]) {
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
