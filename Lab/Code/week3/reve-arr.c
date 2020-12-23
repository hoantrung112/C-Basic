#include <stdlib.h>
#include <stdio.h>
int main(void)
{

int i, n, *p;
printf("How many numbers do you want to enter?\n");
scanf("%d", &n);
/* Allocate an int array of the proper size */
p = (int *)malloc(n * sizeof(int));
if (p == NULL)
{
printf("Memory allocation failed!\n");
return 1;
}
/* Get the numbers from the user */
printf("Enter %d number(s) here: ", n);
for(i = 0; i < n; i++){
    scanf("%d", p);
    p++;
}
p--;
/* Display them in reverse */
for(i = 0; i < n; i++){
    printf("%d ", *p);
    p--;
}
p++;
/* Free the allocated space */
free(p);
return 0;
}