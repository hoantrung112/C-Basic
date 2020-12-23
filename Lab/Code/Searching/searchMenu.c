#include "search.h"
#include "time.h"
#define MAX 200000

int fetchKeyValue();
void displayResult();

int key;
int keyIndex;
double timeExe;
void main()
{
    int choice, i;
    clock_t begin, end;
    int arr[MAX];
    for (i = 0; i < MAX; i++)
    {
        arr[i] = 11 * i - 2;
    }
    while (1)
    {
        printf("============= Searching option menu =============\n");
        printf("1. Linear search.\n");
        printf("2. Sentinel search.\n");
        printf("3. Binary search using loop.\n");
        printf("4. Binary search using recursion.\n");
        printf("5. Exit.\n");
        printf("Please enter your choice here: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            begin = clock();
            key = fetchKeyValue();
            keyIndex = linerSearch_Int(arr, MAX, key);
            end = clock();
            timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
            displayResult();
            break;
        case 2:
            begin = clock();
            key = fetchKeyValue();
            keyIndex = sentinelSearch_Int(arr, MAX, key);
            end = clock();
            timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
            displayResult();
            break;
        case 3:
            begin = clock();
            key = fetchKeyValue();
            keyIndex = binarySearch(arr, MAX, key);
            end = clock();
            timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
            displayResult();
            break;
        case 4:
            begin = clock();
            key = fetchKeyValue();
            keyIndex = binarySearchRecursive(arr, key, 0, MAX - 1);
            end = clock();
            timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
            displayResult();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Please enter a number 1->4!\n");
            break;
        }
    }
}

int fetchKeyValue()
{
    printf("Enter a key value to search for: \n");
    scanf("%d", &key);
    return key;
}
void displayResult()
{
    if (keyIndex == -1)
    {
        printf("No such element found!\n");
        return;
    }
    else
    {
        printf("The key element has the index of %d.\n", keyIndex);
        printf("Execution time: %.3f miliseconds.\n", timeExe);
    }
}