#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

int main() {
    int i,sum =0,index;
    float average, diff;
    int arr[SIZE];
    int mindiff = 2147483647;

    printf("please enter 10 numbers:\n");
    for(i = 0; i < SIZE; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
    }
    average = sum/SIZE;   
    printf("Sum is %d \n", sum);
    for(i = 0; i < SIZE; i++){
        diff = fabs(average-arr[i]);
        if(diff < mindiff) {
        mindiff = diff;
        index = i;
        }
    }
    printf("The average value is %.1f \n", average);
    printf("The element closet to mean value is %d", arr[index]);
    return 0;
}
