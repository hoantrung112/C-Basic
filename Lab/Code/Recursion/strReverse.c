#include <stdio.h>

void strReverse(char *str)
{
    if (*str)
    {
        strReverse(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    char str[] = "Hello my name is Trung";
    strReverse(str);
    printf("%s", *str);
    return 0;
}
