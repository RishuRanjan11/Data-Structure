#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top >= MAX - 1)
    {
        printf("Stack is already full.\n");
    }
    else
    {
        top += 1;
        stack[top] = val;
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        int val = stack[top];
        top--;
        return val;
    }
}

void displayElement()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, val, option = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the values of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        push(val);
    }

    while (option != 4)
    {
        printf("\nChoose one option:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack elements\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            printf("Popped value: %d\n", pop());
            break;
        case 3:
            displayElement();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option chosen.\n");
        }
    }

    return 0;
}
