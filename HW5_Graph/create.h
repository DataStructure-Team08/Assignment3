#ifndef CREATE
#define CREATE

int** createAdjacencyMatrix(int numNodes);
void addRandomEdges(int** graph, int numNodes, int numEdges);
void printAdjacencyMatrix(int** graph, int numNodes);
void freeAdjacencyMatrix(int** graph, int numNodes);

void copyGraph(int** source, int** destination, int numNodes);

#endif

