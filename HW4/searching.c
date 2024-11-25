#include "searching.h"

// Stack operations
void push(StackNode** stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for stack node.\n");
        exit(EXIT_FAILURE);
    }
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

// define priority of operators
int precedence(char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    return 0;
}

// create node
TreeNode* createNode(const char* element) {
    if (!element) {
        fprintf(stderr, "Error: NULL element passed to createNode.\n");
        exit(EXIT_FAILURE);
    }

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed for TreeNode.\n");
        exit(EXIT_FAILURE);
    }
    node->Element = (char*)malloc(strlen(element) + 1);
    if (!node->Element) {
        fprintf(stderr, "Memory allocation failed for TreeNode->Element.\n");
        free(node);
        exit(EXIT_FAILURE);
    }

    strcpy(node->Element, element);
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

// create a binary tree
TreeNode* buildExpressionTree(const char* expression) {
    StackNode* operandStack = NULL;
    StackNode* operatorStack = NULL;
    char buffer[32];
    int bufIdx=0;

    for (int i = 0; expression[i] != '\0'; i++) {
        char str[2];
        str[0] = expression[i];
        str[1] = '\0';

        // ignore space
        if (isspace(str[0])) continue;

        if (isdigit(str[0])) {
            buffer[bufIdx++] = str[0];
            if (!isdigit(expression[i + 1])) {  // end number
                buffer[bufIdx] = '\0';          // add NULL
                TreeNode* operandNode = createNode(buffer);
                push(&operandStack, operandNode);
                bufIdx = 0;
            }
        }
        else if (str[0] == '(') {
            // open parenthesis
            TreeNode* operatorNode = createNode(str);
            push(&operatorStack, operatorNode);
        }
        else if (str[0] == ')') {
            // close parenthesis
            while (operatorStack && strcmp(operatorStack->TreeNode->Element, "(") != 0) {
                TreeNode* operatorNode = pop(&operatorStack);
                operatorNode->Right = pop(&operandStack);
                operatorNode->Left = pop(&operandStack);
                push(&operandStack, operatorNode);
            }
            pop(&operatorStack); // remove open parenthesis
        }
        else {
            // operators
            while (operatorStack && precedence(operatorStack->TreeNode->Element) >= precedence(str)) {
                TreeNode* operatorNode = pop(&operatorStack);
                operatorNode->Right = pop(&operandStack);
                operatorNode->Left = pop(&operandStack);
                push(&operandStack, operatorNode);
            }
            TreeNode* operatorNode = createNode(str);
            push(&operatorStack, operatorNode);
        }
    }

    // handling remains
    while (operatorStack) {
        TreeNode* operatorNode = pop(&operatorStack);
        operatorNode->Right = pop(&operandStack);
        operatorNode->Left = pop(&operandStack);
        push(&operandStack, operatorNode);
    }
    // return results
    return pop(&operandStack);
}

// Queue operations
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

// tree traversing
void inOrder(TreeNode* T) {
    if (T != NULL) {
        inOrder(T->Left);
        printf("%s ", T->Element);
        inOrder(T->Right);
    }
}

void postOrder(TreeNode* T) {
    if (T != NULL) {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%s ", T->Element);
    }
}

void preOrder(TreeNode* T) {
    if (T != NULL) {
        printf("%s ", T->Element);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// traverse tree in level order
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        printf("%s ", current->Element);

        if (current->Left) enqueue(queue, current->Left);
        if (current->Right) enqueue(queue, current->Right);
    }

    printf("\n");
}