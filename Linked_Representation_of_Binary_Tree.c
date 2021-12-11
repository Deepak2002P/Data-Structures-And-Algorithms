#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node*n;  // Creating a node pointer
    n=(struct node*)malloc(sizeof(struct node)); // Allocating Memory in heap
    n->data=data; // Setting the data
    n->left=NULL; // Setting the Left Children to NULL
    n->right=NULL; // Setting the right Children to NULL
    return n; // Finally returning the Created node
}

int main()
{
    // Constructing the root node-using Function
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(6);
   // Linking the Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
/*       2
        / \
       1   4
      / \
     5   6
*/
    return 0;
}
