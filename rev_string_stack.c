#include <stdio.h>
#include <stdlib.h>
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

void reverseSentence(char *sentence) {
    struct Stack stack;
    initStack(&stack);
    int len = strlen(sentence);

    for (int i = 0; i < len; i++) {
        if (sentence[i] != ' ')
            push(&stack, sentence[i]);
        else {
            while (!isEmpty(&stack))
                printf("%c", pop(&stack));
            printf(" ");
        }
    }

    while (!isEmpty(&stack))
        printf("%c", pop(&stack));
    printf("\n");
}

int main() {
    char sentence[MAX_SIZE];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    printf("Reversed sentence: ");
    reverseSentence(sentence);

    return 0;
}

