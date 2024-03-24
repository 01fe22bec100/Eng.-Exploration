#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char *exp) {
    struct Stack stack;
    initStack(&stack);

    printf("Postfix Expression: ");
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i]))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            push(&stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(')
                printf("%c", pop(&stack));
            if (!isEmpty(&stack) && stack.arr[stack.top] != '(')
                printf("Invalid Expression\n");
            else
                pop(&stack);
        } else {
            while (!isEmpty(&stack) && precedence(exp[i]) <= precedence(stack.arr[stack.top]))
                printf("%c", pop(&stack));
            push(&stack, exp[i]);
        }
    }

    while (!isEmpty(&stack))
        printf("%c", pop(&stack));
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);
    printf("\n");

    return 0;
}

