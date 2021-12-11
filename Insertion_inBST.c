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

void insert(struct node* root, int key){
    struct node* prev=NULL;
    while (root!=NULL)
    {
        prev=root;
        if(key==root->data){
            printf("Cannot Insert %d,already in BST",key);
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new=createNode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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
    inOrder(p);
    insert(p,16);
    printf("\n");
    inOrder(p);
/* Binary Search Tree After Insertion of 16
         5
        / \
       3   6
      / \   \
     1   4   16
*/
    return 0;
}
