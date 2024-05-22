#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *findMiddle(node *head)
{
    node *slow;
    node *fast;
    node *start;
    slow=fast=start=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    int option;
    node *start;
    start = (node *)malloc(sizeof(node));
    node *curr = start;
    printf("Enter the data for first node: ");
    scanf("%d",&(start->data));
    do
    {
        printf("Do you want more nodes? press 1/0: \n");
        scanf("%d", &option);

        if (option != 0)
        {
            node *temp1 = (node *)malloc(sizeof(node));
            printf("Enter data: ");
            scanf("%d", &(temp1->data));
            curr->next = temp1;
            curr = temp1;
        }

    } while (option);

    curr->next = NULL;
    node *temp = start;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }

    node *middle = findMiddle(start);
    printf("\n middle node: %d",middle->data);

    return 0;
}

