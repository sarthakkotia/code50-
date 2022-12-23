#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree;

tree *create(int val)
{
    tree *node = malloc(sizeof(tree));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree *insert(tree *node, int val)
{
    if (node == NULL)
    {
        node = create(val);
        return node;
    }

    char ask;
    printf("do you want to inser l or r of %d : ", node->data);
    scanf(" %c", &ask);
    if (ask == 'l')
    {
        node->left = insert(node->left, val);
    }
    else if (ask == 'r')
    {
        node->right = insert(node->right, val);
    }
    return node;
}

int search(tree *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == val)
    {
        printf("Found\n");
        return 1;
    }
    int a = search(root->left, val);
    if(a == 1)
    {
        return 1;
    }
    a = search(root->right, val);
    return a;
}

void preorder(tree *node)
{
    if(node == NULL)
    {
        return;
    }
    printf("%d ",node -> data);
    preorder(node->left);
    preorder(node->right);
    return;
}

void postorder(tree *node)
{
    if(node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node -> data);
    return;
}

void inorder(tree *node)
{
    if(node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d ",node -> data);
    inorder(node->right);
    return;

}

/*void delete(tree *node , int val)
{

}
*/

int main(void)
{
    int n;
    int val;
    tree *root;
    do
    {
        printf("\n*******************\n1.Create\n2.Insert\n3.Search\n4.Preorder\n5.PostOrder\n6.Inorder\n7.Delete\n8.Exit\n********\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the root data: ");
            scanf("%d", &val);
            root = create(val);
            break;
        case 2:
            printf("Enter the node data: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 3:
            printf("The node to be searched for: ");
            scanf("%d", &val);
            int a = search(root, val);
            if(a==0)
            {
                printf("Not found\n");
            }
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            inorder(root);
            break;
       /* case 7:
            printf("Enter the value to be deleted: ");
            scanf("%d",&val);
            delete(root,val)
            */
        }

    } while (n != 8);
}