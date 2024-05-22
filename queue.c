#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;

void insertq(int val)
{
    if (rear >= MAX - 1)
        printf("Queue is full.\n");
    else
    {
        if(front==-1)
            front=0;
        rear++;
        queue[rear] = val;
    }
}

int deleteq()
{
    int val;
    if (rear <= front)
        printf("Queue is empty.\n");
    else
    {
        val = queue[front];
        front+=1;
    }
    return val;
}

void displayq()
{
    if (front >= rear)
        printf("Queue is empty.\n");
    else
    {
        printf("Queue = [ ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("]\n");
    }
}

void compactq()
{
    int j = 0;
    for (int i = front; i <= rear; i++)
    {
        queue[j] = queue[i];
        j++;
    }
    rear = rear - front;
    front = 0;
}

int main()
{
    int val;
    char option;
    do
    {
        printf("Choose your option: \n");
        printf("'1' to insert\n'2' to delete\n'3' to display\n'4' to compact\n'E' to exit\n");
        scanf(" %c", &option);
        switch (option)
        {
        case '1':
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insertq(val);
            break;
        case '2':
            printf("Deleted Value: %d\n", deleteq());
            break;
        case '3':
            displayq();
            break;
        case '4':
            compactq();
            break;
        case 'e':
        case 'E':
            printf("Exiting...\n");
            return 0;
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    } while (option != 'e' && option != 'E');

    return 0;
}
