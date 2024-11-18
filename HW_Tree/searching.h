#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode {
    char* Element;
    struct TreeNode* Left;
    struct TreeNode* Right;
} TreeNode;

// 스택 구조 정의
typedef struct StackNode {
    TreeNode* TreeNode;
    struct StackNode* Next;
} StackNode;

typedef struct QueueNode {
    TreeNode* TreeNode;
    struct QueueNode* Next;
} QueueNode;

typedef struct Queue {
    QueueNode* Front;
    QueueNode* Rear;
} Queue;

void push(StackNode** stack, TreeNode* node);
TreeNode* pop(StackNode** stack);
int precedence(char* op);
TreeNode* createNode(char* element);
TreeNode* buildExpressionTree(const char* expression);

Queue* createQueue();
int isEmpty(Queue* queue);
void enqueue(Queue* queue, TreeNode* node);
TreeNode* dequeue(Queue* queue);


void inOrder(TreeNode* T);
void postOrder(TreeNode* T);
void preOrder(TreeNode* T);
void levelOrder(TreeNode* root);
