#include "huff.h"

// priority queue operations
PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->Head = NULL;
    return queue;
}

void enqueueHuff(PriorityQueue* queue, HuffmanNode* node) {
    PriorityQueueNode* newNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    newNode->TreeNode = node;
    newNode->Next = NULL;

    if (queue->Head == NULL || queue->Head->TreeNode->Frequency > node->Frequency) {
        newNode->Next = queue->Head;
        queue->Head = newNode;
    }
    else {
        PriorityQueueNode* temp = queue->Head;
        while (temp->Next != NULL && temp->Next->TreeNode->Frequency <= node->Frequency) {
            temp = temp->Next;
        }
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

HuffmanNode* dequeueHuff(PriorityQueue* queue) {
    if (queue->Head == NULL) return NULL;
    PriorityQueueNode* temp = queue->Head;
    HuffmanNode* node = temp->TreeNode;
    queue->Head = queue->Head->Next;
    free(temp);
    return node;
}

HuffmanNode* createHuffmanTree(const char* str) {
    int freq[256] = { 0 };
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    PriorityQueue* queue = createPriorityQueue();
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
            node->Character = i;
            node->Frequency = freq[i];
            node->Left = node->Right = NULL;
            enqueueHuff(queue, node);
        }
    }

    while (queue->Head != NULL && queue->Head->Next != NULL) {
        HuffmanNode* left = dequeueHuff(queue);
        HuffmanNode* right = dequeueHuff(queue);

        HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        newNode->Character = '\0'; // internal nodes do not contain characters
        newNode->Frequency = left->Frequency + right->Frequency;
        newNode->Left = left;
        newNode->Right = right;

        enqueueHuff(queue, newNode);
    }

    return dequeueHuff(queue); // return root
}

void generateCodes(HuffmanNode* root, char* code, int depth, char codes[256][256]) {
    if (root->Left == NULL && root->Right == NULL) {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->Character], code);
        return;
    }

    if (root->Left) {
        code[depth] = '0';
        generateCodes(root->Left, code, depth + 1, codes);
    }
    if (root->Right) {
        code[depth] = '1';
        generateCodes(root->Right, code, depth + 1, codes);
    }
}

void encode(const char* str, char codes[256][256], char* encoded) {
    encoded[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        strcat(encoded, codes[(unsigned char)str[i]]);
    }
}

void decode(const char* encoded, HuffmanNode* root, char* decoded) {
    int index = 0;
    HuffmanNode* current = root;
    for (int i = 0; encoded[i] != '\0'; i++) {
        if (encoded[i] == '0') {
            current = current->Left;
        }
        else {
            current = current->Right;
        }

        if (current->Left == NULL && current->Right == NULL) {
            decoded[index++] = current->Character;
            current = root;
        }
    }
    decoded[index] = '\0';
}

