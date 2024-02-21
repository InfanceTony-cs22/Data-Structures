#include <stdio.h>
#include <stdlib.h>

// Define a structure for representing a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial (linked list)
void insertTerm(struct Term** polynomial, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        struct Term* temp = *polynomial;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term* polynomial) {
    if (polynomial == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct Term* temp = polynomial;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* temp1 = poly1;
    struct Term* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            insertTerm(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertTerm(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            insertTerm(&result, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Add remaining terms of poly1
    while (temp1 != NULL) {
        insertTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    // Add remaining terms of poly2
    while (temp2 != NULL) {
        insertTerm(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to free memory allocated for a polynomial
void freePolynomial(struct Term* polynomial) {
    struct Term* temp;
    while (polynomial != NULL) {
        temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    int terms, coefficient, exponent;

    // Input polynomial 1
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &terms);
    printf("Enter the terms for polynomial 1 (coefficient exponent):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    // Input polynomial 2
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &terms);
    printf("Enter the terms for polynomial 2 (coefficient exponent):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* sum = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    // Free memory allocated for polynomials
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}
