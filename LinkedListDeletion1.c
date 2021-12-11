#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate Memory of the nodes of linked list in the Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    //Link first and second Node
    head->data = 4;
    head->next = second;
    //Link second and third Node
    second->data = 3;
    second->next = third;
    //Link third and fourth Node
    third->data = 8;
    third->next = fourth;
    //Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Elements Before Deletion:\n");
    LinkedListTraversal(head);

    head = deleteFirst(head);
    printf("Elements After Deletion:\n");
    LinkedListTraversal(head);
}