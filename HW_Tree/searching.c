#include "searching.h"

// 스택 함수
void push(StackNode** stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->TreeNode = node;
    newNode->Next = *stack;
    *stack = newNode;
}

TreeNode* pop(StackNode** stack) {
    if (*stack == NULL) return NULL;
    StackNode* temp = *stack;
    TreeNode* node = temp->TreeNode;
    *stack = (*stack)->Next;
    free(temp);
    return node;
}

// 우선순위 반환
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 노드 생성
TreeNode* createNode(char element) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->Element = element;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

// 이진트리 생성 (중위표기법을 후위표기법으로 변환하고 트리로 생성)
TreeNode* buildExpressionTree(const char* expression) {
    StackNode* operandStack = NULL;
    StackNode* operatorStack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // 공백 무시
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            // 피연산자 처리
            TreeNode* operandNode = createNode(ch);
            push(&operandStack, operandNode);
        }
        else if (ch == '(') {
            // 여는 괄호
            TreeNode* operatorNode = createNode(ch);
            push(&operatorStack, operatorNode);
        }
        else if (ch == ')') {
            // 닫는 괄호 처리
            while (operatorStack && operatorStack->TreeNode->Element != '(') {
                TreeNode* operatorNode = pop(&operatorStack);
                operatorNode->Right = pop(&operandStack);
                operatorNode->Left = pop(&operandStack);
                push(&operandStack, operatorNode);
            }
            pop(&operatorStack); // 여는 괄호 제거
        }
        else {
            // 연산자 처리
            while (operatorStack && precedence(operatorStack->TreeNode->Element) >= precedence(ch)) {
                TreeNode* operatorNode = pop(&operatorStack);
                operatorNode->Right = pop(&operandStack);
                operatorNode->Left = pop(&operandStack);
                push(&operandStack, operatorNode);
            }
            TreeNode* operatorNode = createNode(ch);
            push(&operatorStack, operatorNode);
        }
    }

    // 남은 연산자 처리
    while (operatorStack) {
        TreeNode* operatorNode = pop(&operatorStack);
        operatorNode->Right = pop(&operandStack);
        operatorNode->Left = pop(&operandStack);
        push(&operandStack, operatorNode);
    }

    // 최종 결과 반환
    return pop(&operandStack);
}

// 큐 함수
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->Front = queue->Rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->Front == NULL;
}

void enqueue(Queue* queue, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->TreeNode = node;
    newNode->Next = NULL;
    if (queue->Rear) {
        queue->Rear->Next = newNode;
    }
    else {
        queue->Front = newNode;
    }
    queue->Rear = newNode;
}

TreeNode* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    QueueNode* temp = queue->Front;
    TreeNode* node = temp->TreeNode;
    queue->Front = temp->Next;
    if (!queue->Front) {
        queue->Rear = NULL;
    }
    free(temp);
    return node;
}

// 트리 순회 함수
void inOrder(TreeNode* T) {
    if (T != NULL) {
        inOrder(T->Left);
        printf("%c ", T->Element);
        inOrder(T->Right);
    }
}

void postOrder(TreeNode* T) {
    if (T != NULL) {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%c ", T->Element);
    }
}

void preOrder(TreeNode* T) {
    if (T != NULL) {
        printf("%c ", T->Element);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// Level Order Traversal 함수
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        printf("%c ", current->Element);

        if (current->Left) enqueue(queue, current->Left);
        if (current->Right) enqueue(queue, current->Right);
    }

    printf("\n");
}