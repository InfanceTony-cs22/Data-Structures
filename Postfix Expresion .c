#include <stdio.h>
#include <ctype.h> // Include this header for isdigit function

#define MAX_SIZE 100 // Define maximum size for the stack

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return some default value indicating underflow
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    char* e;
    int n1, n2, result;
    
    // Iterate through each character in the expression
    for (e = exp; *e != '\0'; e++) {
        // If the character is a digit, push it onto the stack
        if (isdigit(*e)) {
            push(*e - '0'); // Convert char to int
        } else {
            // If it's an operator, pop two operands, perform the operation, and push the result back onto the stack
            n2 = pop();
            n1 = pop();
            switch (*e) {
                case '+': push(n1 + n2); break;
                case '-': push(n1 - n2); break;
                case '*': push(n1 * n2); break;
                case '/': push(n1 / n2); break;
                // Add more cases for other operators as needed
            }
        }
    }
    // After iterating through the expression, the final result should be at the top of the stack
    result = pop();
    return result;
}

int main() {
    char exp[203];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
