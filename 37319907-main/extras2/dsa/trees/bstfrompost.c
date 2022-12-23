#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * createnode(int val)
{
    tree *node = malloc(sizeof(tree));
    node -> data = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

tree * create(tree *node , int data)
{
    if(node == NULL)
    {
        node = createnode(data);
    }
    else if(data < node -> data)
    {
        node->left = create(node->left,data);
    }
    else if(data > node->data)
    {
        node->right = create(node->right,data);
    }
    return node;
}

void inorder(tree *node)
{
    if(node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

int main(void)
{
    int post[] = {1,7,5,50,40,10};
    int size = sizeof(post)/sizeof(int);
    tree *root= NULL;
    root = create(root , post[size-1]);
    for(int i=0;i<size-1;i++)
    {
        root = create(root , post[i]);
    }
    inorder(root);
}