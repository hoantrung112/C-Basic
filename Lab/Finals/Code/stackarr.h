#include <stdio.h>
#define MAX 10

typedef int elementType;
typedef elementType stackType[MAX];
int top;

void initialize(stackType stack);
int isEmpty(stackType stack);
int isFull(stackType stack);
void push(elementType ele, stackType stack);
elementType pop(stackType stack);
elementType peek(stackType stack);

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

void push(elementType ele, stackType stack)
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

elementType pop(stackType stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        return -99999;
    }
    else
    {
        return stack[--top]; // return stack[top] and THEN top = top--
    }
}
elementType peek(stackType stack){
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        return -99999;
    }
    return stack[top - 1];
}