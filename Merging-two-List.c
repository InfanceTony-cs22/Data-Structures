#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node dummy; // Create a dummy node
    struct Node* tail = &dummy; // Initialize the tail to the dummy node

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        }
        if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    return dummy.next; // Return the merged list starting from the next node of the dummy
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    // Free memory for the lists
    free(list1);
    free(list2);
    free(mergedList);

    return 0;
}
