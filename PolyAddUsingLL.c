#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int exp;
    int coeff;
    struct node *next;
} node;

node *copy(node *temp)
{
    node *temp3, *last, *poly3;
    poly3 = NULL;
    while (temp)
    {
        temp3 = (node *)malloc(sizeof(node));
        temp3->exp = temp->exp;
        temp3->coeff = temp->coeff;
        if (poly3 == NULL)
        {
            poly3 = temp3;
            last = temp3;
        }
        else
        {
            last->next = temp3;
            last = temp3;
        }
        temp = temp->next;
    }
    return poly3;
}

void traverse(node *start)
{
    if (start == NULL)
        printf("list is empty.");
    else
    {
        while (start != NULL)
        {
            if (start->next != NULL)
                printf("%dx^%d + ", start->coeff, start->exp);

            else
                printf("%dx^%d", start->coeff, start->exp);
            start = start->next;
        }
    }
}
node *create2()
{
    node *first, *last, *temp;
    first = NULL;
    int exp, coeff;
    printf("enter the exponential or press -1 to stop :");
    scanf("%d", &exp);
    if (exp != -1)
    {

        first = (node *)malloc(sizeof(node));
        if (first == NULL)
        {
            printf("Malloc failed.");
            return NULL;
        }
        printf("enter the coefficient :");
        scanf("%d", &coeff);
        first->exp = exp;
        first->coeff = coeff;
        first->next = NULL;

        last = first;
        printf("enter the exponential or press -1 to stop :");
        scanf("%d", &exp);
        while (exp != -1)
        {
            printf("enter the coefficient :");
            scanf("%d", &coeff);
            temp = (node *)malloc(sizeof(node));
            temp->exp = exp;
            temp->coeff = coeff;
            temp->next = NULL;
            last->next = temp;
            last = temp;
            printf("enter the exp or press -1 to stop :");
            scanf("%d", &exp);
        }
        printf("the polnomial has ended.");
        last->next = NULL;
    }
    return first;
}
node *addpol(node *poly1, node *poly2)
{
    node *poly3, *temp1, *temp2, *temp3, *last;
    poly3 = NULL;
    temp1 = poly1;
    temp2 = poly2;
    temp3 = poly3;
    if ((poly1 == NULL) && (poly2 == NULL))
    {
        printf("Polynomials are empty");
        return poly3;
    }
    else if (poly1 == NULL)
    {
        poly3 = copy(temp2);
        return poly3;
    }
    else if (poly2 == NULL)
    {
        poly3 = copy(temp1);
        return poly3;
    }
    else
    {
        while ((temp1 != NULL) && (temp2 != NULL))
        {
            temp3 = (node *)malloc(sizeof(node));
            if (temp1->exp == temp2->exp)
            {
                if (temp1->coeff + temp2->coeff != 0)
                {
                    temp3 = (node *)malloc(sizeof(node));
                    temp3->coeff = temp1->coeff + temp2->coeff;
                    temp3->exp = temp1->exp;
                    if (poly3 == NULL)
                    {
                        poly3 = temp3;
                        last = temp3;
                    }
                    else
                    {
                        last->next = temp3;
                        last = temp3;
                    }
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exp > temp2->exp)
            {
                temp3 = (node *)malloc(sizeof(node));
                temp3->exp = temp1->exp;
                temp3->coeff = temp1->coeff;
                if (poly3 == NULL)
                {
                    poly3 = temp3;
                    last = temp3;
                }
                else
                {

                    last->next = temp3;
                    last = temp3;
                }
                temp1 = temp1->next;
            }
            else
            {
                temp3 = (node *)malloc(sizeof(node));
                temp3->exp = temp2->exp;
                temp3->coeff = temp2->coeff;
                if (poly3 == NULL)
                {
                    poly3 = temp3;
                    last = temp3;
                }
                else
                {

                    last->next = temp3;
                    last = temp3;
                }
                temp2 = temp2->next;
            }
        }
        while (temp1)
        {

            temp3 = (node *)malloc(sizeof(node));
            temp3->exp = temp1->exp;
            temp3->coeff = temp1->coeff;
            if (poly3 == NULL)
            {
                poly3 = temp3;
                last = temp3;
            }
            else
            {
                last->next = temp3;
                last = temp3;
            }
            temp1 = temp1->next;
        }
        while (temp2)
        {
            temp3 = (node *)malloc(sizeof(node));
            temp3->exp = temp2->exp;
            temp3->coeff = temp2->coeff;
            if (poly3 == NULL)
            {
                poly3 = temp3;
                last = temp3;
            }
            else
            {

                last->next = temp3;
                last = temp3;
            }
            temp2 = temp2->next;
        }
    }
    temp3->next = NULL;
    return poly3;
}
int main()
{
    node *poly1, *poly2, *poly3;
    printf("Enter the first polynomial :\n");
    poly1 = create2();
    traverse(poly1);
    printf("\nEnter the second polynomial :\n");
    poly2 = create2();
    traverse(poly2);
    printf("\nthe resultant polynomial is :\n");
    poly3 = addpol(poly1, poly2);
    traverse(poly3);
}