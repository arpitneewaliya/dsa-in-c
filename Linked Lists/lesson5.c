#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct node **head, int value) {
    struct node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node after a given node in the linked list
void insertAfter(struct node *head, int newValue, int key) {
    struct node *newNode = createNode(newValue);
    struct node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Node NOT found!\n");
}

// Insert a new node before a given node in the linked list
void insertBefore(struct node *head, int newValue, int key) {
    struct node *newNode = createNode(newValue);
    struct node *current = head;
    while(current->next != NULL) {
        if (current->next->data == key) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Node NOT found\n");
}

// Insert a new node at a given position in the linked list
void insertAtPos(struct node *head, int newValue, int pos) {
    struct node *newNode = createNode(newValue);
    struct node *current = head;
    for (int i=1; i<pos-1; i++)
        current = current->next;
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(struct node **head, int newValue) {
    struct node *newNode = createNode(newValue);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    newNode->next = NULL;
    current->next = newNode;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("Linked List is EMPTY!\n");
        exit(1);
    }
    struct node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 1);
    printList(head);

    insertAfter(head, 6, 1);
    printList(head);

    insertBefore(head, 5, 6);
    printList(head);

    insertAtPos(head, 4, 2);
    printList(head);

    insertAtEnd(&head, 100);
    printList(head);
    return 0;
}
