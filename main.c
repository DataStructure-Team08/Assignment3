#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "cal.h"

int main() {
    printf("ù ��° ���׽�:\n");
    Node* poly1 = inputLinkedPolynomial();

    printf("�� ��° ���׽�:\n");
    Node* poly2 = inputLinkedPolynomial();

    Node* result = addLinkedPolynomials(poly1, poly2);

    printf("��� ���׽�:\n");
    printLinkedPolynomial(result);

    // �޸� ����
    // TODO: �� ��ũ�� ����Ʈ�� ��带 �����ϴ� �ڵ带 �߰��ϼ���.

    return 0;
}
