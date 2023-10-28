#include <stdio.h>

// Define a structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
};

// Function to add two polynomials
void addPolynomials(struct Term polyA[], int sizeA, struct Term polyB[], int sizeB, struct Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (polyA[i].exponent > polyB[j].exponent) {
            result[k] = polyA[i];
            i++;
        } else if (polyA[i].exponent < polyB[j].exponent) {
            result[k] = polyB[j];
            j++;
        } else {
            result[k].exponent = polyA[i].exponent;
            result[k].coefficient = polyA[i].coefficient + polyB[j].coefficient;
            i++;
            j++;
        }
        k++;
    }

    // Copy the remaining terms from polyA and polyB
    while (i < sizeA) {
        result[k] = polyA[i];
        i++;
        k++;
    }
    while (j < sizeB) {
        result[k] = polyB[j];
        j++;
        k++;
    }
}

int main() {
    struct Term polyA[] = { {2, 3}, {3, 2}, {4, 1}, {1, 0} };
    int sizeA = 4;

    struct Term polyB[] = { {5, 2}, {2, 1}, {7, 0} };
    int sizeB = 3;

    // The result will have at most sizeA + sizeB terms
    struct Term result[sizeA + sizeB];

    addPolynomials(polyA, sizeA, polyB, sizeB, result);

    int resultSize = sizeA + sizeB;
    printf("Result: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%dx^%d ", result[i].coefficient, result[i].exponent);
        if (i < resultSize - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    return 0;
}


Result: 2x^3 + 8x^2 + 6x^1 + 8x^0
