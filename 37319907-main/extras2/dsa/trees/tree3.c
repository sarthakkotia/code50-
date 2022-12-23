#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left,*right;
}tree;

tree * create(char val)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->left = NULL;
    node -> right = NULL;
    node->data = val;
    return node;
}

tree * insert(tree *node , char val)
{
    if(node==NULL)
    {
        node = create(val);
    }
    return node;
}

void infix(tree *node)
{
    if(node==NULL)
    {
        return;
    }
    infix(node->left);
    printf(" %c ",node->data);
    infix(node->right);
}

int main(void)
{
    tree *root = NULL;
    char a[] = "+ab";
    int i=0;
    while(a[i] != '\0')
    {
        root = insert(root,a[i]);
        i++;
    }
    infix(root);
}