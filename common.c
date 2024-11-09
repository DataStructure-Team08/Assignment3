#include "common.h"

// create new node
Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// input linkedlist-version polynomial
Node *inputLinkedPolynomial()
{
    Node *head = NULL;
    Node *tail = NULL;
    int coeff, exp;

    printf("Enter polynomial terms (input coefficient and exponent, end with -1 -1):\n");
    while (1)
    {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1)
            break;

        Node *newNode = createNode(coeff, exp);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// input array-version polynomial
Pol *inputArrayPolynomial()
{
    Pol *result;
    int *arrayPol = NULL;
    int cnt = 0;
    int coeff, exp;

    printf("Enter polynomial terms (input coefficient and exponent, end with -1 -1):\n");
    while (1)
    {
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 && exp == -1)
            break;
        if (cnt == 0)
        {
            arrayPol = (int *)calloc(exp + 1, sizeof(int));
            result->size = exp;
        }
        arrayPol[exp] = coeff;
        cnt++;
    }
    result->a = arrayPol;
    return result;
}

// print linkedlist-version polynomial
void printLinkedPolynomial(Node *poly)
{
    Node *current = poly;
    while (current)
    {
        if (current->coefficient > 0 && current != poly)
        {
            printf("+");
        }
        printf("%dx^%d ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

// oprint array-version polynomial
void printArrayPolynomial(int *a)
{
    int i = 0;
    while (!a)
    {
        if (a[i] != 0)
            printf("%dx^%d + ", a[i], i);
        i++;
    }
    printf("\n");
}

// empty polynomial
Node *freeNode(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
