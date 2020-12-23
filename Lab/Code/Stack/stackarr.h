#include <stdio.h>
#define MAX 100

typedef int elType;
typedef elType stackType[MAX];
int top;

void initialize(stackType stack);
int isEmpty(stackType stack);
int isFull(stackType stack);
void push(elType ele, stackType stack);
elType pop(stackType stack);
elType peek(stackType stack);

void initialize(stackType stack)
{
    top = 0;
}

int isEmpty(stackType stack)
{
    return top == 0;
}

int isFull(stackType stack)
{
    return top == MAX;
}

void push(elType ele, stackType stack)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
    }
    else
    {
        stack[top++] = ele;
    }
}

elType pop(stackType stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
    }
    else
    {
        return stack[--top];
    }
}
elType peek(stackType stack){
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        return -99999;
    }
    return stack[top - 1];
}