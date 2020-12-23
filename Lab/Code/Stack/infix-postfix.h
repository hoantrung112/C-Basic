#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char elementType;
typedef struct node_t
{
    elementType element;
    struct node_t *next;
} node;

int isEmpty(node *top);
void push(elementType ele, node **top);
elementType pop(node **top);
elementType peek(node **top);

int isEmpty(node *top)
{
    return (top == NULL);
}

void push(elementType ele, node **top)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("No Memory available!Error!\n");
        return;
    }
    temp->element = ele;
    temp->next = (*top);
    (*top) = temp;
    temp = NULL;
    free(temp);
}

elementType pop(node **top)
{
    elementType value;
    node *temp;
    if (*top == NULL)
    {
        printf("Empty stack, hence cannot pop. Error!\n");
        exit(1);
    }
    value = (*top)->element;
    temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

elementType peek(node **top)
{
    if (!isEmpty(*top))
    {
        return (*top)->element;
    }
    printf("Stack underflow!No top node identified!\n");
    exit(1);
}
