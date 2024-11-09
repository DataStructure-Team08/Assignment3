#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "cal.h"

int main() {
    printf("First array-version polynomial: ");
    int* arr1 = inputArrayPolynomial();

    printf("Second array-version polynomial: ");
    int* arr2 = inputArrayPolynomial();

    int* link_add = addArrayPolynomials(arr1, arr2);
    int* link_sub = subArrayPolynomials(arr1, arr2);

    printf("Result:");
    printArrayPolynomial(result);
    printf("\n");
    
    printf("First linked-list version polynomial: ");
    Node* link1 = inputLinkedPolynomial();

    printf("Second linked-list version polynomial: ");
    Node* link2 = inputLinkedPolynomial();

    Node* link_add = addLinkedPolynomials(link1, link2);
    Node* link_sub = subLinkedPolynomials(link1, link2);

    printf("Result:");
    printLinkedPolynomial(result);
    printf("\n");

   // delete polynomials
    free(arr1);
    free(arr2);
    free(link_add);
    free(link_sub);

    return 0;
}
