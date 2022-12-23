#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int *arr;
    int size;
} stack;

void isempty(stack *s)
{
    if(s->top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    return;
}
void isfull(stack *s)
{
    if(s->top==s->size-1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
    return;
}

void push(stack *s , int val)
{
    if(s->top==s->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s -> top++;
        s->arr[s->top] = val;
    }
    return;
}

int pop(stack *s)
{
    int temp;
    if(s->top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}

void peek(stack *s)
{
    if(s->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf(" %d ",s->arr[s->top]);
    }
}
int main(void)
{
    int n;
    int val;

    stack *s = (stack *)malloc(sizeof(stack));
    s->top=-1;
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));

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
                push(s,val);
                break;
            case 4:
                val = pop(s);
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