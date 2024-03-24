#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int binaryToDecimal(char *binaryNum) {
    struct Stack stack;
    initStack(&stack);
    int decimal = 0;
    int len = strlen(binaryNum);

    for (int i = 0; i < len; i++) {
        if (binaryNum[i] != '0' && binaryNum[i] != '1') {
            printf("Invalid binary number\n");
            exit(EXIT_FAILURE);
        }
        push(&stack, binaryNum[i] - '0');
    }

    int power = 0;
    while (!isEmpty(&stack)) {
        decimal += pop(&stack) * pow(2, power);
        power++;
    }

    return decimal;
}

int main() {
    char binaryNum[MAX_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", binaryNum);

    int decimalNum = binaryToDecimal(binaryNum);
    printf("Decimal equivalent: %d\n", decimalNum);

    return 0;
}

