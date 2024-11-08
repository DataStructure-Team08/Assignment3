#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "cal.h"

int main() {
    printf("첫 번째 다항식:\n");
    Node* poly1 = inputLinkedPolynomial();

    printf("두 번째 다항식:\n");
    Node* poly2 = inputLinkedPolynomial();

    Node* result = addLinkedPolynomials(poly1, poly2);

    printf("결과 다항식:\n");
    printLinkedPolynomial(result);

    // 메모리 해제
    // TODO: 각 링크드 리스트의 노드를 해제하는 코드를 추가하세요.

    return 0;
}
