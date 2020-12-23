#include <stdio.h>
#include <stdlib.h>

typedef int elementType;
typedef struct
{
    elementType element;
    node *next;
} node;

typedef struct
{
    node *front, *rear;
} queue;

void makeNullQueue(queue *q)
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    q->front = head;
    q->rear = head;
}
int isEmpty(queue q)
{
    return q.front == NULL;
}

void enQueue(elementType ele, queue *q)
{
    q->rear->next = (node *)malloc(sizeof(node));
    q->rear = q->rear->next;
    q->rear->element = ele;
    q->rear->next = NULL;
}

elementType deQueue(queue *q)
{
    elementType ele;
    node *prev = (node *)malloc(sizeof(node));
    if (!isEmpty(*q))
    {
        ele = q->front->element;
        prev = q->front;
        q->front = q->front->next;
        free(prev);
        return ele;
    }
    else
        printf("Queue is empty already!\n");
}
