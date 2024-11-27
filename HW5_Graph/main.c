#include "minspantree.h"
#include "search.h"
#include <stdio.h>

int main() {
    int graph[50][50] = {0};
    int numNodes = 5;

    int edges[][3] = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {3, 4, 6}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    graph[0][1] = 4; graph[1][0] = 4;
    graph[0][2] = 4; graph[2][0] = 4;
    graph[1][2] = 2; graph[2][1] = 2;
    graph[1][3] = 5; graph[3][1] = 5;
    graph[3][4] = 6; graph[4][3] = 6;

    printf("Executing Prim's MST:\n");
    primMST(graph, numNodes);

    printf("\nExecuting Kruskal's MST:\n");
    kruskalMST(graph, numNodes, numEdges, edges);

    printf("\nExecuting BFS:\n");
    bfs(graph, numNodes, 0);

    printf("\nExecuting DFS:\n");
    bool visited[50] = {false};
    dfs(graph, numNodes, 0, visited);

    printf("\nExecuting Connected Components:\n");
    findConnectedComponents(graph, numNodes);

    return 0;
}
