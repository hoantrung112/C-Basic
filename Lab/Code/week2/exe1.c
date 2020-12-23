#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS, FAIL, MAX_LEN = 500, MAX_LINE = 100};

int main(int argc, char* argv[]){
    FILE *read;
    FILE *write;
    int c, i = 0, count = 0;
    char arr[MAX_LEN];
    char letters[MAX_LINE];
    int reval = SUCCESS;
    if(argc != 2){
        printf("Syntax Error!\n");
        reval = FAIL;
    };
    if((read = fopen(argv[1],"r")) == NULL){
        printf("CAN'T OPEN FILE.");
        reval = FAIL;
    }else if((write = fopen("tempt.txt","w")) == NULL){
        printf("CAN'T OPEN FILE.");
        reval = FAIL;
    }
    while((c = fgetc(read)) != EOF){
        letters[i] = c;
        i++;
        fseek(read, -1, SEEK_CUR);
        fgets(arr, MAX_LEN, read);
        fputs(arr, write);
        count ++;
    };
    fclose(read);
    fclose(write);
    read = fopen("tempt.txt","r");
    write = fopen(argv[1],"r+");
    
    while((fgets(arr, MAX_LEN, read)) != NULL){
        fputs(arr, write);
    }
    fputs("\n", write);
    fwrite(letters,sizeof(char),count,write);
    fclose(read);
    fclose(write);
    remove("tempt.txt");
  
    return reval;
}