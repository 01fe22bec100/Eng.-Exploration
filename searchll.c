#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i > 0; i--)
        insertAtBeginning(&head, i);

    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    int key = 3;
    if (search(head, key))
        printf("Element %d is present in the Linked List.\n", key);
    else
        printf("Element %d is not present in the Linked List.\n", key);

    return 0;
}

