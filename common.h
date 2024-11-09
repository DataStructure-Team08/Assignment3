#ifndef COMMON
#define COMMON

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Node structure representing a term in a polynomial
typedef struct Node {
    int coefficient; // Coefficient
    int exponent;    // Exponent
    struct Node* next; // Pointer to the next node
} Node;

Node* createNode(int coeff, int exp);
Node* freeNode(Node* head);
Node* inputLinkedPolynomial();
int* inputArrayPolynomial();
void printPolynomial(Node* poly);
void print_array(int* a, int n);
void freeArray(int* arr);

#endif 
