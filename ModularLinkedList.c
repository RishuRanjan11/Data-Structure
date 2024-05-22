#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *create()
{
    int option;
    node *start;
    start = (node *)malloc(sizeof(node));
    node *curr = start;
    printf("Enter the data for first node: ");
    scanf("%d", &(start->data));
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
    return start;
}

void traverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int search(int val, node *head)
{
    int pos = 1;
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        if ((temp->data) == val)
        {
            return pos;
        }
        temp = temp->next;
        pos += 1;
    }
    return -1;
}

int Exit()
{
    printf("Exiting...\n");
    return 0;
}

int main()
{
    int option;
    int val;
    do
    {
        printf("Select your option: \n");
        printf("1. to create a node.\n");
        printf("2. to traverse.\n");
        printf("3. to search for a value.\n");
        printf("4. to exit.");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            traverse(start);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            int pos = search(val, start);
            if (pos != -1)
            {
                printf("The value %d is found at position %d", val, pos);
            }
            break;
        case 4:
            Exit();
            break;

        default:
            printf("Invalid option.");
            break;
        }

    } while (option != 4);

    return 0;
}
