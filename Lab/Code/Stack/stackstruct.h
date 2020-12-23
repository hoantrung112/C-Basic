#include <stdio.h>
#define MAX 100

typedef int elType;
struct stackRec
{
    elType storage[MAX];
    int top;
};
typedef struct stackRec stackType;
void initialize(stackType *stack);
int isEmpty(stackType *stack);
int isFull(stackType *stack);
void push(elType ele, stackType *stack);
elType pop(stackType *stack);
elType peek(stackType *stack);

void initialize(stackType *stack)
{
    (*stack).top = 0;
}

int isEmpty(stackType *stack)
{
    return (stack->top == 0);
}

int isFull(stackType *stack)
{
    return (stack->top == MAX);
}

void push(elType ele, stackType *stack)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
    }
    else
    {
        (*stack).storage[(*stack).top++] = ele;
    }
}

elType pop(stackType *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
    }
    else
    {
        return (*stack).storage[--(*stack).top];
    }
}

elType peek(stackType *stack){
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        exit(1);
    }
    return (*stack).storage[(*stack).top - 1];
}