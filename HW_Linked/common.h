#ifndef COMMON
#define COMMON

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Node structure representing a term in a polynomial
typedef struct Node
{
    int coefficient;   // Coefficient
    int exponent;      // Exponent
    struct Node *next; // Pointer to the next node
} Node;

// Structure for array-based polynomial representation
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

#endif
