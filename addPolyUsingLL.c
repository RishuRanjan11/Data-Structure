#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int exp, coeff;
    struct node *next;
} node;

int main(int argc, char const *argv[])
{
    node *start1;
    node *curr;
    int terms;
    int count = 1;
    printf("Enter the number of terms of poly1: ");
    scanf("%d", &terms);
    printf("Enter the 1 term's exp and coeff of poly1: ");
    start1 = (node *)malloc(sizeof(node));
    scanf("%d%d" & (start1->exp), &(start1->coeff));
    node *temp1;
    while (count != terms)
    {
        printf("Enter the %d term's exp and coeff of poly1: ", count);
        temp1 = (node *)malloc(sizeof(node));
        scanf("%d%d", &(temp1->exp), &(temp1->coeff));
        count++;
        start1->next=temp1;
        curr->next=temp1;
        curr=temp1;
    }
    curr->next=NULL;

    return 0;
}
