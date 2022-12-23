#include <stdio.h>
#include <stdlib.h>


// https://www.geeksforgeeks.org/binary-search-tree-data-structure/

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * create(int val)
{
    tree *node = malloc(sizeof(tree));
    node -> data = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

tree * insert(tree *node,int val)
{
    if(node==NULL)
    {
        node = create(val);
        return node;
    }
    if(val<node->data)
    {
        node -> left = insert(node->left,val);
    }
    else if(val>node->data)
    {
        node -> right = insert(node->right,val);
    }
    return node;
}

int search(tree *node , int val)
{
    int a;
    if(node==NULL)
    {
        return 0;
    }
    if(node -> data == val)
    {
        printf("found\n");
        return 1;
    }
    if(val < node -> data)
    {
        a = search(node->left,val);
    }
    else
    {
        a= search(node -> right,val);
    }
    return a;
}


tree * delete(tree *node , int val)
{
    if(node == NULL)
    {
        return node;
    }
    if(val < node->data)
    {
        node -> left = delete(node->left,val);
    }
    else if(val > node->data)
    {
        node -> right = delete(node->right,val);
    }
        //if node has no child ie child node
    else if(val==node->data && node -> left == NULL && node-> right == NULL)
    {
        free(node);
        return NULL;
    }
      // if node has left chile or right child ie one child only
    else if(val == node -> data && node -> left == NULL && node -> right != NULL)
    {
        node -> data = node->right->data;
        node -> right =delete(node->right,node->right->data);
        return node;
    }
    else if(val == node -> data && node -> right == NULL && node -> left != NULL)
    {
        node -> data = node -> left -> data;
        node -> left = delete(node->left,node->left->data);
        return node;
    }
      // if node has two childs
    else if(val == node -> data && node -> left != NULL && node -> right != NULL)
    {
        // uske left subtree ka rightmost value ke saath swap karo
        tree *temp = node->left;
        while(temp -> right != NULL)
        {
            temp = temp -> right;
        }
        node -> data = temp -> data;
        node -> left = delete(node->left,temp->data);
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
    int n;
    tree *root = NULL;
    int val;
    do
    {
        printf("\n***************\n1.Insert\n2.Search\n3.Delete\n4.Inorder\n5.Exit\n********\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter the number to Insert: ");
                scanf("%d",&val);
                root = insert(root,val);
                break;
            case 2:
                printf("Enter the number to be searched : ");
                scanf("%d",&val);
                int a = search(root,val);
                if(a==0)
                {
                    printf("Not found\n");
                }
                break;
            case 3:
                printf("Enter the number to be deleted : ");
                scanf("%d",&val);
                root = delete(root,val);
                break;

            case 4:
                inorder(root);
                break;
        }
    }
    while( n != 5);
}