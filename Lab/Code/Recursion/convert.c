#include <stdio.h>
int convertDecToBin(int num);

int main()
{
    int num;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &num);
    printf("The equivalent binary form is:");
    convertDecToBin(num);
}
int convertDecToBin(int num)
{
    int remain;
    if (num == 0)
        return 0;
    else
    {
        remain = num % 2;
        convertDecToBin(num / 2);
        printf("%d", remain);
    }
}
