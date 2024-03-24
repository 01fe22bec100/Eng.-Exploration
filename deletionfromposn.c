#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i > 0; i--)
        insertAtBeginning(&head, i);

    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    reverse(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}

