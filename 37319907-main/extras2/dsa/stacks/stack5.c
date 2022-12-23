#include <stdio.h>
#include <stdlib.h>


//QUEUE USING STACK

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;


void push(stack *s , int val)
{
    if(s->top==s->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(stack *s)
{
    int temp;
    if(s->top==-1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}

int dequeue(stack *s1, stack *s2)
{
    int x;
    while(s1->top != -1)
    {
        x = pop(s1);
        push(s2,x);
    }
    x = pop(s2);
    return x;
}

void enqueue(int val,stack *s1, stack *s2)
{
    push(s1,val);
}

int main(void)
{
    int n;
    int val;
    stack *s1 = malloc(sizeof(stack));
    stack *s2 = malloc(sizeof(stack));
    s1->top = s2->top = -1;
    s1->size = s2->size = 100;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    s2->arr = (int *)malloc(s1->size * sizeof(int));
    do
    {
        printf("\n******\n1.Enqueue\n2.Dedueue\n3.Exit\n******\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter a value to be enqueued : ");
                scanf("%d",&val);
                enqueue(val,s1,s2);
                break;
            case 2:
                printf("Element dequeued : %d",dequeue(s1,s2));
                break;

        }
    }
    while(n != 3);
}