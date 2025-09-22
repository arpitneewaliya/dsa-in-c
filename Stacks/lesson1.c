#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Push operation
void push(struct Node **top, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(struct Node *top) {
    return top == NULL;
}

int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack is underflow, cannot add element.\n");
        return -1;
    }
    struct Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

void display(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *current = top;
    printf("Stack: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL;
    int n;
    printf("How many elements you want to enter: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        printf("Enter element %d:", i+1);
        scanf("%d", &x);
        push(&top, x);
    }
    display(top);
    printf("Popped element: %d\n", pop(&top));
    display(top);
}
