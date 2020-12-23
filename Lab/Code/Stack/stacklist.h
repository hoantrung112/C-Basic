#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int elType;
typedef struct node_t
{
    elType element;
    struct node_t *next;
} node;

node *push(node *top, elType value);
node *pop(node *top, elType *value);

//Return a pointer to the top node
node *push(node *top, elType value)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("No Memory available!Error!\n");
        return NULL;
    }
    temp->element = value;
    temp->next = top;
    top = temp;
    temp = NULL;
    free(temp);
    return (top);
}
//Save top node's element to value & return a pointer to the top node
node *pop(node *top, elType *value)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (top == NULL)
    {
        printf("Empty stack, hence cannot pop. Error!\n");
        return NULL;
    }
    *value = top->element;
    temp = top;
    top = top->next;
    free(temp);
    return (top);
}
