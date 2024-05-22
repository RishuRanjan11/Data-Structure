#include<stdio.h>
void insert_after_val( node *start, int val, int newval)
{
    search for a val and let p1 point to that node (use traverse logic)
    if ( vl!=exist)
    {
        insert not possible
        return;
    }
    newnode (node *)malloc(sizeof(node));
    newnode->data = val;
    temp = p1->next;
    newnode->next = temp;
    p1->next = newnode;
}