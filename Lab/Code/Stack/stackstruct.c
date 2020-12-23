#include "stackstruct.h"
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i;
    stackType *stack;
    initialize(stack);
    if (isEmpty(stack))
    {
        printf("Stack empty!\n");
    }

    for (i = 0; i < 5; i++)
    {
        push(arr[i], stack);
    }
    printf("Top = %d\n", peek(stack));
    if (isFull(stack))
    {
        printf("Stack full!\n");
    }
    while (!isEmpty(stack))
    {
        printf(" %d", pop(stack));
        printf("\nTop = %d\n", stack->top);
    }
    if (isEmpty(stack))
    {
        printf("Empty!\n");
    }
    else
    {
        printf("Not empty!\n");
    }
    printf("stack[0] = %d\n", stack->storage[0]);
}