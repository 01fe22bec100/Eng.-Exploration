#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

bool isPalindrome(char *str) {
    struct Stack stack;
    initStack(&stack);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        push(&stack, str[i]);

    for (int i = 0; i < len; i++) {
        if (pop(&stack) != str[i])
            return false;
    }
    return true;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}

