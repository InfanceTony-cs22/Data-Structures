#include <stdio.h>
#include <stdlib.h>

// Function to add two polynomials
int* addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int* resultDegree) {
    // Find the maximum degree
    *resultDegree = (degree1 > degree2) ? degree1 : degree2;
    
    // Create an array for the result polynomial
    int* result = (int*)malloc((*resultDegree + 1) * sizeof(int));
    
    // Initialize the result polynomial with zeros
    for (int i = 0; i <= *resultDegree; i++) {
        result[i] = 0;
    }

    // Add coefficients from the first polynomial
    for (int i = 0; i <= degree1; i++) {
        result[i] += poly1[i];
    }

    // Add coefficients from the second polynomial
    for (int i = 0; i <= degree2; i++) {
        result[i] += poly2[i];
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i > 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int poly1[] = {2, 0, 1}; // 2x^2 + 1
    int degree1 = 2;

    int poly2[] = {3, 4, 0, 1}; // 3x^3 + 4x^2 + 1
    int degree2 = 3;

    int resultDegree;
    int* result = addPolynomials(poly1, degree1, poly2, degree2, &resultDegree);

    printf("Polynomial 1: ");
    displayPolynomial(poly1, degree1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, degree2);

    printf("Sum: ");
    displayPolynomial(result, resultDegree);

    free(result);

    return 0;
}
