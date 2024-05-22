#include <stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char val) {
    if (top >= MAX - 1) {
        printf("Stack is already full.\n");
    } else {
        top += 1;
        stack[top] = val;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return '\0';
    } else {
        char val = stack[top];
        top--;
        return val;
    }
}

int priority(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // '(' and ')'
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];
        int temp = ch - '0';
        if (isalpha(ch) || temp>=0 && temp <=9) {
            postfix[k] = ch;
            k++;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            char temp;
            temp=pop();
            while (temp != '(') {
                postfix[k++] = temp;
            }
        } else {
            while (top >= 0 && priority(stack[top]) >= priority(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while (top >= 0) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
