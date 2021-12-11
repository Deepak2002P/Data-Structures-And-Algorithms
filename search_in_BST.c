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

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct node* search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
       return search(root->right, key); 
    }
    
}

int main()
{
    // Constructing the root node-using Function
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
   // Linking the Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
/* Binary Search Tree
         5
        / \
       3   6
      / \
     1   4
*/
struct node* n=search(p,10);
    if(n!=NULL){
        printf("Element Found: %d",n->data);
    }
    else{
        printf("Element is not found");
    }
    return 0;
}
