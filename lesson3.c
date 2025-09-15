#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the beginning
void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = createNode(data);
    // The next pointer of the newNode will point to the first node
    newNode->next = *head;
    // Make the newNode the first node of the list
    *head = newNode;
}

// Insert at the end of the list
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    // If list is empty, the newNode will be the first node.
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // Make a temp pointer to traverse the list
    struct node *temp = *head;
    // Traverse the LL until the last node is found
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node *head) {
    struct node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the memory to avoid memory leaks
void freeList(struct node *head) {
    struct node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 100);

    printList(head);

    freeList(head);

    return 0;
}
