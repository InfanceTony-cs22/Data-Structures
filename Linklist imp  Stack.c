#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Structure for the stack
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Elements of stack are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = initializeStack();

    int choice, data;
    while (1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                printf("Popped element: %d\n", pop(stack));
                break;
            case 3:
                printf("Top element of stack: %d\n", peek(stack));
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
