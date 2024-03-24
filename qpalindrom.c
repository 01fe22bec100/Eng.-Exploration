#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    char arr[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(struct Queue *queue, char value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}

char dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    char data = queue->arr[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    return data;
}

bool isPalindrome(char *str) {
    struct Queue queue;
    initQueue(&queue);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        enqueue(&queue, str[i]);

    for (int i = 0; i < len; i++) {
        if (dequeue(&queue) != str[i])
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

