#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char* elementTypeStr;
typedef struct node_t_str
{
    elementTypeStr element;
    struct node_t_str *next;
} nodeStr;

int isEmptyStr(nodeStr *top);
void pushStr(elementTypeStr ele, nodeStr **top);
elementTypeStr popStr(nodeStr **top);
elementTypeStr peekStr(nodeStr **top);

int isEmptyStr(nodeStr *top)
{
    return (top == NULL);
}

void pushStr(elementTypeStr ele, nodeStr **top)
{
    nodeStr *temp;
    temp = (nodeStr *)malloc(sizeof(nodeStr));
    if (temp == NULL)
    {
        printf("No Memory available!Error!\n");
        return;
    }
    strcpy(temp->element, ele);
    temp->next = (*top);
    (*top) = temp;
    temp = NULL;
    free(temp);
}

elementTypeStr popStr(nodeStr **top)
{
    elementTypeStr value;
    nodeStr *temp;
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

elementTypeStr peekStr(nodeStr **top)
{
    if (!isEmptyStr(*top))
    {
        return (*top)->element;
    }
    printf("Stack underflow!No top node identified!\n");
    exit(1);
}
