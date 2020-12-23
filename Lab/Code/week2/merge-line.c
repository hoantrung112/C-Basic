#include<stdio.h>
enum{SUCCESS, FAIL, MAX_LEN = 500};

int main(int argc, char* argv[]){
    FILE *fptr1;
    FILE *fptr2;
    FILE *fptr3;
    char arr1[MAX_LEN], arr2[MAX_LEN];
    int c1, c2;
    int reval = SUCCESS;
    if(argc != 4){
        printf("Syntax Error! Enter: merge-line <file1> <file2> <file3>\n");
        reval = FAIL;
    };
    if((fptr1 = fopen(argv[1],"r")) == NULL){
        printf("CAN'T OPEN FILE %s", argv[1]);
        reval = FAIL;
    }else if((fptr2 = fopen(argv[2],"r")) == NULL){
        printf("CAN'T OPEN FILE %s", argv[2]);
        reval = FAIL;
    }else if((fptr3 = fopen(argv[3],"w")) == NULL){
        printf("CAN'T OPEN FILE %s", argv[3]);
        reval = FAIL;
    }
    while( fgets(arr1,MAX_LEN,fptr1) != NULL && fgets(arr2,MAX_LEN,fptr2) != NULL){
        fputs(arr1, fptr3);
        fputs(arr2, fptr3);
    }
    if((c1 = fgetc(fptr1) == EOF)){
        do{
            fputs(arr2, fptr3);
        }
        while(fgets(arr2,MAX_LEN,fptr2) != NULL);
    }else if((c2 = fgetc(fptr2) == EOF)){
        do{
            fputs(arr1, fptr3);
        }
        while(fgets(arr1,MAX_LEN,fptr2) != NULL);
    };
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return reval;
}