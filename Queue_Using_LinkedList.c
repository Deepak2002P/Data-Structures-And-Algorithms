#include <stdio.h>
#include <stdlib.h>
struct Node*f=NULL;
struct Node*r=NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing The Elements of Linked List\n");
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){     // Special Case
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue(){
    int val=-1;
    struct Node*ptr=f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    linkedListTraversal(f);
    printf("Dequeuing Element:%d\n",dequeue());
    enqueue(6);
    enqueue(5);
    enqueue(4);
    linkedListTraversal(f);

    return 0;
}