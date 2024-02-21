#include <stdio.h>

int main() {
    int c, first, last, middle, n, search, array[100]; // Assuming a maximum size for the array

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &array[c]);
    }

    printf("Enter value to find: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (array[middle] < search) {
            first = middle + 1;
        } else if (array[middle] == search) {
            printf("%d is present at index %d.\n", search, middle + 1);
            break;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last) {
        printf("Not found! %d is not present in the array.\n", search);
    }

    return 0;
}
