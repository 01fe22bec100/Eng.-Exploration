#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* mergedList = NULL;

    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }

    return mergedList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Creating list1: 1 -> 3 -> 5
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Creating list2: 2 -> 4 -> 6
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);
    printf("\n");

    printf("List 2: ");
    printList(list2);
    printf("\n");

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted List: ");
    printList(mergedList);

    return 0;
}

