#include "common.h"

// create new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// empty polynomial
Node* freeNode(Node* head) {
    Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// input linkedlist-version polynomial
Node* inputLinkedPolynomial() {
    Node* head = NULL;
    Node* tail = NULL;
    int coeff, exp;

    printf("Enter polynomial terms (input coefficient and exponent, end with -1 -1):\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1) break;

        Node* newNode = createNode(coeff, exp);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// input array-version polynomial
int* inputArrayPolynomial() {
    int* arrayPol=NULL;
    int cnt = 0;
    int coeff, exp;

    printf("Enter polynomial terms (input coefficient and exponent, end with -1 -1):\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1) break;
        if (cnt == 0) arrayPol = (int*)calloc(exp+1,sizeof(int));
        arrayPol[exp] = coeff;
        cnt++;
    }

    return arrayPol;
}

// print linkedlist-version polynomial
void printLinkedPolynomial(Node* poly) {
    Node* current = poly;
    while (current) {
        if (current->coefficient > 0 && current != poly) {
            printf("+");
        }
        printf("%dx^%d ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

// oprint array-version polynomial
void printArrayPolynomial(int* a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// 
void freeArray(int* arr) {
    free(arr);
}
