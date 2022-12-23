#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;


void isempty(node *s)
{
    if(s==NULL)
    {
        printf("Stack is empty\n");
    }
    return;
}
void isfull(node *s)
{
    node *p = (node *)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Stack is Full\n");
        return;
    }
}

node * push(node *s, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Stack Overflow\n");
        return s;
    }
    else
    {
        temp->data = val;
        temp->next= s;
        s = temp;
        return s;
    }
}
int pop(node **s)
{
    int temp;
    if(*s == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        node *n = *s;
        *s = (*s) -> next;
        temp = n->data;
        free(n);
        return temp;

    }
}
void peek(node *s)
{
    if(s==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf(" %d ",s->data);
    }
}
int main(void)
{
    int n;
    int val;

    node *s = NULL;

    do
    {
        printf("\n************\n1.IsEmpty\n2.IsFull\n3.Push\n4.Pop\n5.Peek\n6.Exit\n***********\nEnter Your Choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                isempty(s);
                break;
            case 2:
                isfull(s);
                break;
            case 3:
                printf("Enter value to be pushed: ");
                scanf("%d",&val);
                s = push(s,val);
                break;
            case 4:
                val = pop(&s);
                if(val !=-1)
                    printf("Value popped: %d",val);
                break;
            case 5:
                peek(s);
                break;
        }

    }
    while(n != 6);
}