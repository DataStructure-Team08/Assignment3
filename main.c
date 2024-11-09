#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "cal.h"

int main() {
    printf("First polynomial:\n");
    Node* poly1 = inputLinkedPolynomial();

    printf("Second polynomial:\n");
    Node* poly2 = inputLinkedPolynomial();

    Node* result = addLinkedPolynomials(poly1, poly2);

    printf("Result polynomial:\n");
    printLinkedPolynomial(result);

    // 메모리 해제
    // TODO: 각 링크드 리스트의 노드를 해제하는 코드를 추가하세요.

    return 0;
}
