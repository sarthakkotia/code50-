#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * create(int val)
{
    tree *node = malloc(sizeof(tree));
    node->data = val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int max(int a , int b)
{
    if(b>a)
    {
        return b;
    }
    return a;
}

int height(tree *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+(max(height(node->left),height(node->right)));
}

void printcurrentlevel(tree *node , int i)
{
    if(node==NULL)
    {
        return;
    }
    if(i==1)
    {
        printf("%d ",node->data);
    }
    else if(i>1)
    {
        printcurrentlevel(node->left,i-1);
        printcurrentlevel(node->right,i-1);
    }
}

int main(void)
{
    tree *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);


    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printcurrentlevel(root,i);
    }

}