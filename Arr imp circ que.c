#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int* items;
    int front, rear, maxSize;
};

// Function to initialize a circular queue
struct CircularQueue* initializeCircularQueue(int maxSize) {
    struct CircularQueue* cq = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    cq->items = (int*)malloc(maxSize * sizeof(int));
    cq->front = -1;
    cq->rear = -1;
    cq->maxSize = maxSize;
    return cq;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->front == 0 && cq->rear == cq->maxSize - 1) || (cq->rear == (cq->front - 1) % (cq->maxSize - 1));
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->front == -1;
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full.\n");
        return;
    }
    if (cq->front == -1) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % cq->maxSize;
    cq->items[cq->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* cq) {
    int item;
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return -1;
    }
    item = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->maxSize;
    }
    printf("%d dequeued from queue.\n", item);
    return item;
}

// Function to display the elements in the circular queue
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in circular queue are:\n");
    if (cq->rear >= cq->front) {
        for (int i = cq->front; i <= cq->rear; i++) {
            printf("%d ", cq->items[i]);
        }
    } else {
        for (int i = cq->front; i < cq->maxSize; i++) {
            printf("%d ", cq->items[i]);
        }
        for (int i = 0; i <= cq->rear; i++) {
            printf("%d ", cq->items[i]);
        }
    }
    printf("\n");
}

int main() {
    int maxSize;
    printf("Enter the maximum size of the circular queue: ");
    scanf("%d", &maxSize);

    struct CircularQueue* cq = initializeCircularQueue(maxSize);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations\n");
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
                enqueue(cq, value);
                break;
            case 2:
                dequeue(cq);
                break;
            case 3:
                display(cq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
