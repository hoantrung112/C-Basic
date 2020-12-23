#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fptr, *fw;
    int count = 0;
    char str[50];
    if ((fptr = fopen("fileOP.txt", "r")) == NULL)
    {
        printf("Cannot open to w!\n");
    };
    fw = fopen("demo.txt", "w");
    while (!feof(fptr) && count != 10)
    {
        fgets(str, 50, fptr);
        printf("%s\n", str);
        fprintf(fw, "%s\n", str);
        count++;
    }
    fclose(fptr);
}