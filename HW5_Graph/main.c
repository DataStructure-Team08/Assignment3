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

    // Create copies of the original graph for Prim's and Kruskal's algorithm
    int** primGraph = createAdjacencyMatrix(numNodes);
    int** kruskalGraph = createAdjacencyMatrix(numNodes);
    copyGraph(graph, primGraph, numNodes);
    copyGraph(graph, kruskalGraph, numNodes);

    // Execute Prim's MST on the copied graph and check if it forms a Spanning Tree
    printf("\n\nExecuting Prim's MST:\n");
    primMST(primGraph, numNodes);  // existing primMST function (2 arguments)
    if (isSpanningTree(primGraph, numNodes)) {
        printf("Prim's MST is a valid Spanning Tree.\n");
    } else {
        printf("Prim's MST is NOT a valid Spanning Tree.\n");
    }

    // Execute Kruskal's MST on the copied graph and check if it forms a Spanning Tree
    printf("\nExecuting Kruskal's MST:\n");
    kruskalMST(kruskalGraph, numNodes);  // existing kruskalMST function (2 arguments)
    if (isSpanningTree(kruskalGraph, numNodes)) {
        printf("Kruskal's MST is a valid Spanning Tree.\n");
    } else {
        printf("Kruskal's MST is NOT a valid Spanning Tree.\n");
    }

    free(components);
    freeAdjacencyMatrix(graph, numNodes);
    freeAdjacencyMatrix(primGraph, numNodes);
    freeAdjacencyMatrix(kruskalGraph, numNodes);

    return 0;
}
