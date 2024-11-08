#ifndef COMMON
#define COMMON

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 다항식의 항을 나타내는 노드 구조체
typedef struct Node {
    int coefficient; // 계수
    int exponent;    // 차수
    struct Node* next; // 다음 노드의 포인터
} Node;

Node* createNode(int coeff, int exp);
Node* inputLinkedPolynomial();
int* inputArrayPolynomial();
void printPolynomial(Node* poly);
void print_array(int* a, int n);
void freeArray(int* arr);

#endif 