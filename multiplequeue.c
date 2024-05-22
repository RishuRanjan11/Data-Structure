#include <stdio.h>
#define MAX 100
#define NUM_QUEUES 4 // Define the number of queues

int arr[MAX];
int size = MAX / NUM_QUEUES;                           // Size of each queue segment
int front1 = 0, rear1 = -1;                            // Front and rear pointers for queue 1
int front2 = MAX / 4 - 1, rear2 = MAX / 4 - 1;         // Front and rear pointers for queue 2
int front3 = MAX / 2 - 1, rear3 = MAX / 2 - 1;         // Front and rear pointers for queue 3
int front4 = 3 * MAX / 4 - 1, rear4 = 3 * MAX / 4 - 1; // Front and rear pointers for queue 4

// Function to insert element into queue 1
void insertq1(int val)
{
    if (rear1 - front1 == size - 1)
    {
        printf("Queue 1 is full.\n");
        return;
    }
    rear1 = (rear1 + 1) % MAX;
    arr[rear1] = val;
}

// Function to delete element from queue 1
int deleteq1()
{
    if (front1 > rear1)
    {
        printf("Queue 1 is empty.\n");
        return -1;
    }
    int val = arr[front1];
    front1 = (front1 + 1) % MAX;
    return val;
}

// Function to insert element into queue 2
void insertq2(int val)
{
    if (rear2 - front2 == size - 1)
    {
        printf("Queue 2 is full.\n");
        return;
    }
    rear2 = (rear2 + 1) % MAX;
    arr[rear2] = val;
}

// Function to delete element from queue 2
int deleteq2()
{
    if (front2 > rear2)
    {
        printf("Queue 2 is empty.\n");
        return -1;
    }
    int val = arr[front2];
    front2 = (front2 + 1) % MAX;
    return val;
}

// Function to insert element into queue 3
void insertq3(int val)
{
    if (rear3 - front3 == size - 1)
    {
        printf("Queue 3 is full.\n");
        return;
    }
    rear3 = (rear3 + 1) % MAX;
    arr[rear3] = val;
}

// Function to delete element from queue 3
int deleteq3()
{
    if (front3 > rear3)
    {
        printf("Queue 3 is empty.\n");
        return -1;
    }
    int val = arr[front3];
    front3 = (front3 + 1) % MAX;
    return val;
}

// Function to insert element into queue 4
void insertq4(int val)
{
    if (rear4 - front4 == size - 1)
    {
        printf("Queue 4 is full.\n");
        return;
    }
    rear4 = (rear4 + 1) % MAX;
    arr[rear4] = val;
}

// Function to delete element from queue 4
int deleteq4()
{
    if (front4 > rear4)
    {
        printf("Queue 4 is empty.\n");
        return -1;
    }
    int val = arr[front4];
    front4 = (front4 + 1) % MAX;
    return val;
}

// Function to display elements of a specified queue
void displayq(int queue_num)
{
    int front, rear;
    switch (queue_num)
    {
    case 1:
        front = front1;
        rear = rear1;
        break;
    case 2:
        front = front2;
        rear = rear2;
        break;
    case 3:
        front = front3;
        rear = rear3;
        break;
    case 4:
        front = front4;
        rear = rear4;
        break;
    default:
        printf("Invalid queue number.\n");
        return;
    }

    if (front > rear)
    {
        printf("Queue %d is empty.\n", queue_num);
        return;
    }

    printf("Queue %d: ", queue_num);
    while (front != rear)
    {
        printf("%d ", arr[front]);
        front = (front + 1) % MAX;
    }
    printf("%d\n", arr[rear]);
}

int main()
{
    int option, val;
    while (1)
    {
        printf("Choose an option:\n");
        printf("1. Insert into Queue 1\n");
        printf("2. Delete from Queue 1\n");
        printf("3. Insert into Queue 2\n");
        printf("4. Delete from Queue 2\n");
        printf("5. Insert into Queue 3\n");
        printf("6. Delete from Queue 3\n");
        printf("7. Insert into Queue 4\n");
        printf("8. Delete from Queue 4\n");
        printf("9. Display Queue 1\n");
        printf("10. Display Queue 2\n");
        printf("11. Display Queue 3\n");
        printf("12. Display Queue 4\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value to insert into Queue 1: ");
            scanf("%d", &val);
            insertq1(val);
            break;
        case 2:
            printf("Deleted value from Queue 1: %d\n", deleteq1());
            break;
        case 3:
            printf("Enter value to insert into Queue 2: ");
            scanf("%d", &val);
            insertq2(val);
            break;
        case 4:
            printf("Deleted value from Queue 2: %d\n", deleteq2());
            break;
        case 5:
            printf("Enter value to insert into Queue 3: ");
            scanf("%d", &val);
            insertq3(val);
            break;
        case 6:
            printf("Deleted value from Queue 3: %d\n", deleteq3());
            break;
        case 7:
            printf("Enter value to insert into Queue 4: ");
            scanf("%d", &val);
            insertq4(val);
            break;
        case 8:
            printf("Deleted value from Queue 4: %d\n", deleteq4());
            break;
        case 9:
            displayq(1);
            break;
        case 10:
            displayq(2);
            break;
        case 11:
            displayq(3);
            break;
        case 12:
            displayq(4);
            break;
        case 13:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }
}
