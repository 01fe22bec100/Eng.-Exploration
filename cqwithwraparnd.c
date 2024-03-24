#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initCircularQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    return data;
}

int main() {
    struct CircularQueue queue;
    initCircularQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeuing elements: ");
    while (!isEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}

