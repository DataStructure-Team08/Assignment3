#include "cal.h"

Node *addLinkedPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *tail = NULL;

    while (poly1 || poly2)
    {
        int coeff = 0;
        int exp;

        if (!poly1)
        {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else if (!poly2)
        {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent > poly2->exponent)
        {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else
        {
            coeff = poly1->coefficient + poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0)
        {
            Node *newNode = createNode(coeff, exp);
            if (!result)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return result;
}

// 다항식 가감 연산 함수
Node *subLinkedPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *tail = NULL;

    while (poly1 || poly2)
    {
        int coeff = 0;
        int exp;

        if (!poly1)
        {
            coeff = -1 * poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else if (!poly2)
        {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent > poly2->exponent)
        {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            coeff = -1 * poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        else
        {
            coeff = poly1->coefficient - poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0)
        {
            Node *newNode = createNode(coeff, exp);
            if (!result)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return result;
}

// 두 다항식의 덧셈 함수
Pol *addArrayPolynomials(Pol *poly1, Pol *poly2)
{
    // 결과 배열의 크기는 두 다항식의 최대 지수 중 더 큰 값
    Pol *result = (Pol *)malloc(sizeof(Pol));
    int resultSize = (poly1->size > poly2->size) ? poly1->size : poly2->size;
    result->size = resultSize;
    result->a = (int *)calloc(resultSize, sizeof(int));

    // 각 다항식의 계수를 결과 배열에 더함
    for (int i = 0; i < poly1->size; i++)
    {
        if (poly1->a[i] != 0)
            result->a[i] += poly1->a[i];
    }
    for (int i = 0; i < poly2->size; i++)
    {
        if (poly2->a[i] != 0)
            result->a[i] += poly2->a[i];
    }

    return result;
}
// 두 다항식의 덧셈 함수
Pol *subArrayPolynomials(Pol *poly1, Pol *poly2)
{
    // 결과 배열의 크기는 두 다항식의 최대 지수 중 더 큰 값
    Pol *result = (Pol *)malloc(sizeof(Pol));
    int resultSize = (poly1->size > poly2->size) ? poly1->size : poly2->size;
    result->size = resultSize;
    result->a = (int *)calloc(resultSize, sizeof(int));

    // 각 다항식의 계수를 결과 배열에 더함
    for (int i = 0; i < poly1->size; i++)
    {
        if (poly1->a[i] != 0)
            result->a[i] += poly1->a[i];
    }
    for (int i = 0; i < poly2->size; i++)
    {
        if (poly2->a[i] != 0)
            result->a[i] -= poly2->a[i];
    }

    return result;
}