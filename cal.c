#include "cal.h"

// ���׽� ���� ���� �Լ�
Node* addLinkedPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 || poly2) {
        int coeff = 0;
        int exp;

        if (!poly1) {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else if (!poly2) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent > poly2->exponent) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent) {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else {
            coeff = poly1->coefficient + poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0) {
            Node* newNode = createNode(coeff, exp);
            if (!result) {
                result = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return result;
}

// ���׽� ���� ���� �Լ�
Node* subLinkedPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 || poly2) {
        int coeff = 0;
        int exp;

        if (!poly1) {
            coeff = -1 * poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else if (!poly2) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent > poly2->exponent) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent) {
            coeff = -1 * poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else {
            coeff = poly1->coefficient - poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0) {
            Node* newNode = createNode(coeff, exp);
            if (!result) {
                result = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return result;
}

// �� ���׽��� ���� �Լ�
int* addArrayPolynomials(int* poly1, int* poly2) {
    int maxExp1 = sizeof(poly1) / sizeof(poly1[0]);
    int maxExp2 = sizeof(poly2) / sizeof(poly2[0]);

    // ��� �迭�� ũ��� �� ���׽��� �ִ� ���� �� �� ū ��
    int resultSize = (maxExp1 > maxExp2) ? maxExp1 : maxExp2;
    int* result = (int*)calloc(resultSize, sizeof(int));  // 0���� �ʱ�ȭ�� �迭

    // �� ���׽��� ����� ��� �迭�� ����
    for (int i = 0; i < maxExp1; i++) {
        result[i] += poly1[i];
    }
    for (int i = 0; i < maxExp2; i++) {
        result[i] += poly2[i];
    }

    return result;
}
// �� ���׽��� ���� �Լ�
int* subArrayPolynomials(int* poly1, int* poly2) {
    int maxExp1 = sizeof(poly1) / sizeof(poly1[0]);
    int maxExp2 = sizeof(poly2) / sizeof(poly2[0]);

    // ��� �迭�� ũ��� �� ���׽��� �ִ� ���� �� �� ū ��
    int resultSize = (maxExp1 > maxExp2) ? maxExp1 : maxExp2;
    int* result = (int*)calloc(resultSize, sizeof(int));  // 0���� �ʱ�ȭ�� �迭

    // �� ���׽��� ����� ��� �迭�� ����
    for (int i = 0; i < maxExp1; i++) {
        result[i] += poly1[i];
    }
    for (int i = 0; i < maxExp2; i++) {
        result[i] += (-1*poly2[i]);
    }

    return result;
}