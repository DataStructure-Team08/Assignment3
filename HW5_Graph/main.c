#include "search.h"
#include "minspantree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numNodes, density;

    // 사용자 입력
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter edge density (0-100): ");
    scanf("%d", &density);

    // 최대 간선 수 및 실제 간선 수 계산
    int maxEdges = numNodes * (numNodes - 1) / 2; // 무방향 그래프의 최대 간선 수
    int numEdges = (density * maxEdges) / 100;   // 밀도에 기반한 실제 간선 수

    // 그래프 생성 및 랜덤 간선 추가
    int** graph = createAdjacencyMatrix(numNodes);
    addRandomEdges(graph, numNodes, numEdges);

    // 생성된 그래프 출력
    printf("Generated Adjacency Matrix:\n");
    printAdjacencyMatrix(graph, numNodes);

    printf("\nExecuting BFS from node 0:\n");
    bfs(graph, numNodes, 0);

    printf("\nExecuting DFS from node 0:\n");
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    dfs(graph, numNodes, 0, visited);
    free(visited);

    printf("\n\nFinding Connected Components:\n");
    findConnectedComponents(graph, numNodes);

    printf("\nExecuting Prim's MST:\n");
    primMST(graph, numNodes);

    printf("\nExecuting Kruskal's MST:\n");
    int edges[numEdges][3];
    int edgeIndex = 0;
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (graph[i][j] != 0) {
                edges[edgeIndex][0] = i;
                edges[edgeIndex][1] = j;
                edges[edgeIndex][2] = graph[i][j];
                edgeIndex++;
            }
        }
    }
    kruskalMST(graph, numNodes, numEdges, edges);

    // 메모리 해제
    freeAdjacencyMatrix(graph, numNodes);

    return 0;
}
