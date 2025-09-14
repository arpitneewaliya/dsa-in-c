// In this program we have learned how to create a Linked List using separate functions
// for creating and printing the linked List.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new Node.
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node *head) {
    struct node* temp = head;
    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = createNode(10);
    struct node *second = createNode(20);
    struct node *third = createNode(30);
    struct node *fourth = createNode(40);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    printList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
