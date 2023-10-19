#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct List {
    int array[MAX_SIZE];
    int size;
};

struct List* createList() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->size = 0; // Initialize size to 0 for an empty list
    return list;
}

void insert(struct List* list, int data, int position) {
    if (list->size >= MAX_SIZE) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    
    if (position < 0 || position > list->size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    
    // Shift elements to the right to make space for the new element
    for (int i = list->size; i > position; i--) {
        list->array[i] = list->array[i - 1];
    }
    
    // Insert the new element at the specified position
    list->array[position] = data;
    list->size++;
}

void display(struct List* list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d -> ", list->array[i]);
    }
    printf("NULL\n");
}

int main() {
    struct List* myList = createList();

    insert(myList, 10, 0);
    insert(myList, 20, 1);
    insert(myList, 30, 1);

    display(myList);

    free(myList); // Don't forget to free memory when you're done
    return 0;
}
