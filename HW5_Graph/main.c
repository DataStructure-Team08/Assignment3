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

    printf("\n\nExecuting Prim's MST:\n");
    primMST(graph, numNodes);

    printf("\nExecuting Kruskal's MST:\n");
    kruskalMST(graph, numNodes);

    freeAdjacencyMatrix(graph, numNodes);
    return 0;
}
