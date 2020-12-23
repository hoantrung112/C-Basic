#include <stdio.h>
#include <stdlib.h>

typedef int elementType;
typedef struct node
{
    elementType element;
    struct node *next;
} node;

typedef struct
{
    node *front, *rear;
} queue;

node *makeNewNode(elementType ele)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->element = ele;
    tmp->next = NULL;
    return tmp;
}

void makeNullQueue(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
int isEmpty(queue q)
{
    return q.front == NULL;
}

void enQueue(elementType ele, queue *q)
{
    node *tmp = makeNewNode(ele);
    if (isEmpty(*q))
    {
        q->rear = tmp;
        q->front = tmp;
        return;
    }
    q->rear->next = tmp;
    q->rear = tmp;
}

elementType deQueue(queue *q)
{
    if (!isEmpty(*q))
    {
        elementType ele = q->front->element;
        node *prev;
        prev = q->front;
        q->front = q->front->next;
        free(prev);
        return ele;
    }
    else
    {
        printf("Queue is empty already!\n");
        return -1;
    }
}
