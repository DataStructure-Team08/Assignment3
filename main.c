#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "cal.h"

int main()
{
    printf("First array-version polynomial: \n");
    Pol *arr1 = inputArrayPolynomial();
    printArrayPolynomial(arr1);

    printf("Second array-version polynomial: \n");
    Pol *arr2 = inputArrayPolynomial();

    Pol *arr_add = addArrayPolynomials(arr1, arr2);
    Pol *arr_sub = subArrayPolynomials(arr1, arr2);

    printf("Add Result: ");
    printArrayPolynomial(arr_add);
    printf("\n");
    printf("Sub Result: ");
    printArrayPolynomial(arr_sub);
    printf("\n");

    printf("First linked-list version polynomial: ");
    Node *link1 = inputLinkedPolynomial();

    printf("Second linked-list version polynomial: ");
    Node *link2 = inputLinkedPolynomial();

    Node *link_add = addLinkedPolynomials(link1, link2);
    Node *link_sub = subLinkedPolynomials(link1, link2);

    printf("Add Result: ");
    printLinkedPolynomial(link_add);
    printf("\n");
    printf("Sub Result: ");
    printLinkedPolynomial(link_sub);
    printf("\n");

    // delete polynomials
    free(arr1);
    free(arr2);
    free(link_add);
    free(link_sub);

    return 0;
}