// Implementing stack using arrays.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct stack{
    int data[MAX_SIZE];
    int top;
} Stack;

// Check if stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if(isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d to stack\n", value);
}

int pop(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int value = stack->data[stack->top--];
    printf("Popped %d from stack\n", value);
    return value;
}

int peek(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return stack->data[stack->top];
}

void display(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int size(Stack *stack) {
    return stack->top + 1;
}

int main() {
    Stack stack;
    stack.top = -1;

    // Push elements
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);

    display(&stack);
    printf("Stack size: %d\n", size(&stack));
    printf("Top element: %d\n", peek(&stack));

    // Pop elements
    pop(&stack);
    pop(&stack);
    pop(&stack);

    display(&stack);
    printf("Stack size: %d\n", size(&stack));
    printf("Top element: %d\n", peek(&stack));

    return 0;
}
