#include "stacklist1.h"
void main()
{
    node *top0 = NULL ;
    node *top1 = NULL;
    int count0 = 0, count1 = 0;
    int choice;
    while (1)
    {
        printf("--------------- Stacklist1 menu ---------------\n");
        printf("1.Push stack 1\n");
        printf("2.Push stack 2\n");
        printf("3.Pop stack 1\n");
        printf("4.Pop stack 2\n");
        printf("5.IsEmpty stack 1\n");
        printf("6.IsEmpty stack 2\n");
        printf("7.Peek stack 1\n");
        printf("8.Peek stack 2\n");
        printf("9.Exit\n");
        printf("Your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an integer to push to stack1:\n");
            scanf("%d", &choice);
            push(choice, &top0, count0);
            printf("Top node of stack1 is: %d\n", top0->element);
            break;
        case 2:
            printf("Enter an integer to push to stack2:\n");
            scanf("%d", &choice);
            push(choice, &top1, count1);
            printf("Top node of stack2 is: %d\n", top1->element);
            break;
        case 3:
            printf("Popped node of stack1 is: %d\n", pop(&top0, count0));
            break;
        case 4:
            printf("Popped node of stack1 is: %d\n", pop(&top1, count1));
            break;
        case 5:
            if (isEmpty(top0))
            {
                printf("Stack 1 empty!\n");
            }
            else
            {
                printf("Stack 1 not empty!\n");
            }
            break;
        case 6:
            if (isEmpty(top1))
            {
                printf("Stack 2 empty!\n");
            }
            else
            {
                printf("Stack 2 not empty!\n");
            }
            break;
        case 7:
            printf("Peek stack 1: %d\n", peek(&top0));
            break;
        case 8:
            printf("Peek stack 2: %d\n", peek(&top1));
            break;
        case 9:
            exit(0);
            break;

        default:
            break;
        }
    }
}