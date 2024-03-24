#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct PriorityQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initPriorityQueue(struct PriorityQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(struct PriorityQueue *queue) {
    return queue->size == 0;
}

int isFull(struct PriorityQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(struct PriorityQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Priority queue overflow\n");
        exit(EXIT_FAILURE);
    }
    int i;
    if (isEmpty(queue)) {
        queue->arr[++queue->rear] = value;
    } else {
        for (i = queue->rear; i >= queue->front; i--) {
            if (value > queue->arr[i]) {
                queue->arr[i + 1] = queue->arr[i];
            } else {
                break;
            }
        }
        queue->arr[i + 1] = value;
        queue->rear++;
    }
    queue->size++;
}

int dequeue(struct PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->arr[queue->front++];
    queue->size--;
    return data;
}

void display(struct PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue queue;
    initPriorityQueue(&queue);

    enqueue(&queue, 3);
    enqueue(&queue, 6);
    enqueue(&queue, 1);
    enqueue(&queue, 9);

    display(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}

