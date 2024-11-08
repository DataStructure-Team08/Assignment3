#include "common.h"

// 새로운 노드 생성 함수
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// 다항식 입력 함수
Node* inputLinkedPolynomial() {
    Node* head = NULL;
    Node* tail = NULL;
    int coeff, exp;

    printf("다항식을 입력하세요 (계수와 차수를 입력, -1 -1로 종료):\n");
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

// 다항식 입력 함수
int* inputArrayPolynomial() {
    int* arrayPol=NULL;
    int cnt = 0;
    int coeff, exp;

    printf("다항식을 입력하세요 (계수와 차수를 입력, -1 -1로 종료):\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1) break;
        if (cnt == 0) arrayPol = (int*)calloc(exp+1,sizeof(int));
        arrayPol[exp] = coeff;
        cnt++;
    }

    return arrayPol;
}

// 다항식 출력 함수
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

void printArrayPolynomial(int* a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void freeArray(int* arr) {
    free(arr);
}