#include "stacklist1.h"
#include <string.h>

int main()
{
    char num1[MAX], num2[MAX];
    int i, rem = 0, tmp = 0;
    node *top1 = NULL, *top2 = NULL, *sum = NULL;
    printf("Please input first number: ");
    scanf("%s", num1);
    printf("Please input second number: ");
    scanf("%s", num2);

    for (i = 0; i < strlen(num1); i++)
        push(num1[i] - '0', &top1);

    for (i = 0; i < strlen(num2); i++)
        push(num2[i] - '0', &top2);
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
            tmp += pop(&top2);
        }
        tmp += rem;
        if (tmp >= 10)
        {
            tmp -= 10;
            rem = 1;
        }
        else
        {
            rem = 0;
        }
        push(tmp, &sum);
        tmp = 0;
    }
    if(rem == 1){
        push(rem, &sum);
    }
    printf("The result is: ");
    while (!isEmpty(sum))
    {
        printf("%d", pop(&sum));
    }
    return 0;
}