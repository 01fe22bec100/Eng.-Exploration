#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
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

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

void decimalToBinary(int num) {
    struct Stack stack;
    initStack(&stack);

    while (num > 0) {
        push(&stack, num % 2);
        num /= 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack))
        printf("%d", pop(&stack));
    printf("\n");
}

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    decimalToBinary(decimalNum);

    return 0;
}


