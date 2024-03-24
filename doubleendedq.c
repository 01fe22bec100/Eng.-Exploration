#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->arr[deque->front] = value;
}

void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->arr[deque->rear] = value;
}

int deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    return data;
}

int deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return data;
}

void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->arr[i]);
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    insertFront(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 3);
    insertRear(&deque, 4);

    display(&deque);

    printf("Deleted front element: %d\n", deleteFront(&deque));
    printf("Deleted rear element: %d\n", deleteRear(&deque));

    display(&deque);

    return 0;
}

