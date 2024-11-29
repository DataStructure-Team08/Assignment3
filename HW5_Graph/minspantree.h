#ifndef MINSPANTREE
#define MINSPANTREE

typedef struct {
    int u, v, weight;
} Edge;

// Prim's MST 함수 선언
void primMST(int** graph, int numNodes);

// Kruskal's MST 함수 선언
void kruskalMST(int** graph, int numNodes);

#endif // MINSPANTREE

