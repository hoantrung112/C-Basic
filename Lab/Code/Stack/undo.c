#include "stacklist1.h"
#include "stacklist1Str.h"
#include <string.h>

void main()
{
    int choice;
    node *stack1 = NULL; //store integers
    node *stackValue = NULL;
    nodeStr *stack2 = NULL; //store names of methods used for stack1
    char *pushed = "PUSH", *popped = "POP";
    while (1)
    {
        printf("============== MENU UNDO PROGRAMME ==============\n");
        printf("1. Push to stack.\n");
        printf("2. View the top element in the stack.\n");
        printf("3. Pop from stack.\n");
        printf("4. Undo.\n");
        printf("5. Exit.\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an integer to push to stack: ");
            scanf("%d", &choice);
            push(choice, &stack1);
            printf("Element %d pushed successfully!\n", peek(&stack1));
            pushStr(pushed, &stack2);
            break;
        case 2:
            printf("The current topmost element in the stack is: %d\n", peek(&stack1));
            break;
        case 3:
            choice = pop(&stack1);
            printf("Element %d popped successfully!\n", choice);
            push(choice, &stackValue);
            pushStr(popped, &stack2);
            break;
        case 4:
            if (strcmp(peekStr(&stack2), pushed) == 0)
            {
                pop(&stack1);
                popStr(&stack2);
            }
            else
            {
                popStr(&stack2);
                push(pop(&stackValue), &stack1);
            }
            printf("Undo successfully!\n");
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("Please enter number from 1->5 !\n");
            break;
        }
    }
}