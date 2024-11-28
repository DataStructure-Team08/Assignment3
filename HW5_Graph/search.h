#ifndef SEARCH
#define SEARCH

#include <stdbool.h>

// 그래프 생성 및 관리
int** createAdjacencyMatrix(int numNodes);
void freeAdjacencyMatrix(int** graph, int numNodes);
void addRandomEdges(int** graph, int numNodes, int numEdges);
void printAdjacencyMatrix(int** graph, int numNodes);

// BFS, DFS, Connected Component
void bfs(int** graph, int numNodes, int start);
void dfs(int** graph, int numNodes, int start, bool* visited);
void findConnectedComponents(int** graph, int numNodes);

// DFS 기반 사이클 판별
bool isCyclicDFS(int** graph, int numNodes);

#endif // SEARCH_H
