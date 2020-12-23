#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 150

typedef struct demo
{
    char *left;
    char *mid;
    char *right;
    char line[MAX];
} demo;

demo *myDemo;
void main()
{
    demo *dict;
    dict = (demo *)malloc(sizeof(demo) * 25);
    int i = 0;
    FILE *fptr;
    char str[MAX];
    const char delim[2] = "-";
    if ((fptr = fopen("demo.txt", "r")) == NULL)
    {
        printf("Cannot open file text to read!\n");
        exit(1);
    }

    while (fgets(dict[i].line, MAX, fptr))
    {
        dict[i].left = strtok(dict[i].line, delim);
        dict[i].mid = strtok(NULL, delim);
        dict[i].right = strtok(NULL, delim);
        i++;
    }
    for (i = 0; i < 25; i++)
        printf("%s : %s : %s\n", dict[i].left, dict[i].mid, dict[i].right);
}