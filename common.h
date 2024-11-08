#ifndef COMMON
#define COMMON

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ���׽��� ���� ��Ÿ���� ��� ����ü
typedef struct Node {
    int coefficient; // ���
    int exponent;    // ����
    struct Node* next; // ���� ����� ������
} Node;

Node* createNode(int coeff, int exp);
Node* inputLinkedPolynomial();
int* inputArrayPolynomial();
void printPolynomial(Node* poly);
void print_array(int* a, int n);
void freeArray(int* arr);

#endif 