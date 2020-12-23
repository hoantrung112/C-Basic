#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {SUCCESS, FAIL, SIZE = 1000, MAX_LEN = 30};
int main(){
    char arr[MAX_LEN];
    char a = 'a';
    for(int i = 0; i< MAX_LEN - 1; i++){
            arr[i] = a;
    }

    printf("%s\n", arr);
    printf("%s\n", arr[MAX_LEN]);
    memset(arr, ' ', sizeof(arr));
    arr[10] = a;
    printf("%s\n", arr);
    return 0;
}