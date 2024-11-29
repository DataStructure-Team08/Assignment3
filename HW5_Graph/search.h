#ifndef SEARCH
#define SEARCH

#include <stdbool.h>

// BFS, DFS, Connected Component
void bfs(int** graph, int numNodes, int start); // BFS 구현
void dfs(int** graph, int numNodes, int start, bool* visited); // DFS 구현
int* findConnectedComponents(int** graph, int numNodes); // 연결 성분 탐색

// DFS 기반 사이클 판별
bool isCyclicDFS(int** graph, int numNodes);
bool isCyclicDFSUtil(int** graph, bool* visited, int current, int parent, int numNodes);

#endif // SEARCH_H

