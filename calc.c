#include <stdio.h>

double calculate(double a, double b, char operator)
{
    double result;

    switch (operator)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        printf("Error: Invalid operator!\n");
        result = 0;
    }

    return result;
}

int main()
{
    double a, b;
    char op;
    int testCase;
    printf("Enter the number of testcases: ");
    scanf("%d", &testCase);
    do
    {
        printf("Enter the num1: ");
        scanf("%lf", &a);
        printf("Enter the operator: ");
        scanf(" %c", &op);
        printf("Enter the num2: ");
        scanf("%lf", &b);
        printf("%.3lf \n", calculate(a, b, op));
        testCase--;
    } while (testCase > 0);

    return 0;
}
