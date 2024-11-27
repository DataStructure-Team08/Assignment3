#ifndef SEARCH_H
#define SEARCH_H

#include <stdbool.h>

// BFS 함수 선언
void bfs(int graph[50][50], int numNodes, int start);

// DFS 함수 선언
void dfs(int graph[50][50], int numNodes, int start, bool visited[]);

// Connected Components 함수 선언
void findConnectedComponents(int graph[50][50], int numNodes);

// DFS 기반 사이클 판별 함수 선언
bool isCyclicDFS(int graph[50][50], int numNodes);

#endif // SEARCH_H
