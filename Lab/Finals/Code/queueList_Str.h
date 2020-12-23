#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

char ele[MAX_LEN];
typedef struct node
{
    char element[MAX_LEN];
    struct node *next;
} node;

typedef struct
{
    node *front, *rear;
} queue;

node *makeNewNode(char ele[])
{
    node *tmp = (node *)malloc(sizeof(node));
    strcpy(tmp->element, ele);
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

void enQueue(char ele[], queue *q)
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

char *deQueue(queue *q)
{
    if (!isEmpty(*q))
    {
        strcpy(ele, q->front->element);
        node *prev;
        prev = q->front;
        q->front = q->front->next;
        free(prev);
        return ele;
    }
    else
    {
        printf("Queue is empty already!\n");
    }
}
