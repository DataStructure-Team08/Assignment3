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

    printf("\nExecuting BFS from node 0:\n");
    bfs(graph, numNodes, 0);

    printf("\nExecuting DFS from node 0:\n");
    bool* visited = (bool*)calloc(numNodes, sizeof(bool));
    dfs(graph, numNodes, 0, visited);
    free(visited);

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

    freeAdjacencyMatrix(graph, numNodes);
    freeAdjacencyMatrix(primGraph, numNodes);
    freeAdjacencyMatrix(kruskalGraph, numNodes);

    return 0;
}
