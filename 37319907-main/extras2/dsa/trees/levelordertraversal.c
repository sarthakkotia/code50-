#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}tree;

tree * newnode(int data)
{
    tree *node = malloc(sizeof(tree));
    node->data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int max(int a , int b)
{
    if(b>a)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int height(tree *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+max(height(node->left),height(node->right));
}

void printlevel(tree *node , int i)
{
    if(node==NULL)
    {
        return;
    }
    if(i ==1)
    {
        printf("%d ",node->data);
        return;
    }
    else if(i>1)
    {
        printlevel(node->left ,i-1);
        printlevel(node->right,i-1);
    }
}

void levelorder(tree *node)
{
    int h = height(node);
    for(int i = 1;i<=h;i++)
    {
        printlevel(node,i);
    }
}

int main(void)
{
    tree *root = newnode(1);
    root -> left = newnode(2);
    root -> right = newnode(3);
    root->left->left = newnode(4);
    root -> left ->right = newnode(5);

    levelorder(root);
}