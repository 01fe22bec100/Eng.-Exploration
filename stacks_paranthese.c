#include <stdio.h>
#include <stdlib.h>

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

int isBalanced(char *exp) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(&stack, exp[i]);
        else if (exp[i] == ')') {
            if (isEmpty(&stack) || pop(&stack) != '(')
                return 0;
        }
    }

    return isEmpty(&stack);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter the expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Expression is balanced\n");
    else
        printf("Expression is not balanced\n");

    return 0;
}

