#include <stdio.h>
#include <stdlib.h>
typedef struct dllnode
{
    int data;
    struct dllnode *next, *back;
} dllnode;

dllnode *create(dllnode *start)
{

    int option;
    dllnode *curr = start;
    do
    {
        printf("Choose 1 to insert and 0 to end: \n");
        scanf("%d", &option);
        if (option == 0)
            break;
        dllnode *temp = (dllnode *)malloc(sizeof(dllnode));
        if (temp == NULL)
        {
            printf("memory allocation fail. ");
            return start;
        }
        printf("Enter data: \n");
        scanf("%d", &(temp->data));
        temp->next = NULL;
        temp->back = curr;
        curr->next = temp;
        curr = curr->next;
    } while (option);
    return start;
}

void insert_after_val(dllnode *start, int val, int data)
{
    dllnode *p1;
    p1 = start;
    while (p1->data != val && p1->next != NULL)
    {
        p1 = p1->next;
    }
    dllnode *nextnode = p1->next;
    dllnode *newnode = (dllnode *)malloc(sizeof(dllnode));
    newnode->data = data;
    newnode->next = nextnode;
    newnode->back = p1;
    p1->next = newnode;
    if (nextnode != NULL)
    {
        nextnode->back = newnode;
    }
}

dllnode *delete_after_val(dllnode *start, int *val)
{
    dllnode *p1;
    p1 = start;
    while (p1->data != *val && p1->next != NULL)
    {
        p1 = p1->next;
    }
    dllnode *temp = p1->next;
    dllnode *nextnode = temp->next;
    *val = temp->data;
    if (nextnode != NULL)
        p1->next = nextnode;
    nextnode->back = p1;
    free(temp);
    return start;
}
void traverse_forward(dllnode *head)
{
    dllnode *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
void traverse_backward(dllnode *head)
{
    dllnode *temp = head;
    while (temp != NULL)
    {   
        temp = temp->next;
    }
    while(temp->back!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->back;
    }
}
int main(int argc, char const *argv[])
{
    int option;
    int val,data;
    dllnode *start;
    do
    {
    printf("choose 1 option: \n1. to create \n2.insert after val. \n3.delete after val\n4. traverse forward\n5. traverse backward\n 0. to exit\n");
    scanf("%d" ,&option);
    start->back==NULL;
    switch (option)
    {
    case 1:
        start = (dllnode *)malloc(sizeof(dllnode));
        printf("Enter 1st data: ");
        scanf("%d", &(start->data));
        create(start);
        break;
    case 2:
        printf("Enter the value after which data to be stored: ");
        scanf("%d",&val);
        printf("Enter the data: ");
        scanf("%d",&data);
        insert_after_val(start,val,data);
        break;
    case 3: 
        printf("Enter val");
        scanf("%d",&val);
        delete_after_val(start,&val);
        break;
    case 4: 
        traverse_forward(start);
        break;
    case 5:
        traverse_backward(start);
        break;


    default : break;
    
    }

    } while (option);
    return 0;
}
