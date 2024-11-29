#ifndef MINSPANTREE
#define MINSPANTREE

// Function declarations for Prim's and Kruskal's algorithms
void primMST(int** graph, int numNodes);
void kruskalMST(int** graph, int numNodes);

// Function to check if a graph is a Spanning Tree
bool isSpanningTree(int** graph, int numNodes);

#endif // MINSPANTREE_H
