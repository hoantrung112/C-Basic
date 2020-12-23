#include <stdio.h>
#define MAX_LEN 20
typedef int elementType;
typedef struct
{
    elementType element[MAX_LEN]; //Store the elements
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
    return (q.rear - q.front + 1) % MAX_LEN == 0;
}
void enQueue(elementType ele, queue *q)
{
    if (!isFull(*q))
    {
        if (isEmpty(*q))
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_LEN;
        q->element[q->rear] = ele;
    }
    else
        printf("Queue is full!\n");
}

elementType deQueue(queue *q)
{
    if (!isEmpty(*q))
    {
        elementType ele;
        ele = q->element[q->front];
        if (q->front == q->rear)
            makeNullQueue(q); // Queue becomes empty
        else
        {
            q->front = (q->front + 1) % MAX_LEN;
        }
        return ele;
    }
    else
        printf("Queue is empty already!\n");
}
