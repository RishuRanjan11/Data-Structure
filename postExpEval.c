#include <stdio.h>
#include <math.h>

#define MAX 100

float postfixExp[MAX];
int top = -1;

void push(float val)
{
    if (top >= MAX - 1)
    {
        printf("Stack is already full.\n");
    }
    else
    {
        top += 1;
        postfixExp[top] = val;
    }
}

float pop()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else
    {
        float val = postfixExp[top];
        top--;
        return val;
    }
}

float postfixEvaluation(char postfixExp[MAX])
{
    int i = 0;
    float res;
    float v1, v2;

    while (postfixExp[i] != '\0')
    {
        int temp = postfixExp[i] - '0'; // Convert char to int
        if (temp >= 0 && temp <= 9)
        {
            push(temp);
        }
        else
        {
            v2 = pop();
            v1 = pop();
            switch (postfixExp[i])
            {
            case '+':
                res = v1 + v2;
                break;
            case '-':
                res = v1 - v2;
                break;
            case '*':
                res = v1 * v2;
                break;
            case '/':
                res = v1 / v2;
                break;
            case '^':
                res = pow(v1, v2);
                break;
            default:
                printf("Invalid operator: %c\n", postfixExp[i]);
                return -1;
            }
            push(res);
        }
        i++;
    }
    res = pop();
    return res;
}

int main()
{
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    float result = postfixEvaluation(postfix);
    if (result != -1)
    {
        printf("Result of evaluation: %.2f\n", result);
    }

    return 0;
}
