#ifndef COMMON
#define COMMON

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ���׽��� ���� ��Ÿ���� ��� ����ü
typedef struct Node
{
    int coefficient;   // ���
    int exponent;      // ����
    struct Node *next; // ���� ����� ������
} Node;

typedef struct Pol
{
    int size;
    int *a;
} Pol;

Node *createNode(int coeff, int exp);
Node *inputLinkedPolynomial();
Pol *inputArrayPolynomial();
void printLinkedPolynomial(Node *poly);
void printArrayPolynomial(Pol *p);
Node *freeNode(Node *head);
void freeArray(int *arr);

#endif