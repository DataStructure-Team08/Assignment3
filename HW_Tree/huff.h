#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 허프만 트리 노드 정의
typedef struct HuffmanNode {
    char Character;         // 문자
    int Frequency;          // 빈도수
    struct HuffmanNode* Left, * Right; // 왼쪽/오른쪽 자식 노드
} HuffmanNode;

// 우선순위 큐 노드 정의
typedef struct PriorityQueueNode {
    HuffmanNode* TreeNode;
    struct PriorityQueueNode* Next;
} PriorityQueueNode;

// 우선순위 큐 정의
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
