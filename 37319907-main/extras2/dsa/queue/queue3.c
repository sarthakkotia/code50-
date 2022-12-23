
//level order traversal of tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree *create(int val)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->data = val;
    node ->left = NULL;
    node ->right = NULL;
    return node;
}

int queue[100];
int rear = -1;
int front = -1;

void enqueue(int val)
{
    if(front == rear)
    {
        front++;
        rear++;
        queue[front] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}
void printlevelorder(tree *root)
{
    if(root==NULL)
    {
        return;
    }
    printf(" %d ",root->data);
    if(root->left != NULL)
    {
        enqueue(root->left->data);
    }
    if(root->right != NULL)
    {
        enqueue(root->right->data);
    }
    printlevelorder(root->left);
    printlevelorder(root->right);
}

int main(void)
{
    tree *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root -> left->left = create(4);
    root->left->right = create(5);
    printlevelorder(root);
}
