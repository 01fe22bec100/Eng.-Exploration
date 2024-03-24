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

    int choice, value;
    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                if (!isEmpty(&queue))
                    printf("Dequeued element: %d\n", dequeue(&queue));
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
