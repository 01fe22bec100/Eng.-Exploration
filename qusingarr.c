#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
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

void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) // If there's only one element in the queue
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    return data;
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->arr[queue->front];
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Front element: %d\n", peek(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}

