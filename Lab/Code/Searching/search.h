#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//return the index of key ele (if any)
int linearSearch_Int(int arr[], int size, int key)
{
    int k = 0;
    while (arr[k] != key && k < size)
    {
        k++;
    }
    if (k < size)
    {
        return k;
    }
    return -1;
}

//return the index of key ele (return SIZE if not found)
int sentinelSearch_Int(int arr[], int size, int key)
{
    int k = 0;
    arr[size] = key;
    while (arr[k] != key)
    {
        k++;
    }
    if (k < size)
    {
        return k;
    }
    return -1;
}

int moveToFrontSearch_Int(int arr[], int size, int key)
{
    int i, j, temp;
    for (i = 0; i < size && arr[i] != key; i++)
    {
        if (arr[i] == key)
        {
            if (i > 0)
            {
                temp = arr[i];
                for (j = i; j > 0; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[0] = temp;
            }
            return i;
        }
    }
    return -1;
}

int transposeSearch_Int(int arr[], int size, int key)
{
    int i;
    int temp;
    for (i = 0; i < size - 1 && arr[i] != key; i++)
    {
        if (key == arr[i])
        {
            if (i > 0)
            {
                /*** Transpose with predecessor ***/
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
            return i - 1;
        }
    }
    return -1;
}

//for sorted array
int binarySearch(int arr[], int size, int keyValue)
{
    int mid, low = 0, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == keyValue)
        {
            return mid;
        }
        else if (keyValue < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
//for sorted array
int binarySearchRecursive(int arr[], int keyValue, int low, int high)
{
    int mid;
    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    if (arr[mid] < keyValue)
    {
        return binarySearchRecursive(arr, keyValue, mid + 1, high);
    }
    else if (arr[mid] > keyValue)
    {
        return binarySearchRecursive(arr, keyValue, low, mid - 1);
    }
    else
    {
        return mid;
    }
    return -1;
}
