#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node next;
} node;

node *insertAtPos(node *start, int pos, int val, int newval)
{
    if (pos == 1)
    {
        start = insert_at_start(start, newval) return start;
    }
    int count 1;
    node *p1 = start;
    while (count < pos - 1 && p1 != NULL)
    {
        p1 = p1->next;
        count++;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = newval;
    node *temp = p1->next;
    newnode->next = temp;
    p1->next= newnode
    return start;
}
