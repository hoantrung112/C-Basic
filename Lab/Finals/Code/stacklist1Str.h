#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_LEN 30

char value[MAX_LEN];

typedef struct node_t_str
{
    char element[MAX_LEN];
    struct node_t_str *next;
} nodeStr;

int isEmptyStr(nodeStr *top);
void pushStr(char ele[], nodeStr **top);
char *popStr(nodeStr **top);
char *peekStr(nodeStr **top);

int isEmptyStr(nodeStr *top)
{
    return (top == NULL);
}

void pushStr(char ele[], nodeStr **top)
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

char *popStr(nodeStr **top)
{
    nodeStr *temp;
    if (*top == NULL)
    {
        printf("Empty stack, hence cannot pop. Error!\n");
        exit(1);
    }
    strcpy(value, (*top)->element);
    temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

char *peekStr(nodeStr **top)
{
    if (!isEmptyStr(*top))
    {
        return (*top)->element;
    }
    printf("Stack underflow!No top node identified!\n");
    exit(1);
}
