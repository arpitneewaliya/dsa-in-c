#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to find the length of the linked list
int length_of_linked_list(struct node *head)
{
    struct node *current = head;
    int count = 0;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

// To print the linked list
void printList(struct node *head)
{
    struct node *current = head;
    printf("Linked list: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Searching an element in the list
int searchList(struct node *head, int value)
{
    struct node *current = head;
    int count = 1;
    while (current != NULL)
    {
        if (current->data == value)
            return count;
        count++;
        current = current->next;
    }
    return -1;
}

int main()
{
    struct node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("Length of Linked List = %d\n", length_of_linked_list(head));
    printList(head);
    int searchNum;
    printf("Enter the element you want to search: ");
    scanf("%d", &searchNum);
    int position = searchList(head, searchNum);
    if (position != -1)
        printf("Element found! In node no. %d\n", position);
    else
        printf("Element NOT found in the list.\n");
    return 0;
}
