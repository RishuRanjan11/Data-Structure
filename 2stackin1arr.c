#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;  // Top pointer for stack 1
int top2 = MAX; // Top pointer for stack 2

// Function to push element onto stack 1
void push1(int val)
{
    if (top1 + 1 == top2)
    {
        printf("Stack overflow\n");
        return;
    }
    arr[++top1] = val;
}

// Function to pop element from stack 1
int pop1()
{
    if (top1 == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return arr[top1--];
}

// Function to push element onto stack 2
void push2(int val)
{
    if (top2 - 1 == top1)
    {
        printf("Stack overflow\n");
        return;
    }
    arr[--top2] = val;
}

// Function to pop element from stack 2
int pop2()
{
    if (top2 == MAX)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return arr[top2++];
}

int main()
{
    int option;
    int val;
    do
    {
        printf("Choose your option: \n");
        printf("1 to push in stack1\n2 to push in stack2\n3 to pop from stack1\n4 to pop from stack2\n'E' to exit.\n");
        scanf(" %c", &option);
        switch (option)
        {
        case '1':
            scanf("%d", &val);
            push1(val);
            break;
        case '2':
            scanf("%d", &val);
            push2(val);
            break;
        case '3':
            printf("Poped value from stack1: %d", pop1());
            break;
        case '4':
            scanf("%d", &val);
            printf("Poped value from stack2: %d", pop2());
            break;
        case 'e':
        case 'E':
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.") break;
        }
    } while (option != 'e' || option != 'E');

    return 0;
}
