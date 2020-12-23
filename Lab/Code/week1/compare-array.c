#include<stdio.h>
#define SIZE 5

int compare_arrays(int arr1[], int arr2[], int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if((arr1[i] != arr2[i]) || (arr1[i]==arr2[i] && i==((size-1)/2))){
            if(arr1[i] == arr2[size-1-i]){
                count +=1;
            }else {
                return 0;
            }
        }
    }
    if(count == size){
        return -1;
    }
    return 1;
};
int main(void){
    int arr1[SIZE], arr2[SIZE],j;
    printf("Enter %d integers of array 1: \n", SIZE);
    for(j =0; j<SIZE; j++){
        scanf("%d", &arr1[j]);
    }
    printf("Enter %d integers of array 2: \n", SIZE);
    for(j =0; j<SIZE; j++){
        scanf("%d", &arr2[j]);
    }

    switch(compare_arrays(arr1, arr2, SIZE)){
        case 0:
        printf("They are not equal arrays \n");
        break;
        case 1:
        printf("They are equal arrays \n");
        break;
        case -1:
        printf("They are symmetric arrays \n");
        break;
    }
    return 0;
};

