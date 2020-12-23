#include "infix-postfix.h"
#include <string.h>
#include <ctype.h>

void infixNotationInput();
void postfixConversion();

node *infixTop = NULL;
char postfix[MAX * 4];
int postfixIndex = 0;
int infixLen;

int main()
{
    int choice, j;
    while (1)
    {
        printf("--------------- INFLIX - POSTFLIX NOTATION CALCULATION MENU---------------\n");
        printf("--------------- ONE - DIGIT INTEGERS ONLY---------------\n");
        printf("1. Enter arithmatic expressions in inflix notation.  \n");
        printf("2. Postflix form conversion & display. \n");
        printf("3. Calculation.\n");
        printf("4. Exit.\n");
        printf("Your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            infixNotationInput();
            break;
        case 2:
            printf("The converted postfix notation is:");
            for (j = 0; j < MAX; j++)
            {
                printf(" %c", postfix[j]);
            }
            printf("\n");
            break;
        case 3:
            postfixConversion();
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("SYNTAX ERROR!\n Please enter a number from 1->4");
            break;
        }
    }
    return 0;
}

void infixNotationInput()
{
    int i = 0;
    int flag = 0;
    char infix[MAX]; // array to store infix expression inputted
    printf("Please enter an arithmatic expression with no spaces:\n");
    scanf("%s", infix);
    infixLen = strlen(infix);
    while (i < infixLen)
    {
        if (infix[i] == '(')
        {
            push(infix[i], &infixTop);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(infixTop))
            {
                if (peek(&infixTop) == '(')
                {
                    pop(&infixTop);
                    break;
                }
                else
                {
                    postfix[postfixIndex] = pop(&infixTop);
                    postfixIndex++;
                    flag = -1; // if flag != 0 then prevent doubling i++
                }
                i++;
            }
        }
        else if (infix[i] >= 48 && infix[i] <= 57)
        {
            postfix[postfixIndex] = infix[i];
            postfixIndex++;
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            if (isEmpty(infixTop))
            {
                push(infix[i], &infixTop);
            }
            else if (!isEmpty(infixTop) && (peek(&infixTop) == '('))
            {
                push(infix[i], &infixTop);
            }
            else
            {
                postfix[postfixIndex] = pop(&infixTop);
                postfixIndex++;
                push(infix[i], &infixTop);
            }
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            if (isEmpty(infixTop))
            {
                push(infix[i], &infixTop);
            }
            else if (!isEmpty(infixTop))
            {
                if (peek(&infixTop) == '+' || peek(&infixTop) == '-')
                {
                    push(infix[i], &infixTop);
                }
                else if (peek(&infixTop) == '(')
                {
                    push(infix[i], &infixTop);
                }
                else if (peek(&infixTop) == '*' || peek(&infixTop) == '/')
                {
                    postfix[postfixIndex] = pop(&infixTop);
                    postfixIndex++;
                    push(infix[i], &infixTop);
                }
            }
        }
        if (flag == 0)
        {
            i++;
        }
        else
        {
            flag = 0;
        }
    }
    while (!isEmpty(infixTop))
    {
        postfix[postfixIndex] = pop(&infixTop);
        postfixIndex++;
    }
}
void postfixConversion()
{
    char *cptr;
    int op1, op2, op3, num;
    cptr = postfix;
    while (*cptr != '\0')
    {
        if (isdigit(*cptr))
        {
            num = *cptr - 48;
            push(num, &infixTop);
        }
        else
        {
            op1 = pop(&infixTop);
            op2 = pop(&infixTop);
            switch (*cptr)
            {
            case '+':
            {
                op3 = op1 + op2;
                break;
            }
            case '-':
            {
                op3 = op2 - op1;
                break;
            }
            case '*':
            {
                op3 = op1 * op2;
                break;
            }
            case '/':
            {
                op3 = op2 / op1;
                break;
            }
            }
            push(op3, &infixTop);
        }
        cptr++;
    }
    printf("\nThe result of the expression is %d.\n\n", pop(&infixTop));
}