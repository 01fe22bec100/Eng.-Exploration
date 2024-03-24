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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortLinkedList(struct Node* head) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(&(ptr1->data), &(ptr1->next->data));
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;

    // Creating list: 3 -> 1 -> 5 -> 2 -> 4
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 3);

    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    sortLinkedList(head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}

