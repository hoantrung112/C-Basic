#include "stackarr.h"
int main()
{
    int arr[10] = { 17, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int i;
    stackType stack;
    initialize(stack);
    if (isEmpty(stack))
    {
        printf("Stack empty!\n");
    }
    for (i = 0; i < 10; i++)
    {
        push(arr[i], stack);
    }
    printf("Top = %d\n", peek(stack));
    while (!isEmpty(stack))
    {
        printf(" %d", pop(stack));
        printf("\nTop = %d\n", top);
    }
    if(isEmpty(stack)){
        printf("Empty!\n");
    }else
    {
        printf("Not empty!\n");
    }
    
    printf("stack[9] = %d\n", stack[9]);
}