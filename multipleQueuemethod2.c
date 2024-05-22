#include <stdio.h>
#define MAX 100

int queue[MAX];
int front[4] = {-1, -1, -1, -1}; // Front of each queue
int rear[4] = {-1, -1, -1, -1};  // Rear of each queue
int size = MAX / 4;              // Size of each queue

void insertq(int i, int val)
{
    if (rear[i - 1] == MAX - 1)
    {
        printf("Queue %d is full.\n", i);
    }
    else
    {
        if (front[i - 1] == -1)
        { // If queue is empty, reset the queue
            front[i - 1] = rear[i - 1] = 0;
            queue[front[i - 1]] = val;
        }
        else
        {
            rear[i - 1] = (rear[i - 1] + 1) % MAX; // Update rear index with wrap-around
            queue[rear[i - 1]] = val;
        }
    }
}

int deleteq(int i)
{
    if (front[i - 1] == -1)
    {
        printf("Queue %d is empty.\n", i);
        return -1;
    }
    else
    {
        int val = queue[front[i - 1]];
        if (front[i - 1] == rear[i - 1])
        {
            // Reset front and rear indices when queue becomes empty
            front[i - 1] = -1;
            rear[i - 1] = -1;
        }
        else
        {
            front[i - 1] = (front[i - 1] + 1) % MAX; // Update front index
        }
        return val;
    }
}

void display(int i)
{
    if (front[i - 1] == -1)
    {
        printf("Queue %d is empty.\n", i);
        return;
    }
    else
    {
        printf("Queue %d: ", i);
        int j = front[i - 1];
        while (j != rear[i - 1])
        {
            printf("%d ", queue[j]);
            j = (j + 1) % MAX; // Update index with wrap-around
        }
        printf("%d\n", queue[j]); // Display last element
    }
}

int main()
{
    int option, i, val;
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Insert into Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter queue number (1-4): ");
            scanf("%d", &i);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertq(i, val);
            break;
        case 2:
            printf("Enter queue number (1-4): ");
            scanf("%d", &i);
            printf("Deleted value from Queue %d: %d\n", i, deleteq(i));
            break;
        case 3:
            printf("Enter queue number (1-4): ");
            scanf("%d", &i);
            display(i);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option.\n");
            break;
        }
    }
}
