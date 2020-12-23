#include "stacklist1.h"
#include <string.h>

int main()
{
    char subtrahend[MAX], subtractor[MAX], diff[MAX], temp[MAX];
    int i, rem = 0, minus = 0, tmp = 0;
    node *top1 = NULL, *top2 = NULL, *sum = NULL;
    printf("Please input the subtrahend: ");
    scanf("%s", subtrahend);
    printf("Please input subtractor: ");
    scanf("%s", subtractor);
    printf("hend = %d tor = %d",atoi(subtrahend),atoi(subtractor));
    if (atoi(subtrahend) < atoi(subtractor))
    {
        strcpy(temp, subtractor);
        strcpy(subtractor, subtrahend);
        strcpy(subtrahend, temp);
        minus = -1;
    }

    for (i = 0; i < strlen(subtrahend); i++)
        push(subtrahend[i] - '0', &top1);

    for (i = 0; i < strlen(subtractor); i++)
        push(subtractor[i] - '0', &top2);

    while (!isEmpty(top1) || !isEmpty(top2))
    {
        if (isEmpty(top1))
        {
            tmp += 0;
        }
        else
        {
            tmp += pop(&top1);
        }
        if (isEmpty(top2))
        {
            tmp += 0;
        }
        else
        {
            tmp -= pop(&top2);
        }
        tmp -= rem;
        if (tmp < 0)
        {
            tmp += 10;
            rem = 1;
        }
        else
        {
            rem = 0;
        }
        push(tmp, &sum);
        tmp = 0;
    }
    while (peek(&sum) == 0)
    {
        pop(&sum);
    }
    if (minus == -1)
    {
        printf("The result is: -");
    }
    else
        printf("The result is: ");
    while (!isEmpty(sum))
    {
        printf("%d", pop(&sum));
    }
    return 0;
}