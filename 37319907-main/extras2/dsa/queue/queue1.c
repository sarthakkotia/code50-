#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
}queue;


void enqueue( queue *q , int val)
{
    if(q->rear==q->size-1)
    {
        printf("Queue filled\n");
    }
    else
    {
        q->arr[q->rear] = val;
        q->rear++;
    }
}

int dequeue(queue *q)
{
    int temp;
    if(q->front==q->rear)
    {
        printf("queue empty\n");
        return -1;
    }
    else
    {
        temp = q->arr[q->front];
        q->front++;
        return temp;
    }
}

int main(void)
{
    queue *q = malloc(sizeof(queue));
    q->front = 0;
    q->rear=0;
    q->size=100;
    q->arr=(int *)malloc(q->size * sizeof(int));

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    printf("Vale dequeued : %d\n",dequeue(q));
    printf("Vale dequeued : %d\n",dequeue(q));
    printf("Vale dequeued : %d\n",dequeue(q));
    printf("Vale dequeued : %d\n",dequeue(q));
    printf("Vale dequeued : %d\n",dequeue(q));

}