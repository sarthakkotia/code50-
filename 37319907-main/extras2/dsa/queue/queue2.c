#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct queue
{
    node *front;
    node *rear;
}queue;


node *newnode(int val)
{
    node *temp = malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void enqueue(queue *q,int val)
{
    node *temp = newnode(val);
    if(q->rear==NULL)
    {
        q->front=q->rear=temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear=temp;
    }
}


int dequeue(queue *q)
{
    int n;
    node *temp;
    temp = q->front;
    q->front = q->front -> next;
    n = temp->data;
    free(temp);
    return n;

}

int main(void)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;


    enqueue(q,10);
    enqueue(q,100);
    enqueue(q,1000);
    enqueue(q,10000);
    enqueue(q,100000);
    enqueue(q,1000000);


    printf("Element dequeued : %d \n",dequeue(q));
    printf("Element dequeued : %d \n",dequeue(q));
    printf("Element dequeued : %d \n",dequeue(q));
    printf("Element dequeued : %d \n",dequeue(q));
}
