#ifndef CREATE
#define CREATE

// 그래프 생성 및 관리
int** createAdjacencyMatrix(int numNodes);        // 동적 그래프 생성
void freeAdjacencyMatrix(int** graph, int numNodes); // 그래프 메모리 해제
void addRandomEdges(int** graph, int numNodes, int numEdges); // 랜덤 간선 추가
void printAdjacencyMatrix(int** graph, int numNodes); // 그래프 출력

#endif // CREATE_H

