#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int arr[MAX_SIZE];
    int size;
};

// Function to initialize a priority queue
struct PriorityQueue* initializePriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    return pq;
}

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain heap property after insertion
void heapifyUp(struct PriorityQueue* pq, int index) {
    while (index > 0 && pq->arr[(index - 1) / 2] < pq->arr[index]) {
        swap(&pq->arr[(index - 1) / 2], &pq->arr[index]);
        index = (index - 1) / 2;
    }
}

// Function to insert an element into the priority queue
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }

    pq->arr[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Function to maintain heap property after deletion
void heapifyDown(struct PriorityQueue* pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->arr[left] > pq->arr[largest]) {
        largest = left;
    }

    if (right < pq->size && pq->arr[right] > pq->arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->arr[index], &pq->arr[largest]);
        heapifyDown(pq, largest);
    }
}

// Function to delete the highest priority element from the priority queue
int deleteMax(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int maxValue = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return maxValue;
}

// Function to display the elements in the priority queue
void display(struct PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* pq = initializePriorityQueue();
    int choice, value;

    while (1) {
        printf("\nPriority Queue Operations\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(pq, value);
                break;
            case 2:
                printf("Deleted element: %d\n", deleteMax(pq));
                break;
            case 3:
                display(pq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
