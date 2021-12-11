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

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
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

  PreOrder->  2 1 5 6 4
  InOrder->   5 1 6 2 4 
  PostOrder-> 5 6 1 4 2 
*/
    preOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    postOrder(p);
    return 0;
}
