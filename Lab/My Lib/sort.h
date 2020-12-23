#include <stdio.h>

void insertionSort(int list[], int size)
{
    int i, j;
    int next;
    for (i = 1; i < size; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
}
void selectionSort(int list[], int size)
{
    int i, j, min, tmp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j <= size - 1; j++)
            if (list[j] < list[min])
                min = j;
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
    }
}
void adjust(int list[], int root, int n)
{
    int child, rootKey;
    int temp;
    temp = list[root];
    rootKey = list[root];
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && (list[child] < list[child + 1]))
            child++;
        if (rootKey > list[child])
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}

void heapSort(int list[], int n)
{
    int i, j;
    int temp;
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = list[1];
        list[1] = list[i + 1];
        list[i + 1] = temp;
        adjust(list, 1, i);
    }
}

void SWAP (int key1, int key2, int tmp){
    tmp = key1;
    key1 = key2;
    key2 = tmp;
}
void quickSort(int list[], int left, int right)
{
    int pivot, i, j;
    int temp;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = list[left];
        do
        {
            do
                i++;
            while (list[i] < pivot);
            do
                j--;
            while (list[j] > pivot);
            if (i < j)
                SWAP(list[i], list[j], temp);
        } while (i < j);
        SWAP(list[left], list[j], temp);
        quickSort(list, left, j - 1);
        quickSort(list, j + 1, right);
    }
}
