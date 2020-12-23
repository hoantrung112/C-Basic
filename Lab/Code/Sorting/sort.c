#include "sort.h"
#include <time.h>
#define size 10

double timeExe;
clock_t begin, end;
void main()
{
    int i;
    int myArr[size];
    // for (i = 0; i < size; i++)
    // {
    //     myArr[i] = -1 * (i * (-10000 + i) - 50 * i);
    // }
    int heapArr[size]={7,3,11,-2,23,19,0,7,100,-11},
    //Heap sort
    begin = clock();
    heapSort(heapArr, size);
    end = clock();
    timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nHeap sort: %.5f\n", timeExe);

    for (i = 0; i < size; i++)
    {
        printf("%d\t", heapArr[i]);
    }

    for (i = 0; i < size; i++)
    {
        myArr[i] = -1 * (i * (-10000 + i) - 50 * i);
    }

    //Insertion sort
    begin = clock();
    insertionSort(myArr, size);
    end = clock();
    timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Insertion sort: %.5f\n", timeExe);

    // for (i = 0; i < size; i++)
    // {
    //     myArr[i] = -1 * (i * (-10000 + i) - 50 * i);
    // }
    int bubArr[size] = {11, 2, 69, 101, -5, 26, 18, 9, 7, -555};

    //Bubble sort
    begin = clock();
    bubbleSort(bubArr, size);
    end = clock();
    timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Bubble sort: %.5f\n", timeExe);
    for (i = 0; i < size; i++)
    {
        printf("%d\t", bubArr[i]);
    }

    for (i = 0; i < size; i++)
    {
        myArr[i] = -1 * (i * (-10000 + i) - 50 * i);
    }

    //Selection sort
    begin = clock();
    bubbleSort(myArr, size);
    end = clock();
    timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Selection sort: %.5f\n", timeExe);

    for (i = 0; i < size; i++)
    {
        myArr[i] = -1 * (i * (-10000 + i) - 50 * i);
    }
    //Quick sort
    begin = clock();
    quickSort(myArr, 0, size - 1);
    end = clock();
    timeExe = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Quick sort: %.5f\n", timeExe);
}