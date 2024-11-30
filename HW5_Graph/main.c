#include "create.h"
#include "search.h"
#include "minspantree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numNodes, density;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter edge density (0-100): ");
    scanf("%d", &density);

    clock_t start = clock();
    int maxEdges = numNodes * (numNodes - 1) / 2;
    int numEdges = (density * maxEdges) / 100;

    int** graph = createAdjacencyMatrix(numNodes);
    addRandomEdges(graph, numNodes, numEdges);

    printf("Generated Adjacency Matrix:\n");
    printAdjacencyMatrix(graph, numNodes);

    // BFS 실행
    printf("\nExecuting BFS from node 0:\n");
    bfs(graph, numNodes, 0);

    // DFS 실행
    printf("\nExecuting DFS from node 0:\n");
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    dfs(graph, numNodes, 0, visited, true);  // 출력 활성화
    free(visited);

    // 연결 성분 탐색
    printf("\n\nFinding Connected Components:\n");
    int* components = findConnectedComponents(graph, numNodes);

    int maxComponent = 0;
    for (int i = 0; i < numNodes; i++) {
        if (components[i] > maxComponent) {
            maxComponent = components[i];
        }
    }

    for (int c = 1; c <= maxComponent; c++) {
        printf("Component %d: ", c);
        for (int i = 0; i < numNodes; i++) {
            if (components[i] == c) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

   printf("\n\nExecuting Prim's MST:\n");
    int** primMSTGraph = primMST(graph, numNodes);
    if (isSpanningTree(primMSTGraph, numNodes)) {
        printf("Prim's MST is a valid Spanning Tree.\n");
    } else {
        printf("Prim's MST is NOT a valid Spanning Tree.\n");
    }
    freeAdjacencyMatrix(primMSTGraph, numNodes);

    printf("\nExecuting Kruskal's MST:\n");
    int** kruskalMSTGraph = kruskalMST(graph, numNodes);
    if (isSpanningTree(kruskalMSTGraph, numNodes)) {
        printf("Kruskal's MST is a valid Spanning Tree.\n");
    } else {
        printf("Kruskal's MST is NOT a valid Spanning Tree.\n");
    }

    clock_t end = clock();
    printf("Total time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    freeAdjacencyMatrix(kruskalMSTGraph, numNodes);

    free(components);
    freeAdjacencyMatrix(graph, numNodes);

    return 0;
}
