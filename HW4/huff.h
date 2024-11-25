#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// huffman tree's node
typedef struct HuffmanNode {
    char Character;         // character
    int Frequency;          // frequency
    struct HuffmanNode* Left, * Right; // left/right child node
} HuffmanNode;

// Definition of priority queue's node
typedef struct PriorityQueueNode {
    HuffmanNode* TreeNode;
    struct PriorityQueueNode* Next;
} PriorityQueueNode;

// priority queue
typedef struct PriorityQueue {
    PriorityQueueNode* Head;
} PriorityQueue;

PriorityQueue* createPriorityQueue();
void enqueueHuff(PriorityQueue* queue, HuffmanNode* node);
HuffmanNode* dequeueHuff(PriorityQueue* queue);
HuffmanNode* createHuffmanTree(const char* str);
void generateCodes(HuffmanNode* root, char* code, int depth, char codes[256][256]);
void encode(const char* str, char codes[256][256], char* encoded);
void decode(const char* encoded, HuffmanNode* root, char* decoded);
