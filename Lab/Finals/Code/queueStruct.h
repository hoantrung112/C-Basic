#include<stdio.h>
#define MaxLength 5
typedef int elementType;
typedef struct
{
    elementType element[MaxLength]; //Store the elements
    int front, rear;
} queue;

void makeNullQueue(queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(queue q)
{
    return q.front == -1;
}
int isFull(queue q)
{
    return (q.rear == MaxLength - 1);
}
void enQueue(elementType ele, queue *q)
{
    if (!isFull(*q))
    {
        if (isEmpty(*q))
        {
            q->front = 0;
        }
        q->rear = q->rear + 1;
        q->element[q->rear] = ele;
    }
    else
        printf("Queue is full!\n");
}

elementType deQueue(queue *q)
{
    elementType e;
    if (!isEmpty(*q))
    {
        e = q->element[q->front];
        q->front = q->front + 1;
        if (q->front > q->rear)
            makeNullQueue(q);
        // Queue become empty
        return e;
    }
    else
        printf("Queue is empty!\n");
}
