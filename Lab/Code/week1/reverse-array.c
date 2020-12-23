#include <stdio.h>
int main(void)
{
int i, arr[10];
printf("please enter 10 numbers:\n");
for(i=0; i<10; i++)
scanf("%d", &arr[i]);
printf("numbers in reversed order:\n");
for(i=9; i>=0; i--)
printf("%d\n", arr[i]);
return 0;
}