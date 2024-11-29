#include "create.h"
#include "search.h"
#include "minspantree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numNodes, density;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter edge density (0-100): ");
    scanf("%d", &density);

    int maxEdges = numNodes * (numNodes - 1) / 2;
    int numEdges = (density * maxEdges) / 100;

    // 원래 그래프 생성
    int** graph = createAdjacencyMatrix(numNodes);
    addRandomEdges(graph, numNodes, numEdges);

    printf("Generated Adjacency Matrix:\n");
    printAdjacencyMatrix(graph, numNodes);

    // BFS와 DFS 실행
    printf("\nExecuting BFS from node 0:\n");
    bfs(graph, numNodes, 0);

    printf("\nExecuting DFS from node 0:\n");
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    dfs(graph, numNodes, 0, visited);
    free(visited);

    // 분리된 그래프를 복사하여 별도로 작업
    int** separatedGraph = copyAdjacencyMatrix(graph, numNodes);
    separateGraph(separatedGraph, numNodes);

    printf("\nGenerated Adjacency Matrix (After Separation):\n");
    printAdjacencyMatrix(separatedGraph, numNodes);

    printf("\nFinding Connected Components:\n");
    findConnectedComponents(separatedGraph, numNodes);

    // Prim과 Kruskal은 원래 그래프에 대해 실행
    printf("\n\nExecuting Prim's MST:\n");
    primMST(graph, numNodes);

    printf("\nExecuting Kruskal's MST:\n");
    kruskalMST(graph, numNodes);

    // 메모리 해제
    freeAdjacencyMatrix(graph, numNodes);
    freeAdjacencyMatrix(separatedGraph, numNodes);

    return 0;
}
