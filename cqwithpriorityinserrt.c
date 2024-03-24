#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initCircularQueue(struct CircularQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(struct CircularQueue *queue) {
    return queue->size == 0;
}

int isFull(struct CircularQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
    queue->size++;
}

void priorityEnqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        enqueue(queue, value);
        return;
    }
    int i = queue->rear;
    while (i != queue->front && value > queue->arr[i]) {
        queue->arr[(i + 1) % MAX_SIZE] = queue->arr[i];
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
    }
    queue->arr[(i + 1) % MAX_SIZE] = value;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->size++;
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return data;
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue: ");
    int i = queue->front;
    int count = 0;
    while (count < queue->size) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initCircularQueue(&queue);

    priorityEnqueue(&queue, 2);
    priorityEnqueue(&queue, 4);
    priorityEnqueue(&queue, 1);
    priorityEnqueue(&queue, 3);

    printf("Priority Queue: ");
    display(&queue);

    return 0;
}

