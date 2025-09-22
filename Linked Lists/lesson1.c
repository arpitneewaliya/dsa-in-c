// In this program we have learned how to create a linked list and print all its elements
// without using separate functions.

#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure for a node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    // 2. Declare four node pointers
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;

    // 3. Allocate memory for each node
    // malloc() reserves a block of memory and returns a pointer to it.
    // (struct Node*) is used to cast the returned void pointer to a Node pointer.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL || fourth == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error code
    }

    // 4. Assign data and link the nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    // 5. Traverse the list and print the data
    struct node *current = head; // Start from the beginning of the list
    printf("Linked List: ");
    // Keep looping until we reach the end
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    // 6. Free the memory to avoid memory leaks
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
