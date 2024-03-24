#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

bool isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    if (isEmpty(&queue))
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");



    return 0;
}

