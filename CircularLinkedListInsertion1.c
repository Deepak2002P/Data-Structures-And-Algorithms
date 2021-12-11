#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// void linkedListTraversal(struct Node *head)
// {
//     struct Node *ptr = head;
//     printf("Element is:%d\n", ptr->data);
//     ptr = ptr->next;
//     while (ptr != head)
//     {
//         printf("Element is:%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is:%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this Point p points to the last Node of this Circular Linked List
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocte Memory of Nodes of Circular Linked List in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link First and Second Nodes
    head->data = 4;
    head->next = second;

    // link Second and Third Nodes
    second->data = 3;
    second->next = third;

    // link Third and Fourth Nodes
    third->data = 6;
    third->next = fourth;

    // link Fourth and First Node
    fourth->data = 1;
    fourth->next = head;

    printf("\nElements Before Insertion are:\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    printf("\nElements After Insertion are:\n");
    linkedListTraversal(head);
    return 0;
}
