#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
}tree;


tree *create(tree *node , int val)
{
    node = malloc(sizeof(tree));
    node -> data = val;
    node -> left = NULL;
    node -> right = NULL;
    // height will be changed further
    node -> height = 0;
    return node;
}

int max(int a , int b)
{
    int maximum = a;
    if(b>a)
    {
        maximum = b;
    }
    return maximum;
}


int height(tree *node)
{
    int h;
    if(node==NULL)
    {
        h = 0;
    }
    else
    {
        h = 1+max(height(node->left),height(node->right));
    }
    return h;
}

int balancefactor(tree *node)
{
    if(node == NULL)
    {
        return 0;
    }
    int hl = height(node->left);
    int hr = height(node -> right);
    return (hl-hr);
}

tree * acw(tree *node)
{
    tree *temp1 = node -> left;
    tree *temp2 = node -> left -> right;

    temp1 -> right = node;
    node -> left = temp2;

    node -> height = height(node);
    temp1 -> height = height(temp1);

    return temp1;
}

tree* cw(tree *node)
{
    tree *temp1 = node -> right;
    tree *temp2 = node-> right -> left;

    temp1 -> left = node;
    node -> right = temp2;

    node->height = height(node);
    temp1 -> height = height(temp1);

    return temp1;
}

tree * ll(tree *node)
{
    node = acw(node);
    return node;
}


tree *rr(tree *node)
{
    node = cw(node);
    return node;
}

tree * insert(tree *node , int val)
{
    if(node == NULL)
    {
        node = create(node, val);
    }
    else if(val < node -> data)
    {
        node -> left = insert(node-> left, val);
    }
    else if(val > node -> data)
    {
        node -> right = insert(node -> right, val);
    }

    // update the height of the newly created node
    node -> height = height(node);

    int bf = balancefactor(node);

    // if bf >1
        // added on left side of node then LL case
    if(bf > 1 && val < node -> left -> data)
    {
        //LL rotation
        node = ll(node);
    }
    //LR case
    else if(bf>1 && val > node->left->data)
    {
        node -> left = rr(node->left);
        node = ll(node);
    }
    // if bf <1
        // added on right side ie RR case
    else if(bf < -1 && val > node->right->data)
    {
        //RR rotation
        node = rr(node);
    }
    else if(bf < -1 && val < node -> right->data)
    {
        //RL rotation
        node ->right = ll(node->right);
        node = rr(node);
    }
    return node;
}

tree * delete(tree *node , int val)
{
    if(node == NULL)
    {
        return node;
    }
    else if(val < node->data)
    {
        node -> left = delete(node->left,val);
    }
    else if(val > node -> data)
    {
        node -> right = delete(node->right,val);
    }
    else if(val == node->data)
    {
        // if it's a child ie no further nodes
        if(node->left == NULL && node -> right == NULL)
        {
            free (node);
            node = NULL;
        }
        // if it has only left child
        else if(node->left != NULL && node ->right == NULL)
        {
            node->data = node->left -> data;
            node->left = delete(node->left,node->data);
        }
        // if it has only right child
        else if(node->right != NULL && node -> left == NULL)
        {
            node->data = node->right -> data;
            node->right = delete(node->right,node->data);
        }
        else if(node->left != NULL && node->right != NULL)
        {
            tree *temp = node->left;
            while(temp -> right != NULL)
            {
                temp = temp -> right;
            }
            node->data = temp->data;

            node->left = delete(node->left,temp->data);
        }

        // if root has been deleted so node will be null therfore we cannot calculate its height and balance factor
        if(node == NULL)
        {
            return node;
        }


        //update height
        node -> height = height(node);

        //get balance factor and and do all the operations
            int bf = balancefactor(node);

    // a little different case here for avl tree as val is deleted not inserted
    // if bf >1
        // added on left side of node then LL case
        if(bf > 1 && balancefactor(node->left)>=0)
        {
            //LL rotation
            node = ll(node);
        }
        //LR case
        else if(bf>1 && balancefactor(node->left)<0)
        {
            node -> left = rr(node->left);
            node = ll(node);
        }
        // if bf <1
            // added on right side ie RR case
        else if(bf < -1 && balancefactor(node->right)<=0 )
        {
            //RR rotation
            node = rr(node);
        }
        else if(bf < -1 && balancefactor(node->right)>0)
        {
            //RL rotation
            node ->right = ll(node->right);
            node = rr(node);
        }
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
    return;
}

int main(void)
{
    int n;
    int val;
    tree *root = NULL;
    do
    {
        printf("\n************\n1.Insert\n2.Delete\n3.Inorder\n4.Exit\n***********\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter node data : ");
                scanf("%d",&val);
                root = insert(root,val);
                break;
            case 2:
                printf("Enter the data to be deleted : ");
                scanf("%d",&val);
                root = delete(root,val);
                break;
            case 3:
                inorder(root);
                break;
        }
    }
    while(n != 4);
}