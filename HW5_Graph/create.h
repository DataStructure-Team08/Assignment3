#ifndef CREATE
#define CREATE

int** createAdjacencyMatrix(int numNodes);
int** copyAdjacencyMatrix(int** graph, int numNodes);
void addRandomEdges(int** graph, int numNodes, int numEdges);
void printAdjacencyMatrix(int** graph, int numNodes);
void freeAdjacencyMatrix(int** graph, int numNodes);
void separateGraph(int** graph, int numNodes);

#endif

