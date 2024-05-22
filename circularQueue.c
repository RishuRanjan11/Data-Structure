#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = 0, rear = 0;

void insertq(int val)
{
    if ((rear + 1) % MAX == front)
        printf("Queue is full.\n");
    else
    {

        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}

int deleteq()
{

    if (front == 0)
    {
        printf("Queue is empty.\n");
        return -100;
    }
    else
    {
        int val = queue[front];
        if (front == rear)
            front = rear = 0;
        else
            front = (front + 1) % MAX;
        return val;
    }
}

void displayq()
{
    if (front < 0)
        printf("Queue is empty.\n");
    else
    {
        printf("Queue = [ ");
        int i = front + 1;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ]\n", queue[rear]);
    }
}

int main()
{
    int val;
    char option;
    do
    {
        printf("Choose your option: \n");
        printf("'1' to insert\n'2' to delete\n'3' to display\n'E' to exit\n");
        scanf(" %c", &option);
        switch (option)
        {
        case '1':
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insertq(val);
            break;
        case '2':
            val = deleteq();
            if (val != -100)
            {
                printf("Deleted Value: %d\n", val);
            }
            break;
        case '3':
            displayq();
            break;
        case 'e':
        case 'E':
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid option.\n");
            break;
        }
    } while (option != 'e' && option != 'E');

    return 0;
}
