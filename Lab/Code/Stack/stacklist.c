#include "stacklist.h"
void main()
{
    node *top = NULL;
    int n, value;
    elType* valuepop;
    do
    {
        do
        {
            printf("Enter the element to be pushed\n");
            scanf("%d", &value);
            top = push(top, value);
            printf("Enter 1 to continue\n");
            scanf("%d", &n);
        } while (n == 1);
        printf("Enter 1 to pop an element\n");
        scanf("%d", &n);
        while (n == 1)
        {
            top = pop(top, valuepop);
            printf("The value popped is %d\n", valuepop);
            printf("Enter 1 to pop an element\n");
            scanf("%d", &n);
        }
        printf("Enter 1 to continue\n");
        scanf("%d", &n);
    } while (n == 1);
}