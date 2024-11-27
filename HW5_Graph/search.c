#include "search.h"
#include <stdio.h>

// BFS 구현
void bfs(int graph[50][50], int numNodes, int start) {
    bool visited[numNodes];
    for (int i = 0; i < numNodes; i++) visited[i] = false;

    int queue[50], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    printf("BFS: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < numNodes; i++) {
            if (graph[curr][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// DFS 구현
void dfs(int graph[50][50], int numNodes, int start, bool visited[]) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < numNodes; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(graph, numNodes, i, visited);
        }
    }
}

// Connected Components 탐색
void findConnectedComponents(int graph[50][50], int numNodes) {
    bool visited[50] = {false};
    int component = 0;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            printf("Component %d: ", ++component);
            dfs(graph, numNodes, i, visited);
            printf("\n");
        }
    }
}

// DFS를 이용한 사이클 판별
bool isCyclicDFSUtil(int graph[50][50], bool visited[], int curr, int parent, int numNodes) {
    visited[curr] = true;

    for (int i = 0; i < numNodes; i++) {
        if (graph[curr][i]) {
            if (!visited[i]) {
                if (isCyclicDFSUtil(graph, visited, i, curr, numNodes)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int graph[50][50], int numNodes) {
    bool visited[50] = {false};

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicDFSUtil(graph, visited, i, -1, numNodes)) {
                return true;
            }
        }
    }
    return false;
}
